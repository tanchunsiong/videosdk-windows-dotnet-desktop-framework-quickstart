// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// Zoom Video SDK Headers
#include <zoom_video_sdk_interface.h>
#include <zoom_video_sdk_api.h>
#include <zoom_video_sdk_delegate_interface.h>
#include <zoom_video_sdk_session_info_interface.h>
#include <helpers/zoom_video_sdk_audio_helper_interface.h>
#include <helpers/zoom_video_sdk_video_helper_interface.h>
#include <helpers/zoom_video_sdk_user_helper_interface.h>
#include <zoom_sdk_raw_data_def.h>
#include <zoom_video_sdk_vector_interface.h>
