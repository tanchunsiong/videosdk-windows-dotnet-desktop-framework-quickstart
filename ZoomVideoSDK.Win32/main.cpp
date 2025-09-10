// main.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "main.h"
#include "ZoomSDKManager.h"
#include <commctrl.h>
#include <string>
#include <vector>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance

// Application state
bool g_bInSession = false;
bool g_bMicMuted = false;
bool g_bVideoStarted = false;

// SDK Manager
ZoomSDKManager* g_pSDKManager = nullptr;

// Callback functions for SDK events
void OnSessionStatusChanged(const SessionStatusEventArgs& args) {
    // This will be called from SDK manager - need to update UI
    // For now, we'll handle this in the button handlers
}

void OnVideoFrameReceived(const VideoFrameEventArgs& args) {
    // Handle video frame display
    // TODO: Implement video rendering
}

// Forward declarations of functions included in this code module:
INT_PTR CALLBACK    MainDialogProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                UpdateStatus(HWND hDlg, const std::string& message);
void                UpdateButtonStates(HWND hDlg);
void                PopulateDeviceLists(HWND hDlg);
void                InitializeZoomSDK();
void                OnDeviceSelectionChanged(HWND hDlg, int controlId);
void                ApplyDeviceSelections(HWND hDlg);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize common controls
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&icex);

    hInst = hInstance; // Store instance handle

    // Create and show the main dialog
    INT_PTR result = DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN), nullptr, MainDialogProc);

    return (int)result;
}

// Main dialog procedure
INT_PTR CALLBACK MainDialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (message)
    {
    case WM_INITDIALOG:
        {
            // Initialize the dialog
            UpdateStatus(hDlg, "Initializing...");
            UpdateButtonStates(hDlg);
            
            // Initialize SDK first, then populate device lists
            InitializeZoomSDK();
            PopulateDeviceLists(hDlg);

            // Set default values
            SetDlgItemText(hDlg, IDC_SESSION_NAME, L"TestSession");
            SetDlgItemText(hDlg, IDC_USER_NAME, L"TestUser");
            SetDlgItemText(hDlg, IDC_TOKEN, L"your_jwt_token_here");

            UpdateStatus(hDlg, "Ready");
            return (INT_PTR)TRUE;
        }

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

            switch (wmId)
            {
            case IDC_JOIN_SESSION:
                {
                    // Get session details
                    WCHAR sessionName[256] = {0};
                    WCHAR token[1024] = {0};
                    WCHAR userName[256] = {0};
                    WCHAR password[256] = {0};

                    GetDlgItemText(hDlg, IDC_SESSION_NAME, sessionName, 256);
                    GetDlgItemText(hDlg, IDC_TOKEN, token, 1024);
                    GetDlgItemText(hDlg, IDC_USER_NAME, userName, 256);
                    GetDlgItemText(hDlg, IDC_PASSWORD, password, 256);

                    if (wcslen(sessionName) == 0 || wcslen(token) == 0 || wcslen(userName) == 0)
                    {
                        MessageBox(hDlg, L"Please fill in Session Name, Token, and User Name", L"Missing Information", MB_OK | MB_ICONWARNING);
                        return (INT_PTR)TRUE;
                    }

                    UpdateStatus(hDlg, "Applying device selections...");

                    // Apply device selections before joining session
                    ApplyDeviceSelections(hDlg);

                    UpdateStatus(hDlg, "Joining session...");

                    // Convert wide strings to narrow strings for SDK
                    std::string strSessionName = std::string(sessionName, sessionName + wcslen(sessionName));
                    std::string strToken = std::string(token, token + wcslen(token));
                    std::string strUserName = std::string(userName, userName + wcslen(userName));
                    std::string strPassword = std::string(password, password + wcslen(password));

                    // Call SDK manager to join session
                    if (g_pSDKManager && g_pSDKManager->JoinSession(strSessionName, strToken, strUserName, strPassword)) {
                        g_bInSession = true;
                        UpdateButtonStates(hDlg);
                        UpdateStatus(hDlg, "Successfully joined session");
                    } else {
                        UpdateStatus(hDlg, "Failed to join session");
                        MessageBox(hDlg, L"Failed to join session. Please check your credentials.", L"Join Failed", MB_OK | MB_ICONERROR);
                    }
                }
                break;

            case IDC_LEAVE_SESSION:
                {
                    UpdateStatus(hDlg, "Leaving session...");

                    // Call SDK manager to leave session
                    if (g_pSDKManager && g_pSDKManager->LeaveSession()) {
                        g_bInSession = false;
                        g_bVideoStarted = false;
                        UpdateButtonStates(hDlg);
                        UpdateStatus(hDlg, "Left session");
                    } else {
                        UpdateStatus(hDlg, "Failed to leave session");
                    }
                }
                break;

            case IDC_MUTE_MIC:
                {
                    // Check current audio mute status before toggling
                    bool isCurrentlyMuted = g_pSDKManager ? g_pSDKManager->IsAudioMuted() : false;
                    bool newMuteState = !isCurrentlyMuted;

                    // Call SDK manager to mute/unmute audio
                    if (g_pSDKManager && g_pSDKManager->MuteAudio(newMuteState)) {
                        g_bMicMuted = newMuteState;
                        UpdateButtonStates(hDlg);
                        UpdateStatus(hDlg, g_bMicMuted ? "Microphone muted" : "Microphone unmuted");
                    } else {
                        UpdateStatus(hDlg, "Failed to change microphone state");
                    }
                }
                break;


            case IDC_START_VIDEO:
                {
                    UpdateStatus(hDlg, "Starting video...");

                    // Call SDK manager to start video
                    if (g_pSDKManager && g_pSDKManager->StartVideo()) {
                        g_bVideoStarted = true;
                        UpdateButtonStates(hDlg);
                        
                        // Start video preview for self video
                        HWND selfVideoHwnd = GetDlgItem(hDlg, IDC_SELF_VIDEO);
                        if (selfVideoHwnd && g_pSDKManager->StartVideoPreview(selfVideoHwnd)) {
                            UpdateStatus(hDlg, "Video started with preview");
                        } else {
                            UpdateStatus(hDlg, "Video started (preview failed)");
                        }
                        
                        // Try to subscribe to remote video if there are remote users
                        HWND remoteVideoHwnd = GetDlgItem(hDlg, IDC_REMOTE_VIDEO);
                        if (remoteVideoHwnd) {
                            g_pSDKManager->SubscribeRemoteVideo(remoteVideoHwnd, "");
                        }
                    } else {
                        UpdateStatus(hDlg, "Failed to start video");
                    }
                }
                break;

            case IDC_STOP_VIDEO:
                {
                    UpdateStatus(hDlg, "Stopping video...");

                    // Stop video preview first
                    HWND selfVideoHwnd = GetDlgItem(hDlg, IDC_SELF_VIDEO);
                    if (selfVideoHwnd) {
                        g_pSDKManager->StopVideoPreview(selfVideoHwnd);
                    }
                    
                    // Unsubscribe from remote video
                    HWND remoteVideoHwnd = GetDlgItem(hDlg, IDC_REMOTE_VIDEO);
                    if (remoteVideoHwnd) {
                        g_pSDKManager->UnsubscribeRemoteVideo(remoteVideoHwnd);
                    }

                    // Call SDK manager to stop video
                    if (g_pSDKManager && g_pSDKManager->StopVideo()) {
                        g_bVideoStarted = false;
                        UpdateButtonStates(hDlg);
                        UpdateStatus(hDlg, "Video stopped");
                    } else {
                        UpdateStatus(hDlg, "Failed to stop video");
                    }
                }
                break;

            case IDC_PREVIEW_TOKEN:
                {
                    WCHAR token[1024] = {0};
                    GetDlgItemText(hDlg, IDC_TOKEN, token, 1024);

                    if (wcslen(token) == 0)
                    {
                        MessageBox(hDlg, L"Please enter a JWT token first", L"No Token", MB_OK | MB_ICONWARNING);
                        return (INT_PTR)TRUE;
                    }

                    // Simple token preview (basic check)
                    std::string status = "Token: ";
                    status += (wcslen(token) > 10) ? "[Valid format]" : "[Check format]";
                    UpdateStatus(hDlg, status);
                }
                break;

            case IDOK:
            case IDCANCEL:
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }

            // Handle combobox selection changes
            if (HIWORD(wParam) == CBN_SELCHANGE) {
                switch (LOWORD(wParam)) {
                    case IDC_MICROPHONE:
                    case IDC_SPEAKER:
                    case IDC_CAMERA:
                        OnDeviceSelectionChanged(hDlg, LOWORD(wParam));
                        break;
                }
            }
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hDlg, &ps);
            // TODO: Add custom painting if needed
            EndPaint(hDlg, &ps);
        }
        break;
    }

    return (INT_PTR)FALSE;
}

// Helper functions
void UpdateStatus(HWND hDlg, const std::string& message)
{
    SetDlgItemTextA(hDlg, IDC_STATUS, message.c_str());
}

void UpdateButtonStates(HWND hDlg)
{
    // Session buttons
    EnableWindow(GetDlgItem(hDlg, IDC_JOIN_SESSION), !g_bInSession);
    EnableWindow(GetDlgItem(hDlg, IDC_LEAVE_SESSION), g_bInSession);

    // Control buttons
    EnableWindow(GetDlgItem(hDlg, IDC_MUTE_MIC), g_bInSession);
    EnableWindow(GetDlgItem(hDlg, IDC_START_VIDEO), g_bInSession && !g_bVideoStarted);
    EnableWindow(GetDlgItem(hDlg, IDC_STOP_VIDEO), g_bInSession && g_bVideoStarted);

    // Update button text
    SetDlgItemText(hDlg, IDC_MUTE_MIC, g_bMicMuted ? L"Unmute Mic" : L"Mute Mic");
}

void PopulateDeviceLists(HWND hDlg)
{
    // Clear existing items
    SendMessage(GetDlgItem(hDlg, IDC_MICROPHONE), CB_RESETCONTENT, 0, 0);
    SendMessage(GetDlgItem(hDlg, IDC_SPEAKER), CB_RESETCONTENT, 0, 0);
    SendMessage(GetDlgItem(hDlg, IDC_CAMERA), CB_RESETCONTENT, 0, 0);

    if (g_pSDKManager && g_pSDKManager->IsInitialized()) {
        // Get real device lists from SDK
        auto microphones = g_pSDKManager->GetMicrophoneList();
        auto speakers = g_pSDKManager->GetSpeakerList();
        auto cameras = g_pSDKManager->GetCameraList();

        // Populate microphones
        for (const auto& mic : microphones) {
            SendMessageA(GetDlgItem(hDlg, IDC_MICROPHONE), CB_ADDSTRING, 0, (LPARAM)mic.c_str());
        }

        // Populate speakers
        for (const auto& speaker : speakers) {
            SendMessageA(GetDlgItem(hDlg, IDC_SPEAKER), CB_ADDSTRING, 0, (LPARAM)speaker.c_str());
        }

        // Populate cameras
        for (const auto& camera : cameras) {
            SendMessageA(GetDlgItem(hDlg, IDC_CAMERA), CB_ADDSTRING, 0, (LPARAM)camera.c_str());
        }

        UpdateStatus(hDlg, "Device lists populated from SDK");
    } else {
        // Fallback to default devices if SDK not initialized
        SendMessageA(GetDlgItem(hDlg, IDC_MICROPHONE), CB_ADDSTRING, 0, (LPARAM)"Default Microphone");
        SendMessageA(GetDlgItem(hDlg, IDC_SPEAKER), CB_ADDSTRING, 0, (LPARAM)"Default Speaker");
        SendMessageA(GetDlgItem(hDlg, IDC_CAMERA), CB_ADDSTRING, 0, (LPARAM)"Default Camera");
        UpdateStatus(hDlg, "Using default devices (SDK not ready)");
    }

    // Select first item in each list
    if (SendMessage(GetDlgItem(hDlg, IDC_MICROPHONE), CB_GETCOUNT, 0, 0) > 0) {
        SendMessage(GetDlgItem(hDlg, IDC_MICROPHONE), CB_SETCURSEL, 0, 0);
    }
    if (SendMessage(GetDlgItem(hDlg, IDC_SPEAKER), CB_GETCOUNT, 0, 0) > 0) {
        SendMessage(GetDlgItem(hDlg, IDC_SPEAKER), CB_SETCURSEL, 0, 0);
    }
    if (SendMessage(GetDlgItem(hDlg, IDC_CAMERA), CB_GETCOUNT, 0, 0) > 0) {
        SendMessage(GetDlgItem(hDlg, IDC_CAMERA), CB_SETCURSEL, 0, 0);
    }
}

void InitializeZoomSDK()
{
    // Initialize SDK manager
    if (!g_pSDKManager) {
        g_pSDKManager = new ZoomSDKManager();

        // Set up callbacks
        g_pSDKManager->SetSessionStatusCallback(OnSessionStatusChanged);
        g_pSDKManager->SetRemoteVideoCallback(OnVideoFrameReceived);
        g_pSDKManager->SetPreviewVideoCallback(OnVideoFrameReceived);

        // Initialize the SDK
        if (g_pSDKManager->Initialize()) {
            // Give SDK a moment to fully initialize before querying devices
            Sleep(100);
        }
    }
}

void OnDeviceSelectionChanged(HWND hDlg, int controlId)
{
    if (!g_pSDKManager || !g_pSDKManager->IsInitialized()) {
        return;
    }

    // Get the selected index
    int selectedIndex = (int)SendMessage(GetDlgItem(hDlg, controlId), CB_GETCURSEL, 0, 0);
    if (selectedIndex == CB_ERR) {
        return;
    }

    // Get the selected device name
    char deviceName[256] = {0};
    SendMessageA(GetDlgItem(hDlg, controlId), CB_GETLBTEXT, selectedIndex, (LPARAM)deviceName);

    // Apply the device selection
    bool success = false;
    std::string statusMessage;

    switch (controlId) {
        case IDC_MICROPHONE:
            success = g_pSDKManager->SelectMicrophoneByName(std::string(deviceName));
            statusMessage = success ? "Microphone selected: " + std::string(deviceName) : "Failed to select microphone";
            break;

        case IDC_SPEAKER:
            success = g_pSDKManager->SelectSpeakerByName(std::string(deviceName));
            statusMessage = success ? "Speaker selected: " + std::string(deviceName) : "Failed to select speaker";
            break;

        case IDC_CAMERA:
            success = g_pSDKManager->SelectCameraByName(std::string(deviceName));
            statusMessage = success ? "Camera selected: " + std::string(deviceName) : "Failed to select camera";
            break;
    }

    UpdateStatus(hDlg, statusMessage);
}

void ApplyDeviceSelections(HWND hDlg)
{
    if (!g_pSDKManager || !g_pSDKManager->IsInitialized()) {
        UpdateStatus(hDlg, "SDK not initialized for device selection");
        return;
    }

    // Apply microphone selection
    int micIndex = (int)SendMessage(GetDlgItem(hDlg, IDC_MICROPHONE), CB_GETCURSEL, 0, 0);
    if (micIndex != CB_ERR) {
        char micName[256] = {0};
        SendMessageA(GetDlgItem(hDlg, IDC_MICROPHONE), CB_GETLBTEXT, micIndex, (LPARAM)micName);
        g_pSDKManager->SelectMicrophoneByName(std::string(micName));
    }

    // Apply speaker selection
    int speakerIndex = (int)SendMessage(GetDlgItem(hDlg, IDC_SPEAKER), CB_GETCURSEL, 0, 0);
    if (speakerIndex != CB_ERR) {
        char speakerName[256] = {0};
        SendMessageA(GetDlgItem(hDlg, IDC_SPEAKER), CB_GETLBTEXT, speakerIndex, (LPARAM)speakerName);
        g_pSDKManager->SelectSpeakerByName(std::string(speakerName));
    }

    // Apply camera selection
    int cameraIndex = (int)SendMessage(GetDlgItem(hDlg, IDC_CAMERA), CB_GETCURSEL, 0, 0);
    if (cameraIndex != CB_ERR) {
        char cameraName[256] = {0};
        SendMessageA(GetDlgItem(hDlg, IDC_CAMERA), CB_GETLBTEXT, cameraIndex, (LPARAM)cameraName);
        g_pSDKManager->SelectCameraByName(std::string(cameraName));
    }

    UpdateStatus(hDlg, "Device selections applied");
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
