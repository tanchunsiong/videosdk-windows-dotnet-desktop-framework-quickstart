# Zoom Video SDK C# Example

A Windows Forms application demonstrating the integration of Zoom Video SDK with C# using a C++/CLI wrapper.

## 📁 Project Structure

```
SkeletonExample_CSharp/
├── README.md                     # This file
├── ZoomVideoSDK.CSharp.sln      # Visual Studio solution file
├── config.json                  # Configuration file
├── h/                           # Zoom Video SDK header files
│   ├── zoom_video_sdk_*.h       # Main SDK headers
│   └── helpers/                 # Helper interface headers
├── lib/                         # Static libraries
│   └── videosdk.lib            # Zoom Video SDK static library
├── dll/                         # Runtime DLLs (copied to output during build)
│   └── videosdk.dll            # Main SDK runtime library
├── bin/                         # Build output directory
│   ├── Debug/                   # Debug build outputs
│   └── Release/                 # Release build outputs
├── obj/                         # Intermediate build files
├── ZoomVideoSDK.Wrapper/        # C++/CLI wrapper project
│   ├── ZoomVideoSDK.Wrapper.vcxproj
│   ├── ZoomSDKManager.h         # Wrapper header
│   └── ZoomSDKManager.cpp       # Wrapper implementation
└── ZoomVideoSDK.WinForms/       # C# Windows Forms application
    ├── ZoomVideoSDK.WinForms.csproj
    ├── MainForm.cs              # Main application form
    ├── Program.cs               # Application entry point
    └── ZoomSDKInterop.cs        # C# interop classes
```

## 🚀 Getting Started

### Prerequisites

- **Visual Studio 2022** (Community, Professional, or Enterprise)
- **.NET Framework 4.8** or later
- **Windows 10/11** (x64)
- **C++/CLI support** in Visual Studio
- **Zoom Video SDK** (headers and libraries included)

### Building the Project

1. **Open the solution**:
   ```
   Open ZoomVideoSDK.CSharp.sln in Visual Studio 2022
   ```

2. **Set build configuration**:
   - Configuration: `Debug` or `Release`
   - Platform: `x64` (required)

3. **Build the solution**:
   - Press `Ctrl+Shift+B` or use `Build > Build Solution`
   - The build process will:
     - Compile the C++/CLI wrapper
     - Automatically copy DLLs from `dll/` folder to output directory
     - Build the C# Windows Forms application

4. **Run the application**:
   - Press `F5` or use `Debug > Start Debugging`

### Alternative Build (Command Line)

```bash
# Navigate to the project directory
cd SkeletonExample_CSharp

# Build using MSBuild
"C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe" ZoomVideoSDK.CSharp.sln /p:Configuration=Debug /p:Platform=x64
```

## 🏗️ Architecture

### Component Overview

1. **ZoomVideoSDK.WinForms** (C# Application)
   - Windows Forms UI
   - Event handling and user interactions
   - Calls into the C++/CLI wrapper

2. **ZoomVideoSDK.Wrapper** (C++/CLI Bridge)
   - Bridges C# managed code with native Zoom SDK
   - Handles SDK initialization and session management
   - Provides managed interfaces for SDK functionality

3. **Zoom Video SDK** (Native C++)
   - Core video conferencing functionality
   - Audio/video processing
   - Network communication

### Data Flow

```
C# UI Layer (WinForms)
        ↕
C++/CLI Wrapper Layer
        ↕
Native Zoom SDK (C++)
```

## 🔧 Key Features

- **Session Management**: Join/leave video sessions
- **Audio Controls**: Mute/unmute microphone and speakers
- **Video Controls**: Start/stop camera
- **Device Management**: List and select audio/video devices
- **Event Handling**: Real-time session status updates
- **Cross-Platform Bridge**: Seamless C# to C++ integration

## 📝 Usage Example

```csharp
// Initialize the SDK
var sdkManager = new ZoomSDKManager();
bool initialized = sdkManager.Initialize();

// Join a session
bool joined = sdkManager.JoinSession(
    sessionName: "MySession",
    token: "your_jwt_token",
    userName: "John Doe",
    password: "optional_password"
);

// Handle events
sdkManager.SessionStatusChanged += (sender, e) => {
    Console.WriteLine($"Status: {e.Status}, Message: {e.Message}");
};

// Leave session when done
sdkManager.LeaveSession();
```

## 🔄 Build Process Details

### Automatic DLL Management

The build system automatically handles runtime dependencies:

1. **Pre-build**: Essential DLLs are stored in the `dll/` folder
2. **Post-build**: DLLs are automatically copied to the output directory
3. **Runtime**: Application finds all dependencies in the same folder

### Build Events

- **C++ Wrapper Post-Build**: Copies DLLs from `dll/` to `bin/Debug` or `bin/Release`
- **C# Application Post-Build**: Ensures all dependencies are in the final output directory

## 🐛 Troubleshooting

### Common Issues

1. **Build Error: "Cannot open include file"**
   - Ensure all header files are in the `h/` folder
   - Check that include paths in the project are correct

2. **Link Error: "Cannot find videosdk.lib"**
   - Verify `videosdk.lib` is in the `lib/` folder
   - Check library paths in project settings

3. **Runtime Error: "DLL not found"**
   - Ensure `videosdk.dll` is in the `dll/` folder
   - Verify post-build events are copying DLLs correctly

4. **Platform Mismatch**
   - Always build for `x64` platform
   - Ensure all projects target the same platform

### Debug Tips

- Check the build output for post-build event execution
- Verify DLL copying with: `copy "dll\*.dll" "bin\Debug\" /Y`
- Use Dependency Walker to check DLL dependencies

## 📋 Requirements

### System Requirements

- **OS**: Windows 10 (1903) or Windows 11
- **Architecture**: x64 only
- **Memory**: 4GB RAM minimum, 8GB recommended
- **Network**: Internet connection for Zoom services

### Development Requirements

- **Visual Studio 2022** with:
  - C++ desktop development workload
  - .NET desktop development workload
  - Windows 10/11 SDK

## 🔐 Security Notes

- **JWT Tokens**: Store securely, never hardcode in source
- **Session Passwords**: Handle securely in production
- **Network**: Ensure proper firewall configuration for Zoom services

## 📚 Additional Resources

- [Zoom Video SDK Documentation](https://developers.zoom.us/docs/video-sdk/)

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📄 License

This project is provided as an example implementation. Please refer to Zoom's licensing terms for the Video SDK usage.

---

**Note**: This is a skeleton example for demonstration purposes. For production use, implement proper error handling, logging, and security measures.
