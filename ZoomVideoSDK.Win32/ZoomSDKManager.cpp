// ZoomSDKManager.cpp : Native C++ implementation for Zoom Video SDK
#include "stdafx.h"
#include "ZoomSDKManager.h"
#include "zoom_video_sdk_api.h"

// Use the Zoom SDK namespace for convenience
using namespace ZOOMVIDEOSDK;

// CustomZoomDelegate implementation
CustomZoomDelegate::CustomZoomDelegate(ZoomSDKManager* manager) : m_pManager(manager) {
}

CustomZoomDelegate::~CustomZoomDelegate() {
}

// Core session callbacks
void CustomZoomDelegate::onSessionJoin() {
    if (m_pManager) {
        m_pManager->OnSessionStatusChanged(SessionStatus::InSession, "Session joined successfully");
    }
}

void CustomZoomDelegate::onSessionLeave() {
    if (m_pManager) {
        m_pManager->OnSessionStatusChanged(SessionStatus::Idle, "Session left");
    }
}

void CustomZoomDelegate::onSessionLeave(ZOOMVIDEOSDK::ZoomVideoSDKSessionLeaveReason eReason) {
    if (m_pManager) {
        std::string reason = "Session left with reason: " + std::to_string((int)eReason);
        m_pManager->OnSessionStatusChanged(SessionStatus::Idle, reason);
    }
}

void CustomZoomDelegate::onError(ZOOMVIDEOSDK::ZoomVideoSDKErrors errorCode, int detailErrorCode) {
    if (m_pManager) {
        std::string errorMsg = "SDK Error: " + std::to_string((int)errorCode) +
                             " (Detail: " + std::to_string(detailErrorCode) + ")";
        m_pManager->OnSessionStatusChanged(SessionStatus::Error, errorMsg);
    }
}

// User management callbacks - basic implementations
void CustomZoomDelegate::onUserJoin(ZOOMVIDEOSDK::IZoomVideoSDKUserHelper* pUserHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) {
    // Handle user join events
}

void CustomZoomDelegate::onUserLeave(ZOOMVIDEOSDK::IZoomVideoSDKUserHelper* pUserHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) {
    // Handle user leave events
}

void CustomZoomDelegate::onUserVideoStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKVideoHelper* pVideoHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) {
    // Handle video status changes
}

void CustomZoomDelegate::onUserAudioStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKAudioHelper* pAudioHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) {
    // Handle audio status changes
}

void CustomZoomDelegate::onUserHostChanged(ZOOMVIDEOSDK::IZoomVideoSDKUserHelper* pUserHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle host changes
}

void CustomZoomDelegate::onUserActiveAudioChanged(ZOOMVIDEOSDK::IZoomVideoSDKAudioHelper* pAudioHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* list) {
    // Handle active audio changes
}

void CustomZoomDelegate::onUserManagerChanged(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle user manager changes
}

void CustomZoomDelegate::onUserNameChanged(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle user name changes
}

void CustomZoomDelegate::onUserRecordingConsent(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle user recording consent
}

// Share callbacks - basic implementations
void CustomZoomDelegate::onUserShareStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) {
    // Handle share status changes
}

void CustomZoomDelegate::onShareContentChanged(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) {
    // Handle share content changes
}

void CustomZoomDelegate::onFailedToStartShare(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle failed share start
}

void CustomZoomDelegate::onShareSettingChanged(ZOOMVIDEOSDK::ZoomVideoSDKShareSetting setting) {
    // Handle share setting changes
}

void CustomZoomDelegate::onShareContentSizeChanged(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) {
    // Handle share content size changes
}

// Live stream callbacks
void CustomZoomDelegate::onLiveStreamStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper, ZOOMVIDEOSDK::ZoomVideoSDKLiveStreamStatus status) {
    // Handle live stream status changes
}

// Chat callbacks
void CustomZoomDelegate::onChatNewMessageNotify(ZOOMVIDEOSDK::IZoomVideoSDKChatHelper* pChatHelper, ZOOMVIDEOSDK::IZoomVideoSDKChatMessage* messageItem) {
    // Handle new chat messages
}

void CustomZoomDelegate::onChatMsgDeleteNotification(ZOOMVIDEOSDK::IZoomVideoSDKChatHelper* pChatHelper, const zchar_t* msgID, ZOOMVIDEOSDK::ZoomVideoSDKChatMessageDeleteType deleteBy) {
    // Handle chat message deletion
}

void CustomZoomDelegate::onChatPrivilegeChanged(ZOOMVIDEOSDK::IZoomVideoSDKChatHelper* pChatHelper, ZOOMVIDEOSDK::ZoomVideoSDKChatPrivilegeType privilege) {
    // Handle chat privilege changes
}

// Password callbacks
void CustomZoomDelegate::onSessionNeedPassword(ZOOMVIDEOSDK::IZoomVideoSDKPasswordHandler* handler) {
    // Handle session password requirement
}

void CustomZoomDelegate::onSessionPasswordWrong(ZOOMVIDEOSDK::IZoomVideoSDKPasswordHandler* handler) {
    // Handle wrong session password
}

// Audio raw data callbacks
void CustomZoomDelegate::onMixedAudioRawDataReceived(AudioRawData* data_) {
    // Handle mixed audio raw data
}

void CustomZoomDelegate::onOneWayAudioRawDataReceived(AudioRawData* data_, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle one-way audio raw data
}

void CustomZoomDelegate::onSharedAudioRawDataReceived(AudioRawData* data_) {
    // Handle shared audio raw data
}

// Command channel callbacks
void CustomZoomDelegate::onCommandReceived(ZOOMVIDEOSDK::IZoomVideoSDKUser* sender, const zchar_t* strCmd) {
    // Handle command channel messages
}

void CustomZoomDelegate::onCommandChannelConnectResult(bool isSuccess) {
    // Handle command channel connection result
}

// Phone callbacks
void CustomZoomDelegate::onInviteByPhoneStatus(ZOOMVIDEOSDK::PhoneStatus status, ZOOMVIDEOSDK::PhoneFailedReason reason) {
    // Handle invite by phone status
}

void CustomZoomDelegate::onCalloutJoinSuccess(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, const zchar_t* phoneNumber) {
    // Handle callout join success
}

// Recording callbacks
void CustomZoomDelegate::onCloudRecordingStatus(ZOOMVIDEOSDK::RecordingStatus status, ZOOMVIDEOSDK::IZoomVideoSDKRecordingConsentHandler* pHandler) {
    // Handle cloud recording status changes
}

void CustomZoomDelegate::onHostAskUnmute() {
    // Handle host ask unmute
}

// Multi-camera callbacks
void CustomZoomDelegate::onMultiCameraStreamStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKMultiCameraStreamStatus status, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKRawDataPipe* pVideoPipe) {
    // Handle multi-camera stream status changes
}

// Volume and device callbacks
void CustomZoomDelegate::onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume) {
    // Handle mic/speaker volume changes
}

void CustomZoomDelegate::onAudioDeviceStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKAudioDeviceType type, ZOOMVIDEOSDK::ZoomVideoSDKAudioDeviceStatus status) {
    // Handle audio device status changes
}

void CustomZoomDelegate::onTestMicStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDK_TESTMIC_STATUS status) {
    // Handle test mic status changes
}

void CustomZoomDelegate::onSelectedAudioDeviceChanged() {
    // Handle selected audio device changes
}

void CustomZoomDelegate::onCameraListChanged() {
    // Handle camera list changes
}

// Camera control callbacks
void CustomZoomDelegate::onCameraControlRequestResult(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, bool isApproved) {
    // Handle camera control request result
}

void CustomZoomDelegate::onCameraControlRequestReceived(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::ZoomVideoSDKCameraControlRequestType requestType, ZOOMVIDEOSDK::IZoomVideoSDKCameraControlRequestHandler* pCameraControlRequestHandler) {
    // Handle camera control request received
}

#if defined(WIN32) || defined(__MACOS__)
// Remote control callbacks (Windows/Mac only)
void CustomZoomDelegate::onRemoteControlStatus(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction, ZOOMVIDEOSDK::ZoomVideoSDKRemoteControlStatus status) {
    // Handle remote control status
}

void CustomZoomDelegate::onRemoteControlRequestReceived(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction, ZOOMVIDEOSDK::IZoomVideoSDKRemoteControlRequestHandler* pRemoteControlRequestHandler) {
    // Handle remote control request received
}
#endif

#if defined(WIN32)
// Windows-specific callbacks
void CustomZoomDelegate::onRemoteControlServiceInstallResult(bool bSuccess) {
    // Handle remote control service install result
}
#endif

// Live transcription callbacks
void CustomZoomDelegate::onLiveTranscriptionStatus(ZOOMVIDEOSDK::ZoomVideoSDKLiveTranscriptionStatus status) {
    // Handle live transcription status
}

void CustomZoomDelegate::onOriginalLanguageMsgReceived(ZOOMVIDEOSDK::ILiveTranscriptionMessageInfo* messageInfo) {
    // Handle original language message received
}

void CustomZoomDelegate::onLiveTranscriptionMsgInfoReceived(ZOOMVIDEOSDK::ILiveTranscriptionMessageInfo* messageInfo) {
    // Handle live transcription message info received
}

void CustomZoomDelegate::onLiveTranscriptionMsgError(ZOOMVIDEOSDK::ILiveTranscriptionLanguage* spokenLanguage, ZOOMVIDEOSDK::ILiveTranscriptionLanguage* transcriptLanguage) {
    // Handle live transcription message error
}

void CustomZoomDelegate::onSpokenLanguageChanged(ZOOMVIDEOSDK::ILiveTranscriptionLanguage* spokenLanguage) {
    // Handle spoken language changed
}

// File transfer callbacks
void CustomZoomDelegate::onSendFileStatus(ZOOMVIDEOSDK::IZoomVideoSDKSendFile* file, const ZOOMVIDEOSDK::FileTransferStatus& status) {
    // Handle send file status
}

void CustomZoomDelegate::onReceiveFileStatus(ZOOMVIDEOSDK::IZoomVideoSDKReceiveFile* file, const ZOOMVIDEOSDK::FileTransferStatus& status) {
    // Handle receive file status
}

// Network callbacks
void CustomZoomDelegate::onProxyDetectComplete() {
    // Handle proxy detect complete
}

void CustomZoomDelegate::onProxySettingNotification(ZOOMVIDEOSDK::IZoomVideoSDKProxySettingHandler* handler) {
    // Handle proxy setting notification
}

void CustomZoomDelegate::onSSLCertVerifiedFailNotification(ZOOMVIDEOSDK::IZoomVideoSDKSSLCertificateInfo* info) {
    // Handle SSL cert verified fail notification
}

void CustomZoomDelegate::onUserVideoNetworkStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKNetworkStatus status, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) {
    // Handle user video network status changed
}

void CustomZoomDelegate::onShareNetworkStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKNetworkStatus shareNetworkStatus, bool isSendingShare) {
    // Handle share network status changed
}

// CRC callbacks
void CustomZoomDelegate::onCallCRCDeviceStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKCRCCallStatus status) {
    // Handle call CRC device status changed
}

#if !defined __linux
// Non-Linux callbacks
void CustomZoomDelegate::onVideoCanvasSubscribeFail(ZOOMVIDEOSDK::ZoomVideoSDKSubscribeFailReason fail_reason, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, void* handle) {
    // Handle video canvas subscribe fail
}

void CustomZoomDelegate::onShareCanvasSubscribeFail(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, void* handle, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) {
    // Handle share canvas subscribe fail
}
#endif

// Annotation callbacks
void CustomZoomDelegate::onAnnotationHelperCleanUp(ZOOMVIDEOSDK::IZoomVideoSDKAnnotationHelper* helper) {
    // Handle annotation helper clean up
}

void CustomZoomDelegate::onAnnotationPrivilegeChange(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) {
    // Handle annotation privilege change
}

void CustomZoomDelegate::onAnnotationHelperActived(void* handle) {
    // Handle annotation helper actived
}

// Video callbacks
void CustomZoomDelegate::onVideoAlphaChannelStatusChanged(bool isAlphaModeOn) {
    // Handle video alpha channel status changed
}

void CustomZoomDelegate::onSpotlightVideoChanged(ZOOMVIDEOSDK::IZoomVideoSDKVideoHelper* pVideoHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) {
    // Handle spotlight video changed
}

// Live stream callbacks
void CustomZoomDelegate::onBindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) {
    // Handle bind incoming live stream response
}

void CustomZoomDelegate::onUnbindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) {
    // Handle unbind incoming live stream response
}

void CustomZoomDelegate::onIncomingLiveStreamStatusResponse(bool bSuccess, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IncomingLiveStreamStatus>* pStreamsStatusList) {
    // Handle incoming live stream status response
}

void CustomZoomDelegate::onStartIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) {
    // Handle start incoming live stream response
}

void CustomZoomDelegate::onStopIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) {
    // Handle stop incoming live stream response
}

// Subsession callbacks
void CustomZoomDelegate::onSubSessionStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKSubSessionStatus status, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::ISubSessionKit*>* pSubSessionKitList) {
    // Handle subsession status changed
}

void CustomZoomDelegate::onSubSessionManagerHandle(ZOOMVIDEOSDK::IZoomVideoSDKSubSessionManager* pManager) {
    // Handle subsession manager handle
}

void CustomZoomDelegate::onSubSessionParticipantHandle(ZOOMVIDEOSDK::IZoomVideoSDKSubSessionParticipant* pParticipant) {
    // Handle subsession participant handle
}

void CustomZoomDelegate::onSubSessionUsersUpdate(ZOOMVIDEOSDK::ISubSessionKit* pSubSessionKit) {
    // Handle subsession users update
}

void CustomZoomDelegate::onBroadcastMessageFromMainSession(const zchar_t* sMessage, const zchar_t* sUserName) {
    // Handle broadcast message from main session
}

void CustomZoomDelegate::onSubSessionUserHelpRequest(ZOOMVIDEOSDK::ISubSessionUserHelpRequestHandler* pHandler) {
    // Handle subsession user help request
}

void CustomZoomDelegate::onSubSessionUserHelpRequestResult(ZOOMVIDEOSDK::ZoomVideoSDKUserHelpRequestResult eResult) {
    // Handle subsession user help request result
}

// Constructor
ZoomSDKManager::ZoomSDKManager()
    : m_pZoomSDK(nullptr)
    , m_pSession(nullptr)
    , m_pDelegate(nullptr)
    , m_bInitialized(false)
    , m_bInSession(false)
    , m_bVideoStarted(false)
{
}

// Destructor
ZoomSDKManager::~ZoomSDKManager()
{
    Cleanup();
}

// Initialize the SDK
bool ZoomSDKManager::Initialize()
{
    try {
        // Create SDK instance using actual SDK function
        m_pZoomSDK = CreateZoomVideoSDKObj();
        if (!m_pZoomSDK) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to create Zoom SDK instance");
            return false;
        }

        // Create delegate for SDK callbacks
        m_pDelegate = new CustomZoomDelegate(this);
        if (!m_pDelegate) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to create SDK delegate");
            return false;
        }

        // Initialize SDK with actual parameters
        ZoomVideoSDKInitParams initParams;
        initParams.domain = L"https://zoom.us";
        initParams.logFilePrefix = L"ZoomVideoSDK_Win32";
        initParams.enableLog = true;

        // Initialize SDK
        ZoomVideoSDKErrors ret = m_pZoomSDK->initialize(initParams);
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "SDK initialization failed: " + std::to_string((int)ret));
            return false;
        }

        // Register the delegate to receive SDK callbacks
        m_pZoomSDK->addListener(static_cast<IZoomVideoSDKDelegate*>(m_pDelegate));

        m_bInitialized = true;
        OnSessionStatusChanged(SessionStatus::Idle, "Zoom SDK initialized successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during SDK initialization: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during SDK initialization");
        return false;
    }
}

// Cleanup the SDK
void ZoomSDKManager::Cleanup()
{
    if (m_pZoomSDK) {
        // Leave session if in one
        if (m_bInSession) {
            m_pZoomSDK->leaveSession(false);
        }

        // Remove listener
        if (m_pDelegate) {
            m_pZoomSDK->removeListener(static_cast<IZoomVideoSDKDelegate*>(m_pDelegate));
        }

        // Cleanup SDK
        m_pZoomSDK->cleanup();

        // Destroy SDK instance
        DestroyZoomVideoSDKObj();
        m_pZoomSDK = nullptr;
    }

    // Clean up delegate
    if (m_pDelegate) {
        delete m_pDelegate;  // Direct delete since we know the type
        m_pDelegate = nullptr;
    }

    m_bInitialized = false;
    m_bInSession = false;
    m_bVideoStarted = false;
}

// Join session
bool ZoomSDKManager::JoinSession(const std::string& sessionName, const std::string& token,
                                const std::string& userName, const std::string& password)
{
    if (!m_bInitialized) {
        OnSessionStatusChanged(SessionStatus::Error, "SDK not initialized");
        return false;
    }

    if (!m_pZoomSDK) {
        OnSessionStatusChanged(SessionStatus::Error, "SDK instance not available");
        return false;
    }

    try {
        // Convert strings to wide strings for SDK
        std::wstring wSessionName(sessionName.begin(), sessionName.end());
        std::wstring wToken(token.begin(), token.end());
        std::wstring wUserName(userName.begin(), userName.end());
        std::wstring wPassword(password.begin(), password.end());

        // Create session context with actual SDK structures
        ZoomVideoSDKSessionContext sessionContext;
        sessionContext.sessionName = wSessionName.c_str();
        sessionContext.userName = wUserName.c_str();
        sessionContext.token = wToken.c_str();
        sessionContext.sessionPassword = wPassword.empty() ? nullptr : wPassword.c_str();

        // Configure session options
        sessionContext.videoOption.localVideoOn = true;
        sessionContext.audioOption.connect = true;
        sessionContext.audioOption.mute = false;

        OnSessionStatusChanged(SessionStatus::Joining, "Joining session...");

        // Join session using actual SDK call
        IZoomVideoSDKSession* session = m_pZoomSDK->joinSession(sessionContext);
        if (!session) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to join session");
            return false;
        }

        m_pSession = session;
        m_bInSession = true;
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during session join: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during session join");
        return false;
    }
}

// Leave session
bool ZoomSDKManager::LeaveSession()
{
    if (!m_bInitialized) {
        return false;
    }

    if (!m_pZoomSDK) {
        return false;
    }

    try {
        OnSessionStatusChanged(SessionStatus::Leaving, "Leaving session...");

        // Leave session using actual SDK call
        ZoomVideoSDKErrors ret = m_pZoomSDK->leaveSession(false);
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to leave session: " + std::to_string((int)ret));
            return false;
        }

        m_bInSession = false;
        m_bVideoStarted = false;
        OnSessionStatusChanged(SessionStatus::Idle, "Left session successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during session leave: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during session leave");
        return false;
    }
}

    // Audio controls
    bool ZoomSDKManager::MuteAudio(bool desiredMuteState)
    {
        if (!m_bInitialized) {
            OnSessionStatusChanged(SessionStatus::Error, "SDK not initialized for audio control");
            return false;
        }

        if (!m_pZoomSDK) {
            OnSessionStatusChanged(SessionStatus::Error, "SDK instance not available for audio control");
            return false;
        }

        if (!m_bInSession) {
            OnSessionStatusChanged(SessionStatus::Error, "Not in session - cannot change microphone state");
            return false;
        }

        try {
            // Get current user (myself)
            IZoomVideoSDKSession* session = m_pZoomSDK->getSessionInfo();
            if (!session) {
                OnSessionStatusChanged(SessionStatus::Error, "Failed to get session info");
                return false;
            }

            IZoomVideoSDKUser* currentUser = session->getMyself();
            if (!currentUser) {
                OnSessionStatusChanged(SessionStatus::Error, "No current user available for audio control");
                return false;
            }

            // Check current audio status first
            bool currentMuted = IsAudioMuted();

            // If already in desired state, return success (no-op)
            if (currentMuted == desiredMuteState) {
                return true;
            }

            // Get audio helper
            IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
            if (!audioHelper) {
                OnSessionStatusChanged(SessionStatus::Error, "Failed to get audio helper");
                return false;
            }

            // Need to change state - call appropriate SDK method with current user object
            ZoomVideoSDKErrors ret;
            if (desiredMuteState) {
                // Want to mute - call muteAudio with current user
                ret = audioHelper->muteAudio(currentUser);
            } else {
                // Want to unmute - call unmuteAudio with current user
                ret = audioHelper->unMuteAudio(currentUser);
            }

            if (ret != ZoomVideoSDKErrors_Success) {
                OnSessionStatusChanged(SessionStatus::Error, "Unable to change microphone state: " + std::to_string((int)ret));
                return false;
            }

            OnSessionStatusChanged(SessionStatus::InSession,
                std::string("Audio ") + (desiredMuteState ? "muted" : "unmuted") + " successfully");
            return true;
        }
        catch (const std::exception& e) {
            OnSessionStatusChanged(SessionStatus::Error, "Exception during audio control: " + std::string(e.what()));
            return false;
        }
        catch (...) {
            OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during audio control");
            return false;
        }
    }

bool ZoomSDKManager::IsAudioMuted()
{
    if (!m_bInitialized || !m_pZoomSDK || !m_bInSession) {
        return false;
    }

    try {
        // Get session info to access current user
        IZoomVideoSDKSession* session = m_pZoomSDK->getSessionInfo();
        if (!session) {
            return false;
        }

        // Get current user (myself)
        IZoomVideoSDKUser* currentUser = session->getMyself();
        if (!currentUser) {
            return false;
        }

        // Get audio status from user object
        ZoomVideoSDKAudioStatus audioStatus = currentUser->getAudioStatus();
        return audioStatus.isMuted;
    }
    catch (const std::exception& e) {
        // Handle exceptions gracefully
        return false;
    }
    catch (...) {
        // Handle unknown exceptions gracefully
        return false;
    }
}

// Video controls
bool ZoomSDKManager::StartVideo()
{
    if (!m_bInitialized) {
        return false;
    }

    if (!m_pZoomSDK) {
        return false;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get video helper");
            return false;
        }

        // Start video using actual SDK call
        ZoomVideoSDKErrors ret = videoHelper->startVideo();
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to start video: " + std::to_string((int)ret));
            return false;
        }

        m_bVideoStarted = true;
        OnSessionStatusChanged(SessionStatus::InSession, "Video started successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during video start: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during video start");
        return false;
    }
}

bool ZoomSDKManager::StopVideo()
{
    if (!m_bInitialized) {
        return false;
    }

    if (!m_pZoomSDK) {
        return false;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get video helper");
            return false;
        }

        // Stop video using actual SDK call
        ZoomVideoSDKErrors ret = videoHelper->stopVideo();
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to stop video: " + std::to_string((int)ret));
            return false;
        }

        m_bVideoStarted = false;
        OnSessionStatusChanged(SessionStatus::InSession, "Video stopped successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during video stop: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during video stop");
        return false;
    }
}

bool ZoomSDKManager::IsVideoStarted()
{
    if (!m_bInitialized || !m_pZoomSDK || !m_bInSession) {
        return false;
    }

    try {
        // Get session info to access current user
        IZoomVideoSDKSession* session = m_pZoomSDK->getSessionInfo();
        if (!session) {
            return false;
        }

        // Get current user (myself)
        IZoomVideoSDKUser* currentUser = session->getMyself();
        if (!currentUser) {
            return false;
        }

        // Get user's video pipe
        IZoomVideoSDKRawDataPipe* videoPipe = currentUser->GetVideoPipe();
        if (!videoPipe) {
            return false;
        }

        // Check video status
        ZoomVideoSDKVideoStatus videoStatus = videoPipe->getVideoStatus();
        return videoStatus.isOn;
    }
    catch (const std::exception& e) {
        // Handle exceptions gracefully
        return false;
    }
    catch (...) {
        // Handle unknown exceptions gracefully
        return false;
    }
}

// Video preview and rendering
bool ZoomSDKManager::StartVideoPreview(HWND hwnd)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        OnSessionStatusChanged(SessionStatus::Error, "SDK not initialized for video preview");
        return false;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get video helper for preview");
            return false;
        }

        // Start video canvas preview using actual SDK call
        ZoomVideoSDKErrors ret = videoHelper->startVideoCanvasPreview(hwnd);
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to start video preview: " + std::to_string((int)ret));
            return false;
        }

        OnSessionStatusChanged(SessionStatus::InSession, "Video preview started successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during video preview start: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during video preview start");
        return false;
    }
}

bool ZoomSDKManager::StopVideoPreview(HWND hwnd)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        return false;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            return false;
        }

        // Stop video canvas preview using actual SDK call
        ZoomVideoSDKErrors ret = videoHelper->stopVideoCanvasPreview(hwnd);
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to stop video preview: " + std::to_string((int)ret));
            return false;
        }

        OnSessionStatusChanged(SessionStatus::InSession, "Video preview stopped successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during video preview stop: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during video preview stop");
        return false;
    }
}

bool ZoomSDKManager::SubscribeRemoteVideo(HWND hwnd, const std::string& userId)
{
    if (!m_bInitialized || !m_pZoomSDK || !m_bInSession) {
        OnSessionStatusChanged(SessionStatus::Error, "Not in session for remote video subscription");
        return false;
    }

    try {
        // Get user helper to find the user
        IZoomVideoSDKUserHelper* userHelper = m_pZoomSDK->getUserHelper();
        if (!userHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get user helper for remote video");
            return false;
        }

        // Get session info to access user list
        IZoomVideoSDKSession* session = m_pZoomSDK->getSessionInfo();
        if (!session) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get session info for remote video");
            return false;
        }

        // Get remote users list
        IVideoSDKVector<IZoomVideoSDKUser*>* userList = session->getRemoteUsers();
        if (!userList || userList->GetCount() == 0) {
            OnSessionStatusChanged(SessionStatus::Error, "No remote users available for video subscription");
            return false;
        }

        // Find the first remote user (or specific user by ID if needed)
        IZoomVideoSDKUser* targetUser = nullptr;
        for (int i = 0; i < userList->GetCount(); i++) {
            IZoomVideoSDKUser* user = userList->GetItem(i);
            if (user) {
                // For now, subscribe to the first user with video
                // In a full implementation, you'd match by userId parameter
                targetUser = user;
                break;
            }
        }

        if (!targetUser) {
            OnSessionStatusChanged(SessionStatus::Error, "No suitable remote user found for video subscription");
            return false;
        }

        // Get the user's video canvas
        IZoomVideoSDKCanvas* videoCanvas = targetUser->GetVideoCanvas();
        if (!videoCanvas) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get video canvas for remote user");
            return false;
        }

        // Subscribe to the user's video with the window handle
        ZoomVideoSDKErrors ret = videoCanvas->subscribeWithView(hwnd, ZoomVideoSDKVideoAspect_Original, ZoomVideoSDKResolution_Auto);
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to subscribe to remote video: " + std::to_string((int)ret));
            return false;
        }

        OnSessionStatusChanged(SessionStatus::InSession, "Successfully subscribed to remote video");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during remote video subscription: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during remote video subscription");
        return false;
    }
}

bool ZoomSDKManager::UnsubscribeRemoteVideo(HWND hwnd)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        return false;
    }

    try {
        // Get session info to access user list
        IZoomVideoSDKSession* session = m_pZoomSDK->getSessionInfo();
        if (!session) {
            return false;
        }

        // Get remote users list
        IVideoSDKVector<IZoomVideoSDKUser*>* userList = session->getRemoteUsers();
        if (!userList || userList->GetCount() == 0) {
            return true; // No users to unsubscribe from
        }

        // Unsubscribe from all users (in a full implementation, you'd track which user is subscribed)
        for (int i = 0; i < userList->GetCount(); i++) {
            IZoomVideoSDKUser* user = userList->GetItem(i);
            if (user) {
                IZoomVideoSDKCanvas* videoCanvas = user->GetVideoCanvas();
                if (videoCanvas) {
                    videoCanvas->unSubscribeWithView(hwnd);
                }
            }
        }

        OnSessionStatusChanged(SessionStatus::InSession, "Unsubscribed from remote video");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during remote video unsubscription: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during remote video unsubscription");
        return false;
    }
}

// Device enumeration
std::vector<std::string> ZoomSDKManager::GetMicrophoneList()
{
    std::vector<std::string> devices;

    if (!m_bInitialized || !m_pZoomSDK) {
        devices.push_back("Default Microphone (SDK not initialized)");
        return devices;
    }

    try {
        // Get audio helper
        IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
        if (!audioHelper) {
            devices.push_back("Default Microphone (Audio helper unavailable)");
            return devices;
        }

        // Get microphone list using actual SDK call
        IVideoSDKVector<IZoomVideoSDKMicDevice*>* micList = audioHelper->getMicList();
        if (!micList || micList->GetCount() == 0) {
            devices.push_back("Default Microphone (No devices found)");
            return devices;
        }

        // Populate with real devices
        for (int i = 0; i < micList->GetCount(); i++) {
            IZoomVideoSDKMicDevice* micDevice = micList->GetItem(i);
            if (micDevice) {
                const zchar_t* name = micDevice->getDeviceName();
                const zchar_t* id = micDevice->getDeviceId();
                bool isSelected = micDevice->isSelectedDevice();
                
                if (name) {
                    // Convert wide string to narrow string properly
                    int len = WideCharToMultiByte(CP_UTF8, 0, name, -1, nullptr, 0, nullptr, nullptr);
                    if (len > 0) {
                        std::string deviceName(len - 1, 0);
                        WideCharToMultiByte(CP_UTF8, 0, name, -1, &deviceName[0], len, nullptr, nullptr);
                        
                        // Add selection indicator
                        if (isSelected) {
                            deviceName += " (Selected)";
                        }
                        devices.push_back(deviceName);
                    }
                }
            }
        }
    }
    catch (const std::exception& e) {
        devices.clear();
        devices.push_back(std::string("Error: ") + e.what());
    }
    catch (...) {
        devices.clear();
        devices.push_back("Unknown error occurred");
    }

    if (devices.empty()) {
        devices.push_back("No microphones available");
    }

    return devices;
}

std::vector<std::string> ZoomSDKManager::GetSpeakerList()
{
    std::vector<std::string> devices;

    if (!m_bInitialized || !m_pZoomSDK) {
        devices.push_back("Default Speaker (SDK not initialized)");
        return devices;
    }

    try {
        // Get audio helper
        IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
        if (!audioHelper) {
            devices.push_back("Default Speaker (Audio helper unavailable)");
            return devices;
        }

        // Get speaker list using actual SDK call
        IVideoSDKVector<IZoomVideoSDKSpeakerDevice*>* speakerList = audioHelper->getSpeakerList();
        if (!speakerList || speakerList->GetCount() == 0) {
            devices.push_back("Default Speaker (No devices found)");
            return devices;
        }

        // Populate with real devices
        for (int i = 0; i < speakerList->GetCount(); i++) {
            IZoomVideoSDKSpeakerDevice* speakerDevice = speakerList->GetItem(i);
            if (speakerDevice) {
                const zchar_t* name = speakerDevice->getDeviceName();
                const zchar_t* id = speakerDevice->getDeviceId();
                bool isSelected = speakerDevice->isSelectedDevice();
                
                if (name) {
                    // Convert wide string to narrow string properly
                    int len = WideCharToMultiByte(CP_UTF8, 0, name, -1, nullptr, 0, nullptr, nullptr);
                    if (len > 0) {
                        std::string deviceName(len - 1, 0);
                        WideCharToMultiByte(CP_UTF8, 0, name, -1, &deviceName[0], len, nullptr, nullptr);
                        
                        // Add selection indicator
                        if (isSelected) {
                            deviceName += " (Selected)";
                        }
                        devices.push_back(deviceName);
                    }
                }
            }
        }
    }
    catch (const std::exception& e) {
        devices.clear();
        devices.push_back(std::string("Error: ") + e.what());
    }
    catch (...) {
        devices.clear();
        devices.push_back("Unknown error occurred");
    }

    if (devices.empty()) {
        devices.push_back("No speakers available");
    }

    return devices;
}

std::vector<std::string> ZoomSDKManager::GetCameraList()
{
    std::vector<std::string> devices;

    if (!m_bInitialized || !m_pZoomSDK) {
        devices.push_back("Default Camera (SDK not initialized)");
        return devices;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            devices.push_back("Default Camera (Video helper unavailable)");
            return devices;
        }

        // Get camera list using actual SDK call
        IVideoSDKVector<IZoomVideoSDKCameraDevice*>* cameraList = videoHelper->getCameraList();
        if (!cameraList || cameraList->GetCount() == 0) {
            devices.push_back("Default Camera (No devices found)");
            return devices;
        }

        // Populate with real devices
        for (int i = 0; i < cameraList->GetCount(); i++) {
            IZoomVideoSDKCameraDevice* cameraDevice = cameraList->GetItem(i);
            if (cameraDevice) {
                const zchar_t* name = cameraDevice->getDeviceName();
                const zchar_t* id = cameraDevice->getDeviceId();
                bool isSelected = cameraDevice->isSelectedDevice();
                
                if (name) {
                    // Convert wide string to narrow string properly
                    int len = WideCharToMultiByte(CP_UTF8, 0, name, -1, nullptr, 0, nullptr, nullptr);
                    if (len > 0) {
                        std::string deviceName(len - 1, 0);
                        WideCharToMultiByte(CP_UTF8, 0, name, -1, &deviceName[0], len, nullptr, nullptr);
                        
                        // Add selection indicator
                        if (isSelected) {
                            deviceName += " (Selected)";
                        }
                        devices.push_back(deviceName);
                    }
                }
            }
        }
    }
    catch (const std::exception& e) {
        devices.clear();
        devices.push_back(std::string("Error: ") + e.what());
    }
    catch (...) {
        devices.clear();
        devices.push_back("Unknown error occurred");
    }

    if (devices.empty()) {
        devices.push_back("No cameras available");
    }

    return devices;
}

// Callback registration
void ZoomSDKManager::SetSessionStatusCallback(SessionStatusCallback callback)
{
    m_sessionCallback = callback;
}

void ZoomSDKManager::SetRemoteVideoCallback(VideoFrameCallback callback)
{
    m_remoteVideoCallback = callback;
}

void ZoomSDKManager::SetPreviewVideoCallback(VideoFrameCallback callback)
{
    m_previewVideoCallback = callback;
}

// Private methods
void ZoomSDKManager::OnSessionStatusChanged(SessionStatus status, const std::string& message)
{
    if (status == SessionStatus::InSession) {
        m_bInSession = true;
    }
    else if (status == SessionStatus::Idle) {
        m_bInSession = false;
        m_bVideoStarted = false;
    }

    if (m_sessionCallback) {
        SessionStatusEventArgs args = { status, message };
        m_sessionCallback(args);
    }
}

void ZoomSDKManager::OnRemoteVideoReceived(unsigned char* y, unsigned char* u, unsigned char* v,
                                          int width, int height, int yStride, int uStride, int vStride,
                                          const std::string& userId)
{
    if (m_remoteVideoCallback) {
        VideoFrameEventArgs args = { y, u, v, width, height, yStride, uStride, vStride, userId };
        m_remoteVideoCallback(args);
    }
}

void ZoomSDKManager::OnPreviewVideoReceived(unsigned char* y, unsigned char* u, unsigned char* v,
                                           int width, int height, int yStride, int uStride, int vStride)
{
    if (m_previewVideoCallback) {
        VideoFrameEventArgs args = { y, u, v, width, height, yStride, uStride, vStride, "self" };
        m_previewVideoCallback(args);
    }
}

// Device selection methods
bool ZoomSDKManager::SelectMicrophone(int deviceIndex)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        OnSessionStatusChanged(SessionStatus::Error, "SDK not initialized for microphone selection");
        return false;
    }

    try {
        // Get audio helper
        IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
        if (!audioHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get audio helper for microphone selection");
            return false;
        }

        // Get microphone list
        IVideoSDKVector<IZoomVideoSDKMicDevice*>* micList = audioHelper->getMicList();
        if (!micList || deviceIndex < 0 || deviceIndex >= micList->GetCount()) {
            OnSessionStatusChanged(SessionStatus::Error, "Invalid microphone device index");
            return false;
        }

        // Get the device at the specified index
        IZoomVideoSDKMicDevice* micDevice = micList->GetItem(deviceIndex);
        if (!micDevice) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get microphone device");
            return false;
        }

        // Select the device
        ZoomVideoSDKErrors ret = audioHelper->selectMic(micDevice->getDeviceId(), micDevice->getDeviceName());
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to select microphone: " + std::to_string((int)ret));
            return false;
        }

        OnSessionStatusChanged(SessionStatus::Idle, "Microphone selected successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during microphone selection: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during microphone selection");
        return false;
    }
}

bool ZoomSDKManager::SelectSpeaker(int deviceIndex)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        OnSessionStatusChanged(SessionStatus::Error, "SDK not initialized for speaker selection");
        return false;
    }

    try {
        // Get audio helper
        IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
        if (!audioHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get audio helper for speaker selection");
            return false;
        }

        // Get speaker list
        IVideoSDKVector<IZoomVideoSDKSpeakerDevice*>* speakerList = audioHelper->getSpeakerList();
        if (!speakerList || deviceIndex < 0 || deviceIndex >= speakerList->GetCount()) {
            OnSessionStatusChanged(SessionStatus::Error, "Invalid speaker device index");
            return false;
        }

        // Get the device at the specified index
        IZoomVideoSDKSpeakerDevice* speakerDevice = speakerList->GetItem(deviceIndex);
        if (!speakerDevice) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get speaker device");
            return false;
        }

        // Select the device
        ZoomVideoSDKErrors ret = audioHelper->selectSpeaker(speakerDevice->getDeviceId(), speakerDevice->getDeviceName());
        if (ret != ZoomVideoSDKErrors_Success) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to select speaker: " + std::to_string((int)ret));
            return false;
        }

        OnSessionStatusChanged(SessionStatus::Idle, "Speaker selected successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during speaker selection: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during speaker selection");
        return false;
    }
}

bool ZoomSDKManager::SelectCamera(int deviceIndex)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        OnSessionStatusChanged(SessionStatus::Error, "SDK not initialized for camera selection");
        return false;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get video helper for camera selection");
            return false;
        }

        // Get camera list
        IVideoSDKVector<IZoomVideoSDKCameraDevice*>* cameraList = videoHelper->getCameraList();
        if (!cameraList || deviceIndex < 0 || deviceIndex >= cameraList->GetCount()) {
            OnSessionStatusChanged(SessionStatus::Error, "Invalid camera device index");
            return false;
        }

        // Get the device at the specified index
        IZoomVideoSDKCameraDevice* cameraDevice = cameraList->GetItem(deviceIndex);
        if (!cameraDevice) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to get camera device");
            return false;
        }

        // Select the device
        bool ret = videoHelper->selectCamera(cameraDevice->getDeviceId());
        if (!ret) {
            OnSessionStatusChanged(SessionStatus::Error, "Failed to select camera");
            return false;
        }

        OnSessionStatusChanged(SessionStatus::Idle, "Camera selected successfully");
        return true;
    }
    catch (const std::exception& e) {
        OnSessionStatusChanged(SessionStatus::Error, "Exception during camera selection: " + std::string(e.what()));
        return false;
    }
    catch (...) {
        OnSessionStatusChanged(SessionStatus::Error, "Unknown exception during camera selection");
        return false;
    }
}

bool ZoomSDKManager::SelectMicrophoneByName(const std::string& deviceName)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        return false;
    }

    try {
        // Get audio helper
        IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
        if (!audioHelper) {
            return false;
        }

        // Get microphone list
        IVideoSDKVector<IZoomVideoSDKMicDevice*>* micList = audioHelper->getMicList();
        if (!micList) {
            return false;
        }

        // Find device by name (remove " (Selected)" suffix if present)
        std::string cleanDeviceName = deviceName;
        size_t pos = cleanDeviceName.find(" (Selected)");
        if (pos != std::string::npos) {
            cleanDeviceName = cleanDeviceName.substr(0, pos);
        }

        for (int i = 0; i < micList->GetCount(); i++) {
            IZoomVideoSDKMicDevice* micDevice = micList->GetItem(i);
            if (micDevice) {
                const zchar_t* name = micDevice->getDeviceName();
                if (name) {
                    // Convert wide string to narrow string
                    int len = WideCharToMultiByte(CP_UTF8, 0, name, -1, nullptr, 0, nullptr, nullptr);
                    if (len > 0) {
                        std::string currentDeviceName(len - 1, 0);
                        WideCharToMultiByte(CP_UTF8, 0, name, -1, &currentDeviceName[0], len, nullptr, nullptr);
                        
                        if (currentDeviceName == cleanDeviceName) {
                            return SelectMicrophone(i);
                        }
                    }
                }
            }
        }

        return false;
    }
    catch (...) {
        return false;
    }
}

bool ZoomSDKManager::SelectSpeakerByName(const std::string& deviceName)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        return false;
    }

    try {
        // Get audio helper
        IZoomVideoSDKAudioHelper* audioHelper = m_pZoomSDK->getAudioHelper();
        if (!audioHelper) {
            return false;
        }

        // Get speaker list
        IVideoSDKVector<IZoomVideoSDKSpeakerDevice*>* speakerList = audioHelper->getSpeakerList();
        if (!speakerList) {
            return false;
        }

        // Find device by name (remove " (Selected)" suffix if present)
        std::string cleanDeviceName = deviceName;
        size_t pos = cleanDeviceName.find(" (Selected)");
        if (pos != std::string::npos) {
            cleanDeviceName = cleanDeviceName.substr(0, pos);
        }

        for (int i = 0; i < speakerList->GetCount(); i++) {
            IZoomVideoSDKSpeakerDevice* speakerDevice = speakerList->GetItem(i);
            if (speakerDevice) {
                const zchar_t* name = speakerDevice->getDeviceName();
                if (name) {
                    // Convert wide string to narrow string
                    int len = WideCharToMultiByte(CP_UTF8, 0, name, -1, nullptr, 0, nullptr, nullptr);
                    if (len > 0) {
                        std::string currentDeviceName(len - 1, 0);
                        WideCharToMultiByte(CP_UTF8, 0, name, -1, &currentDeviceName[0], len, nullptr, nullptr);
                        
                        if (currentDeviceName == cleanDeviceName) {
                            return SelectSpeaker(i);
                        }
                    }
                }
            }
        }

        return false;
    }
    catch (...) {
        return false;
    }
}

bool ZoomSDKManager::SelectCameraByName(const std::string& deviceName)
{
    if (!m_bInitialized || !m_pZoomSDK) {
        return false;
    }

    try {
        // Get video helper
        IZoomVideoSDKVideoHelper* videoHelper = m_pZoomSDK->getVideoHelper();
        if (!videoHelper) {
            return false;
        }

        // Get camera list
        IVideoSDKVector<IZoomVideoSDKCameraDevice*>* cameraList = videoHelper->getCameraList();
        if (!cameraList) {
            return false;
        }

        // Find device by name (remove " (Selected)" suffix if present)
        std::string cleanDeviceName = deviceName;
        size_t pos = cleanDeviceName.find(" (Selected)");
        if (pos != std::string::npos) {
            cleanDeviceName = cleanDeviceName.substr(0, pos);
        }

        for (int i = 0; i < cameraList->GetCount(); i++) {
            IZoomVideoSDKCameraDevice* cameraDevice = cameraList->GetItem(i);
            if (cameraDevice) {
                const zchar_t* name = cameraDevice->getDeviceName();
                if (name) {
                    // Convert wide string to narrow string
                    int len = WideCharToMultiByte(CP_UTF8, 0, name, -1, nullptr, 0, nullptr, nullptr);
                    if (len > 0) {
                        std::string currentDeviceName(len - 1, 0);
                        WideCharToMultiByte(CP_UTF8, 0, name, -1, &currentDeviceName[0], len, nullptr, nullptr);
                        
                        if (currentDeviceName == cleanDeviceName) {
                            return SelectCamera(i);
                        }
                    }
                }
            }
        }

        return false;
    }
    catch (...) {
        return false;
    }
}
