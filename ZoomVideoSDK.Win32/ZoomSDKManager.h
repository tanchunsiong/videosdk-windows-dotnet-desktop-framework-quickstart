// ZoomSDKManager.h : Native C++ wrapper for Zoom Video SDK
#pragma once

#include <string>
#include <vector>
#include <functional>
#include <memory>

// Include Zoom SDK headers (these will be empty if SDK not installed)
#include <zoom_video_sdk_interface.h>
#include <zoom_video_sdk_api.h>
#include <zoom_video_sdk_def.h>
#include <zoom_video_sdk_session_info_interface.h>
#include <zoom_video_sdk_delegate_interface.h>
#include <zoom_video_sdk_vector_interface.h>
#include <zoom_sdk_raw_data_def.h>

// Forward declarations for Zoom SDK types
namespace ZOOMVIDEOSDK {
    class IZoomVideoSDK;
    class IZoomVideoSDKSession;
    class IZoomVideoSDKVideoHelper;
    class IZoomVideoSDKAudioHelper;
    class IZoomVideoSDKUserHelper;
    class IZoomVideoSDKDelegate;
}
class YUVRawDataI420;

// Forward declaration
class ZoomSDKManager;
class CustomZoomDelegate;

// Event callback types
enum class SessionStatus {
    Idle,
    Joining,
    InSession,
    Leaving,
    Reconnecting,
    Failed,
    Error
};

struct SessionStatusEventArgs {
    SessionStatus Status;
    std::string Message;
};

struct VideoFrameEventArgs {
    unsigned char* YBuffer;
    unsigned char* UBuffer;
    unsigned char* VBuffer;
    int Width;
    int Height;
    int YStride;
    int UStride;
    int VStride;
    std::string UserId;
};

// Callback function types
using SessionStatusCallback = std::function<void(const SessionStatusEventArgs&)>;
using VideoFrameCallback = std::function<void(const VideoFrameEventArgs&)>;

class ZoomSDKManager {
private:
    // SDK objects
    ZOOMVIDEOSDK::IZoomVideoSDK* m_pZoomSDK;
    ZOOMVIDEOSDK::IZoomVideoSDKSession* m_pSession;
    CustomZoomDelegate* m_pDelegate;
    bool m_bInitialized;
    bool m_bInSession;
    bool m_bVideoStarted;

    // Callbacks
    SessionStatusCallback m_sessionCallback;
    VideoFrameCallback m_remoteVideoCallback;
    VideoFrameCallback m_previewVideoCallback;

public:
    // Public callback methods (accessible by delegate)
    void OnSessionStatusChanged(SessionStatus status, const std::string& message);
    void OnRemoteVideoReceived(unsigned char* y, unsigned char* u, unsigned char* v,
                              int width, int height, int yStride, int uStride, int vStride,
                              const std::string& userId);
    void OnPreviewVideoReceived(unsigned char* y, unsigned char* u, unsigned char* v,
                               int width, int height, int yStride, int uStride, int vStride);

private:
    // Private methods
    void CleanupSDK();

public:
    ZoomSDKManager();
    ~ZoomSDKManager();

    // Initialization
    bool Initialize();
    void Cleanup();

    // Session management
    bool JoinSession(const std::string& sessionName, const std::string& token,
                    const std::string& userName, const std::string& password = "");
    bool LeaveSession();

    // Audio controls
    bool MuteAudio(bool mute);
    bool IsAudioMuted();

    // Video controls
    bool StartVideo();
    bool StopVideo();
    bool IsVideoStarted();
    
    // Video preview and rendering
    bool StartVideoPreview(HWND hwnd);
    bool StopVideoPreview(HWND hwnd);
    bool SubscribeRemoteVideo(HWND hwnd, const std::string& userId);
    bool UnsubscribeRemoteVideo(HWND hwnd);

    // Device enumeration
    std::vector<std::string> GetMicrophoneList();
    std::vector<std::string> GetSpeakerList();
    std::vector<std::string> GetCameraList();

    // Device selection
    bool SelectMicrophone(int deviceIndex);
    bool SelectSpeaker(int deviceIndex);
    bool SelectCamera(int deviceIndex);
    bool SelectMicrophoneByName(const std::string& deviceName);
    bool SelectSpeakerByName(const std::string& deviceName);
    bool SelectCameraByName(const std::string& deviceName);

    // Callback registration
    void SetSessionStatusCallback(SessionStatusCallback callback);
    void SetRemoteVideoCallback(VideoFrameCallback callback);
    void SetPreviewVideoCallback(VideoFrameCallback callback);

    // Properties
    bool IsInitialized() const { return m_bInitialized; }
    bool IsInSession() const { return m_bInSession; }
};

// Custom delegate class that implements IZoomVideoSDKDelegate
class CustomZoomDelegate : public ZOOMVIDEOSDK::IZoomVideoSDKDelegate {
private:
    ZoomSDKManager* m_pManager;

public:
    CustomZoomDelegate(ZoomSDKManager* manager);
    virtual ~CustomZoomDelegate();

    // Core session callbacks
    void onSessionJoin() override;
    void onSessionLeave() override;
    void onSessionLeave(ZOOMVIDEOSDK::ZoomVideoSDKSessionLeaveReason eReason) override;
    void onError(ZOOMVIDEOSDK::ZoomVideoSDKErrors errorCode, int detailErrorCode) override;

    // User management callbacks
    void onUserJoin(ZOOMVIDEOSDK::IZoomVideoSDKUserHelper* pUserHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) override;
    void onUserLeave(ZOOMVIDEOSDK::IZoomVideoSDKUserHelper* pUserHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) override;
    void onUserVideoStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKVideoHelper* pVideoHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) override;
    void onUserAudioStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKAudioHelper* pAudioHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) override;
    void onUserHostChanged(ZOOMVIDEOSDK::IZoomVideoSDKUserHelper* pUserHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;
    void onUserActiveAudioChanged(ZOOMVIDEOSDK::IZoomVideoSDKAudioHelper* pAudioHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* list) override;
    void onUserManagerChanged(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;
    void onUserNameChanged(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;
    void onUserRecordingConsent(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;

    // Share callbacks
    void onUserShareStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) override;
    void onShareContentChanged(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) override;
    void onFailedToStartShare(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;
    void onShareSettingChanged(ZOOMVIDEOSDK::ZoomVideoSDKShareSetting setting) override;
    void onShareContentSizeChanged(ZOOMVIDEOSDK::IZoomVideoSDKShareHelper* pShareHelper, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) override;

    // Live stream callbacks
    void onLiveStreamStatusChanged(ZOOMVIDEOSDK::IZoomVideoSDKLiveStreamHelper* pLiveStreamHelper, ZOOMVIDEOSDK::ZoomVideoSDKLiveStreamStatus status) override;

    // Chat callbacks
    void onChatNewMessageNotify(ZOOMVIDEOSDK::IZoomVideoSDKChatHelper* pChatHelper, ZOOMVIDEOSDK::IZoomVideoSDKChatMessage* messageItem) override;
    void onChatMsgDeleteNotification(ZOOMVIDEOSDK::IZoomVideoSDKChatHelper* pChatHelper, const zchar_t* msgID, ZOOMVIDEOSDK::ZoomVideoSDKChatMessageDeleteType deleteBy) override;
    void onChatPrivilegeChanged(ZOOMVIDEOSDK::IZoomVideoSDKChatHelper* pChatHelper, ZOOMVIDEOSDK::ZoomVideoSDKChatPrivilegeType privilege) override;

    // Password callbacks
    void onSessionNeedPassword(ZOOMVIDEOSDK::IZoomVideoSDKPasswordHandler* handler) override;
    void onSessionPasswordWrong(ZOOMVIDEOSDK::IZoomVideoSDKPasswordHandler* handler) override;

    // Audio raw data callbacks
    void onMixedAudioRawDataReceived(AudioRawData* data_) override;
    void onOneWayAudioRawDataReceived(AudioRawData* data_, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;
    void onSharedAudioRawDataReceived(AudioRawData* data_) override;

    // Command channel callbacks
    void onCommandReceived(ZOOMVIDEOSDK::IZoomVideoSDKUser* sender, const zchar_t* strCmd) override;
    void onCommandChannelConnectResult(bool isSuccess) override;

    // Phone callbacks
    void onInviteByPhoneStatus(ZOOMVIDEOSDK::PhoneStatus status, ZOOMVIDEOSDK::PhoneFailedReason reason) override;
    void onCalloutJoinSuccess(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, const zchar_t* phoneNumber) override;

    // Recording callbacks
    void onCloudRecordingStatus(ZOOMVIDEOSDK::RecordingStatus status, ZOOMVIDEOSDK::IZoomVideoSDKRecordingConsentHandler* pHandler) override;
    void onHostAskUnmute() override;

    // Multi-camera callbacks
    void onMultiCameraStreamStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKMultiCameraStreamStatus status, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKRawDataPipe* pVideoPipe) override;

    // Volume and device callbacks
    void onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume) override;
    void onAudioDeviceStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKAudioDeviceType type, ZOOMVIDEOSDK::ZoomVideoSDKAudioDeviceStatus status) override;
    void onTestMicStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDK_TESTMIC_STATUS status) override;
    void onSelectedAudioDeviceChanged() override;
    void onCameraListChanged() override;

    // Camera control callbacks
    void onCameraControlRequestResult(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, bool isApproved) override;
    void onCameraControlRequestReceived(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::ZoomVideoSDKCameraControlRequestType requestType, ZOOMVIDEOSDK::IZoomVideoSDKCameraControlRequestHandler* pCameraControlRequestHandler) override;

#if defined(WIN32) || defined(__MACOS__)
    // Remote control callbacks (Windows/Mac only)
    void onRemoteControlStatus(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction, ZOOMVIDEOSDK::ZoomVideoSDKRemoteControlStatus status) override;
    void onRemoteControlRequestReceived(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction, ZOOMVIDEOSDK::IZoomVideoSDKRemoteControlRequestHandler* pRemoteControlRequestHandler) override;
#endif

#if defined(WIN32)
    // Windows-specific callbacks
    void onRemoteControlServiceInstallResult(bool bSuccess) override;
#endif

    // Live transcription callbacks
    void onLiveTranscriptionStatus(ZOOMVIDEOSDK::ZoomVideoSDKLiveTranscriptionStatus status) override;
    void onOriginalLanguageMsgReceived(ZOOMVIDEOSDK::ILiveTranscriptionMessageInfo* messageInfo) override;
    void onLiveTranscriptionMsgInfoReceived(ZOOMVIDEOSDK::ILiveTranscriptionMessageInfo* messageInfo) override;
    void onLiveTranscriptionMsgError(ZOOMVIDEOSDK::ILiveTranscriptionLanguage* spokenLanguage, ZOOMVIDEOSDK::ILiveTranscriptionLanguage* transcriptLanguage) override;
    void onSpokenLanguageChanged(ZOOMVIDEOSDK::ILiveTranscriptionLanguage* spokenLanguage) override;

    // File transfer callbacks
    void onSendFileStatus(ZOOMVIDEOSDK::IZoomVideoSDKSendFile* file, const ZOOMVIDEOSDK::FileTransferStatus& status) override;
    void onReceiveFileStatus(ZOOMVIDEOSDK::IZoomVideoSDKReceiveFile* file, const ZOOMVIDEOSDK::FileTransferStatus& status) override;

    // Network callbacks
    void onProxyDetectComplete() override;
    void onProxySettingNotification(ZOOMVIDEOSDK::IZoomVideoSDKProxySettingHandler* handler) override;
    void onSSLCertVerifiedFailNotification(ZOOMVIDEOSDK::IZoomVideoSDKSSLCertificateInfo* info) override;
    void onUserVideoNetworkStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKNetworkStatus status, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser) override;
    void onShareNetworkStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKNetworkStatus shareNetworkStatus, bool isSendingShare) override;

    // CRC callbacks
    void onCallCRCDeviceStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKCRCCallStatus status) override;

#if !defined __linux
    // Non-Linux callbacks
    void onVideoCanvasSubscribeFail(ZOOMVIDEOSDK::ZoomVideoSDKSubscribeFailReason fail_reason, ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, void* handle) override;
    void onShareCanvasSubscribeFail(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, void* handle, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) override;
#endif

    // Annotation callbacks
    void onAnnotationHelperCleanUp(ZOOMVIDEOSDK::IZoomVideoSDKAnnotationHelper* helper) override;
    void onAnnotationPrivilegeChange(ZOOMVIDEOSDK::IZoomVideoSDKUser* pUser, ZOOMVIDEOSDK::IZoomVideoSDKShareAction* pShareAction) override;
    void onAnnotationHelperActived(void* handle) override;

    // Video callbacks
    void onVideoAlphaChannelStatusChanged(bool isAlphaModeOn) override;
    void onSpotlightVideoChanged(ZOOMVIDEOSDK::IZoomVideoSDKVideoHelper* pVideoHelper, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IZoomVideoSDKUser*>* userList) override;

    // Live stream callbacks
    void onBindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) override;
    void onUnbindIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) override;
    void onIncomingLiveStreamStatusResponse(bool bSuccess, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::IncomingLiveStreamStatus>* pStreamsStatusList) override;
    void onStartIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) override;
    void onStopIncomingLiveStreamResponse(bool bSuccess, const zchar_t* strStreamKeyID) override;

    // Subsession callbacks
    void onSubSessionStatusChanged(ZOOMVIDEOSDK::ZoomVideoSDKSubSessionStatus status, ZOOMVIDEOSDK::IVideoSDKVector<ZOOMVIDEOSDK::ISubSessionKit*>* pSubSessionKitList) override;
    void onSubSessionManagerHandle(ZOOMVIDEOSDK::IZoomVideoSDKSubSessionManager* pManager) override;
    void onSubSessionParticipantHandle(ZOOMVIDEOSDK::IZoomVideoSDKSubSessionParticipant* pParticipant) override;
    void onSubSessionUsersUpdate(ZOOMVIDEOSDK::ISubSessionKit* pSubSessionKit) override;
    void onBroadcastMessageFromMainSession(const zchar_t* sMessage, const zchar_t* sUserName) override;
    void onSubSessionUserHelpRequest(ZOOMVIDEOSDK::ISubSessionUserHelpRequestHandler* pHandler) override;
    void onSubSessionUserHelpRequestResult(ZOOMVIDEOSDK::ZoomVideoSDKUserHelpRequestResult eResult) override;
};
