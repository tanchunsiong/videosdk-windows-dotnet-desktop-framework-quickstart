using System;
using System.Drawing;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;
using System.Windows.Media;
using System.IO;
using ZoomVideoSDKWrapper;
using DrawingBrushes = System.Drawing.Brushes;
using MediaBrushes = System.Windows.Media.Brushes;
using DrawingColor = System.Drawing.Color;

namespace ZoomVideoSDK.WPF
{
    // Event args for video frames - WPF version using BitmapSource
    public class VideoFrameEventArgs : EventArgs
    {
        public BitmapSource Frame { get; set; }
        public string UserId { get; set; }
        
        public VideoFrameEventArgs(BitmapSource frame, string userId)
        {
            Frame = frame;
            UserId = userId;
        }
    }

    // Managed wrapper class using C++/CLI wrapper - WPF version
    public class ZoomSDKInterop
    {
        private ZoomSDKManager _sdkManager;
        private bool _isInitialized = false;
        private bool _isInSession = false;
        private bool _isVideoStarted = false;

        // Events
        public event EventHandler SessionJoined;
        public event EventHandler SessionLeft;
        public event EventHandler<string> SessionError;
        public event EventHandler<string> StatusChanged;
        public event EventHandler<VideoFrameEventArgs> RemoteVideoReceived;
        public event EventHandler<VideoFrameEventArgs> PreviewVideoReceived;

        public bool IsInitialized => _isInitialized;
        public bool IsInSession => _isInSession;

        public ZoomSDKInterop()
        {
            try
            {
                // Create the C++/CLI wrapper instance
                _sdkManager = new ZoomSDKManager();
                
                // Subscribe to events from the C++/CLI wrapper
                _sdkManager.SessionStatusChanged += (sender, e) => 
                {
                    StatusChanged?.Invoke(this, $"Session status: {e.Status} - {e.Message}");
                    
                    switch (e.Status)
                    {
                        case SessionStatus.InSession:
                            _isInSession = true;
                            SessionJoined?.Invoke(this, EventArgs.Empty);
                            break;
                        case SessionStatus.Idle:
                            if (_isInSession) // Only fire if we were previously in session
                            {
                                _isInSession = false;
                                SessionLeft?.Invoke(this, EventArgs.Empty);
                            }
                            break;
                        case SessionStatus.Failed:
                        case SessionStatus.Error:
                            SessionError?.Invoke(this, e.Message);
                            break;
                    }
                };
                
                _sdkManager.RemoteVideoReceived += (sender, e) => 
                {
                    var wpfFrame = ConvertBitmapToBitmapSource(e.Frame);
                    RemoteVideoReceived?.Invoke(this, new VideoFrameEventArgs(wpfFrame, e.UserId));
                };
                
                _sdkManager.PreviewVideoReceived += (sender, e) => 
                {
                    var wpfFrame = ConvertBitmapToBitmapSource(e.Frame);
                    PreviewVideoReceived?.Invoke(this, new VideoFrameEventArgs(wpfFrame, "self"));
                };

                StatusChanged?.Invoke(this, "C++/CLI SDK Manager created successfully");
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Failed to create SDK Manager: {ex.Message}");
            }
        }

        public bool Initialize()
        {
            try
            {
                StatusChanged?.Invoke(this, "Initializing Zoom Video SDK with C++/CLI wrapper...");
                
                if (_sdkManager == null)
                {
                    StatusChanged?.Invoke(this, "SDK initialization failed - no SDK manager");
                    return false;
                }

                // Call the C++/CLI wrapper initialize method
                bool result = _sdkManager.Initialize();
                
                if (result)
                {
                    _isInitialized = true;
                    StatusChanged?.Invoke(this, "SDK initialized successfully with real Zoom SDK via C++/CLI");
                    return true;
                }
                else
                {
                    StatusChanged?.Invoke(this, "SDK initialization failed via C++/CLI wrapper");
                    return false;
                }
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Initialization failed: {ex.Message}");
                return false;
            }
        }

        public bool JoinSession(string sessionName, string token, string userName, string password = "")
        {
            if (!_isInitialized) 
            {
                StatusChanged?.Invoke(this, "SDK not initialized");
                return false;
            }

            try
            {
                StatusChanged?.Invoke(this, $"Attempting to join session '{sessionName}' as '{userName}' with C++/CLI wrapper");
                
                // Call the C++/CLI wrapper join session method
                bool result = _sdkManager.JoinSession(sessionName, token, userName, password);
                
                if (result)
                {
                    StatusChanged?.Invoke(this, $"Join session initiated for '{sessionName}' - waiting for connection...");
                    return true;
                }
                else
                {
                    StatusChanged?.Invoke(this, "Join session failed via C++/CLI wrapper");
                    return false;
                }
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Join session failed: {ex.Message}");
                return false;
            }
        }

        public bool LeaveSession()
        {
            if (!_isInSession) return false;

            try
            {
                StatusChanged?.Invoke(this, "Leaving session with C++/CLI wrapper...");
                
                // Stop video if running
                if (_isVideoStarted)
                {
                    StopVideo();
                }
                
                // Call the C++/CLI wrapper leave session method
                _sdkManager.LeaveSession();
                StatusChanged?.Invoke(this, "Leave session initiated via C++/CLI wrapper");
                return true;
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Leave session failed: {ex.Message}");
                // Still update local state even if exception occurred
                _isInSession = false;
                SessionLeft?.Invoke(this, EventArgs.Empty);
                return false;
            }
        }

        public bool MuteAudio(bool mute)
        {
            if (!_isInSession) return false;

            try
            {
                // Call the C++/CLI wrapper mute audio method
                bool result = _sdkManager.MuteAudio(mute);
                
                if (result)
                {
                    StatusChanged?.Invoke(this, $"Audio {(mute ? "muted" : "unmuted")} via C++/CLI wrapper");
                    return true;
                }
                else
                {
                    StatusChanged?.Invoke(this, $"Failed to {(mute ? "mute" : "unmute")} audio via C++/CLI wrapper");
                    return false;
                }
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Mute audio failed: {ex.Message}");
                return false;
            }
        }

        public bool IsAudioMuted()
        {
            try
            {
                if (_sdkManager != null && _isInSession)
                {
                    return _sdkManager.IsAudioMuted();
                }
                return false;
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Failed to get audio mute status: {ex.Message}");
                return false;
            }
        }

        public bool StartVideo()
        {
            if (!_isInSession) return false;

            try
            {
                // Check if video is already started using proper video status checking
                if (_sdkManager.IsCurrentUserVideoOn())
                {
                    StatusChanged?.Invoke(this, "Video is already started - skipping duplicate start");
                    _isVideoStarted = true;
                    return true;
                }

                StatusChanged?.Invoke(this, "Starting video via C++/CLI wrapper...");
                
                // Call the C++/CLI wrapper start video method
                bool result = _sdkManager.StartVideo();
                
                if (result)
                {
                    _isVideoStarted = true;
                    StatusChanged?.Invoke(this, "Video started successfully via C++/CLI wrapper");
                    return true;
                }
                else
                {
                    StatusChanged?.Invoke(this, "Failed to start video via C++/CLI wrapper");
                    return false;
                }
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Start video failed: {ex.Message}");
                return false;
            }
        }

        public bool StopVideo()
        {
            if (!_isInSession) return false;

            try
            {
                StatusChanged?.Invoke(this, "Stopping video via C++/CLI wrapper...");
                
                // Call the C++/CLI wrapper stop video method
                bool result = _sdkManager.StopVideo();
                
                if (result)
                {
                    _isVideoStarted = false;
                    StatusChanged?.Invoke(this, "Video stopped successfully via C++/CLI wrapper");
                    return true;
                }
                else
                {
                    StatusChanged?.Invoke(this, "Failed to stop video via C++/CLI wrapper");
                    return false;
                }
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Stop video failed: {ex.Message}");
                return false;
            }
        }

        public bool IsVideoStarted()
        {
            try
            {
                if (_sdkManager != null && _isInSession)
                {
                    return _sdkManager.IsVideoStarted();
                }
                return _isVideoStarted;
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Failed to get video status: {ex.Message}");
                return _isVideoStarted;
            }
        }

        // Device enumeration methods using C++/CLI wrapper
        public string[] GetMicrophoneList()
        {
            try
            {
                if (_sdkManager != null)
                {
                    return _sdkManager.GetMicrophoneList();
                }
                return new string[] { "Default Microphone" };
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Failed to get microphone list: {ex.Message}");
                return new string[] { "Default Microphone" };
            }
        }

        public string[] GetSpeakerList()
        {
            try
            {
                if (_sdkManager != null)
                {
                    return _sdkManager.GetSpeakerList();
                }
                return new string[] { "Default Speaker" };
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Failed to get speaker list: {ex.Message}");
                return new string[] { "Default Speaker" };
            }
        }

        public string[] GetCameraList()
        {
            try
            {
                if (_sdkManager != null)
                {
                    return _sdkManager.GetCameraList();
                }
                return new string[] { "Default Camera" };
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Failed to get camera list: {ex.Message}");
                return new string[] { "Default Camera" };
            }
        }

        // WPF-specific method to convert System.Drawing.Bitmap to WPF BitmapSource
        private BitmapSource ConvertBitmapToBitmapSource(Bitmap bitmap)
        {
            if (bitmap == null) return null;

            try
            {
                using (var memory = new MemoryStream())
                {
                    bitmap.Save(memory, System.Drawing.Imaging.ImageFormat.Png);
                    memory.Position = 0;
                    
                    var bitmapImage = new BitmapImage();
                    bitmapImage.BeginInit();
                    bitmapImage.StreamSource = memory;
                    bitmapImage.CacheOption = BitmapCacheOption.OnLoad;
                    bitmapImage.EndInit();
                    bitmapImage.Freeze(); // Make it thread-safe
                    
                    return bitmapImage;
                }
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Bitmap conversion failed: {ex.Message}");
                return CreateErrorBitmapSource(bitmap?.Width ?? 320, bitmap?.Height ?? 240, "Conversion Error");
            }
        }

        // Helper method to convert YUV420 data to RGB bitmap (same as WinForms version)
        private Bitmap ConvertYUVToBitmap(byte[] yuvData, int width, int height)
        {
            try
            {
                // FIXED: Proper YUV420 to RGB conversion (based on Linux implementation)
                var bitmap = new Bitmap(width, height, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
                
                // YUV420 format: Y plane + U plane + V plane
                // Y plane: width * height bytes
                // U plane: (width/2) * (height/2) bytes  
                // V plane: (width/2) * (height/2) bytes
                int ySize = width * height;
                int uvSize = (width / 2) * (height / 2);
                
                if (yuvData.Length < ySize + 2 * uvSize)
                {
                    StatusChanged?.Invoke(this, $"Invalid YUV data size: {yuvData.Length}, expected: {ySize + 2 * uvSize}");
                    return CreateErrorBitmap(width, height, "Invalid YUV Size");
                }
                
                // Lock bitmap for direct pixel access (much faster)
                var bitmapData = bitmap.LockBits(new Rectangle(0, 0, width, height), 
                    System.Drawing.Imaging.ImageLockMode.WriteOnly, 
                    System.Drawing.Imaging.PixelFormat.Format24bppRgb);
                
                unsafe
                {
                    byte* rgbPtr = (byte*)bitmapData.Scan0;
                    int stride = bitmapData.Stride;
                    
                    // YUV420 to RGB conversion using standard coefficients
                    for (int y = 0; y < height; y++)
                    {
                        for (int x = 0; x < width; x++)
                        {
                            // Get Y, U, V values
                            int yIndex = y * width + x;
                            int uvIndex = (y / 2) * (width / 2) + (x / 2);
                            
                            int Y = yuvData[yIndex];
                            int U = yuvData[ySize + uvIndex];
                            int V = yuvData[ySize + uvSize + uvIndex];
                            
                            // YUV to RGB conversion (ITU-R BT.601)
                            int C = Y - 16;
                            int D = U - 128;
                            int E = V - 128;
                            
                            int R = (298 * C + 409 * E + 128) >> 8;
                            int G = (298 * C - 100 * D - 208 * E + 128) >> 8;
                            int B = (298 * C + 516 * D + 128) >> 8;
                            
                            // Clamp values to 0-255
                            R = Math.Max(0, Math.Min(255, R));
                            G = Math.Max(0, Math.Min(255, G));
                            B = Math.Max(0, Math.Min(255, B));
                            
                            // Set RGB pixel (BGR format for bitmap)
                            byte* pixel = rgbPtr + y * stride + x * 3;
                            pixel[0] = (byte)B; // Blue
                            pixel[1] = (byte)G; // Green  
                            pixel[2] = (byte)R; // Red
                        }
                    }
                }
                
                bitmap.UnlockBits(bitmapData);
                return bitmap;
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"YUV conversion failed: {ex.Message}");
                return CreateErrorBitmap(width, height, "YUV Conversion Error");
            }
        }
        
        private Bitmap CreateErrorBitmap(int width, int height, string message)
        {
            var errorBitmap = new Bitmap(Math.Max(320, width), Math.Max(240, height));
            using (var g = Graphics.FromImage(errorBitmap))
            {
                g.FillRectangle(DrawingBrushes.Red, 0, 0, errorBitmap.Width, errorBitmap.Height);
                g.DrawString(message, new Font("Arial", 12), DrawingBrushes.White, new PointF(10, 10));
            }
            return errorBitmap;
        }

        private BitmapSource CreateErrorBitmapSource(int width, int height, string message)
        {
            try
            {
                var writeableBitmap = new WriteableBitmap(width, height, 96, 96, PixelFormats.Bgr24, null);
                writeableBitmap.Lock();
                
                unsafe
                {
                    var backBuffer = (byte*)writeableBitmap.BackBuffer;
                    int stride = writeableBitmap.BackBufferStride;
                    
                    for (int y = 0; y < height; y++)
                    {
                        for (int x = 0; x < width; x++)
                        {
                            byte* pixel = backBuffer + y * stride + x * 3;
                            pixel[0] = 0;   // Blue
                            pixel[1] = 0;   // Green
                            pixel[2] = 255; // Red
                        }
                    }
                }
                
                writeableBitmap.AddDirtyRect(new System.Windows.Int32Rect(0, 0, width, height));
                writeableBitmap.Unlock();
                writeableBitmap.Freeze();
                
                return writeableBitmap;
            }
            catch
            {
                return null;
            }
        }

        public void Cleanup()
        {
            try
            {
                if (_isInSession)
                {
                    LeaveSession();
                }

                if (_sdkManager != null)
                {
                    _sdkManager.Cleanup();
                    _sdkManager = null;
                }

                _isInitialized = false;
                StatusChanged?.Invoke(this, "SDK cleaned up successfully via C++/CLI wrapper");
            }
            catch (Exception ex)
            {
                StatusChanged?.Invoke(this, $"Cleanup failed: {ex.Message}");
            }
        }

        // Dispose pattern
        public void Dispose()
        {
            Cleanup();
        }
    }
}
