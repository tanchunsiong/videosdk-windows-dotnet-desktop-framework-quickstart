namespace ZoomVideoSDK.WinForms
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.mainTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.controlsPanel = new System.Windows.Forms.TableLayoutPanel();
            this._sessionGroup = new System.Windows.Forms.GroupBox();
            this.sessionTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.sessionNameLabel = new System.Windows.Forms.Label();
            this._sessionNameTextBox = new System.Windows.Forms.TextBox();
            this.tokenLabel = new System.Windows.Forms.Label();
            this._tokenTextBox = new System.Windows.Forms.TextBox();
            this.userNameLabel = new System.Windows.Forms.Label();
            this._userNameTextBox = new System.Windows.Forms.TextBox();
            this.passwordLabel = new System.Windows.Forms.Label();
            this._passwordTextBox = new System.Windows.Forms.TextBox();
            this._audioGroup = new System.Windows.Forms.GroupBox();
            this.audioFlowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this._previewTokenButton = new System.Windows.Forms.Button();
            this._joinButton = new System.Windows.Forms.Button();
            this._leaveButton = new System.Windows.Forms.Button();
            this._muteMicButton = new System.Windows.Forms.Button();
            this._muteSpeakerButton = new System.Windows.Forms.Button();
            this._videoGroup = new System.Windows.Forms.GroupBox();
            this.videoFlowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this._startVideoButton = new System.Windows.Forms.Button();
            this._stopVideoButton = new System.Windows.Forms.Button();
            this._deviceGroup = new System.Windows.Forms.GroupBox();
            this.deviceTableLayoutPanel = new System.Windows.Forms.TableLayoutPanel();
            this.microphoneLabel = new System.Windows.Forms.Label();
            this._microphoneComboBox = new System.Windows.Forms.ComboBox();
            this.speakerLabel = new System.Windows.Forms.Label();
            this._speakerComboBox = new System.Windows.Forms.ComboBox();
            this.cameraLabel = new System.Windows.Forms.Label();
            this._cameraComboBox = new System.Windows.Forms.ComboBox();
            this.videoPanel = new System.Windows.Forms.TableLayoutPanel();
            this._selfVideoPanel = new System.Windows.Forms.PictureBox();
            this._remoteVideoPanel = new System.Windows.Forms.PictureBox();
            this._statusStrip = new System.Windows.Forms.StatusStrip();
            this._statusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.selfVideoLabel = new System.Windows.Forms.Label();
            this.remoteVideoLabel = new System.Windows.Forms.Label();
            this.mainTableLayoutPanel.SuspendLayout();
            this.controlsPanel.SuspendLayout();
            this._sessionGroup.SuspendLayout();
            this.sessionTableLayoutPanel.SuspendLayout();
            this._audioGroup.SuspendLayout();
            this.audioFlowLayoutPanel.SuspendLayout();
            this._videoGroup.SuspendLayout();
            this.videoFlowLayoutPanel.SuspendLayout();
            this._deviceGroup.SuspendLayout();
            this.deviceTableLayoutPanel.SuspendLayout();
            this.videoPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this._selfVideoPanel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._remoteVideoPanel)).BeginInit();
            this._statusStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainTableLayoutPanel
            // 
            this.mainTableLayoutPanel.ColumnCount = 2;
            this.mainTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 40F));
            this.mainTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 60F));
            this.mainTableLayoutPanel.Controls.Add(this.controlsPanel, 0, 0);
            this.mainTableLayoutPanel.Controls.Add(this.videoPanel, 1, 0);
            this.mainTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainTableLayoutPanel.Location = new System.Drawing.Point(0, 0);
            this.mainTableLayoutPanel.Name = "mainTableLayoutPanel";
            this.mainTableLayoutPanel.Padding = new System.Windows.Forms.Padding(10);
            this.mainTableLayoutPanel.RowCount = 1;
            this.mainTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.mainTableLayoutPanel.Size = new System.Drawing.Size(1000, 628);
            this.mainTableLayoutPanel.TabIndex = 0;
            // 
            // controlsPanel
            // 
            this.controlsPanel.ColumnCount = 1;
            this.controlsPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.controlsPanel.Controls.Add(this._sessionGroup, 0, 0);
            this.controlsPanel.Controls.Add(this._audioGroup, 0, 1);
            this.controlsPanel.Controls.Add(this._videoGroup, 0, 2);
            this.controlsPanel.Controls.Add(this._deviceGroup, 0, 3);
            this.controlsPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.controlsPanel.Location = new System.Drawing.Point(13, 13);
            this.controlsPanel.Name = "controlsPanel";
            this.controlsPanel.RowCount = 4;
            this.controlsPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 140F));
            this.controlsPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 120F));
            this.controlsPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 80F));
            this.controlsPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.controlsPanel.Size = new System.Drawing.Size(386, 602);
            this.controlsPanel.TabIndex = 0;
            // 
            // _sessionGroup
            // 
            this._sessionGroup.Controls.Add(this.sessionTableLayoutPanel);
            this._sessionGroup.Dock = System.Windows.Forms.DockStyle.Fill;
            this._sessionGroup.Location = new System.Drawing.Point(3, 3);
            this._sessionGroup.Name = "_sessionGroup";
            this._sessionGroup.Padding = new System.Windows.Forms.Padding(10);
            this._sessionGroup.Size = new System.Drawing.Size(380, 134);
            this._sessionGroup.TabIndex = 0;
            this._sessionGroup.TabStop = false;
            this._sessionGroup.Text = "Session Configuration";
            // 
            // sessionTableLayoutPanel
            // 
            this.sessionTableLayoutPanel.ColumnCount = 2;
            this.sessionTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 100F));
            this.sessionTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.sessionTableLayoutPanel.Controls.Add(this.sessionNameLabel, 0, 0);
            this.sessionTableLayoutPanel.Controls.Add(this._sessionNameTextBox, 1, 0);
            this.sessionTableLayoutPanel.Controls.Add(this.tokenLabel, 0, 1);
            this.sessionTableLayoutPanel.Controls.Add(this._tokenTextBox, 1, 1);
            this.sessionTableLayoutPanel.Controls.Add(this.userNameLabel, 0, 2);
            this.sessionTableLayoutPanel.Controls.Add(this._userNameTextBox, 1, 2);
            this.sessionTableLayoutPanel.Controls.Add(this.passwordLabel, 0, 3);
            this.sessionTableLayoutPanel.Controls.Add(this._passwordTextBox, 1, 3);
            this.sessionTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.sessionTableLayoutPanel.Location = new System.Drawing.Point(10, 23);
            this.sessionTableLayoutPanel.Name = "sessionTableLayoutPanel";
            this.sessionTableLayoutPanel.RowCount = 4;
            this.sessionTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.sessionTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.sessionTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.sessionTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.sessionTableLayoutPanel.Size = new System.Drawing.Size(360, 101);
            this.sessionTableLayoutPanel.TabIndex = 0;
            // 
            // sessionNameLabel
            // 
            this.sessionNameLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.sessionNameLabel.AutoSize = true;
            this.sessionNameLabel.Location = new System.Drawing.Point(3, 6);
            this.sessionNameLabel.Name = "sessionNameLabel";
            this.sessionNameLabel.Size = new System.Drawing.Size(47, 13);
            this.sessionNameLabel.TabIndex = 0;
            this.sessionNameLabel.Text = "Session:";
            // 
            // _sessionNameTextBox
            // 
            this._sessionNameTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._sessionNameTextBox.Location = new System.Drawing.Point(103, 3);
            this._sessionNameTextBox.Name = "_sessionNameTextBox";
            this._sessionNameTextBox.Size = new System.Drawing.Size(254, 20);
            this._sessionNameTextBox.TabIndex = 1;
            // 
            // tokenLabel
            // 
            this.tokenLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.tokenLabel.AutoSize = true;
            this.tokenLabel.Location = new System.Drawing.Point(3, 31);
            this.tokenLabel.Name = "tokenLabel";
            this.tokenLabel.Size = new System.Drawing.Size(41, 13);
            this.tokenLabel.TabIndex = 2;
            this.tokenLabel.Text = "Token:";
            // 
            // _tokenTextBox
            // 
            this._tokenTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._tokenTextBox.Location = new System.Drawing.Point(103, 28);
            this._tokenTextBox.Name = "_tokenTextBox";
            this._tokenTextBox.Size = new System.Drawing.Size(254, 20);
            this._tokenTextBox.TabIndex = 3;
            // 
            // userNameLabel
            // 
            this.userNameLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.userNameLabel.AutoSize = true;
            this.userNameLabel.Location = new System.Drawing.Point(3, 56);
            this.userNameLabel.Name = "userNameLabel";
            this.userNameLabel.Size = new System.Drawing.Size(32, 13);
            this.userNameLabel.TabIndex = 4;
            this.userNameLabel.Text = "User:";
            // 
            // _userNameTextBox
            // 
            this._userNameTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._userNameTextBox.Location = new System.Drawing.Point(103, 53);
            this._userNameTextBox.Name = "_userNameTextBox";
            this._userNameTextBox.Size = new System.Drawing.Size(254, 20);
            this._userNameTextBox.TabIndex = 5;
            // 
            // passwordLabel
            // 
            this.passwordLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.passwordLabel.AutoSize = true;
            this.passwordLabel.Location = new System.Drawing.Point(3, 81);
            this.passwordLabel.Name = "passwordLabel";
            this.passwordLabel.Size = new System.Drawing.Size(56, 13);
            this.passwordLabel.TabIndex = 6;
            this.passwordLabel.Text = "Password:";
            // 
            // _passwordTextBox
            // 
            this._passwordTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._passwordTextBox.Location = new System.Drawing.Point(103, 78);
            this._passwordTextBox.Name = "_passwordTextBox";
            this._passwordTextBox.Size = new System.Drawing.Size(254, 20);
            this._passwordTextBox.TabIndex = 7;
            this._passwordTextBox.UseSystemPasswordChar = true;
            // 
            // _audioGroup
            // 
            this._audioGroup.Controls.Add(this.audioFlowLayoutPanel);
            this._audioGroup.Dock = System.Windows.Forms.DockStyle.Fill;
            this._audioGroup.Location = new System.Drawing.Point(3, 143);
            this._audioGroup.Name = "_audioGroup";
            this._audioGroup.Padding = new System.Windows.Forms.Padding(10);
            this._audioGroup.Size = new System.Drawing.Size(380, 114);
            this._audioGroup.TabIndex = 1;
            this._audioGroup.TabStop = false;
            this._audioGroup.Text = "Session & Audio Controls";
            // 
            // audioFlowLayoutPanel
            // 
            this.audioFlowLayoutPanel.Controls.Add(this._previewTokenButton);
            this.audioFlowLayoutPanel.Controls.Add(this._joinButton);
            this.audioFlowLayoutPanel.Controls.Add(this._leaveButton);
            this.audioFlowLayoutPanel.Controls.Add(this._muteMicButton);
            this.audioFlowLayoutPanel.Controls.Add(this._muteSpeakerButton);
            this.audioFlowLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.audioFlowLayoutPanel.Location = new System.Drawing.Point(10, 23);
            this.audioFlowLayoutPanel.Name = "audioFlowLayoutPanel";
            this.audioFlowLayoutPanel.Size = new System.Drawing.Size(360, 81);
            this.audioFlowLayoutPanel.TabIndex = 0;
            // 
            // _previewTokenButton
            // 
            this._previewTokenButton.BackColor = System.Drawing.Color.Blue;
            this._previewTokenButton.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._previewTokenButton.ForeColor = System.Drawing.Color.White;
            this._previewTokenButton.Location = new System.Drawing.Point(3, 3);
            this._previewTokenButton.Name = "_previewTokenButton";
            this._previewTokenButton.Size = new System.Drawing.Size(120, 35);
            this._previewTokenButton.TabIndex = 0;
            this._previewTokenButton.Text = "PREVIEW TOKEN";
            this._previewTokenButton.UseVisualStyleBackColor = false;
            this._previewTokenButton.Click += new System.EventHandler(this.PreviewTokenButton_Click);
            // 
            // _joinButton
            // 
            this._joinButton.BackColor = System.Drawing.Color.Green;
            this._joinButton.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._joinButton.ForeColor = System.Drawing.Color.White;
            this._joinButton.Location = new System.Drawing.Point(129, 3);
            this._joinButton.Name = "_joinButton";
            this._joinButton.Size = new System.Drawing.Size(120, 35);
            this._joinButton.TabIndex = 1;
            this._joinButton.Text = "JOIN SESSION";
            this._joinButton.UseVisualStyleBackColor = false;
            this._joinButton.Click += new System.EventHandler(this.JoinButton_Click);
            // 
            // _leaveButton
            // 
            this._leaveButton.BackColor = System.Drawing.Color.Red;
            this._leaveButton.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._leaveButton.ForeColor = System.Drawing.Color.White;
            this._leaveButton.Location = new System.Drawing.Point(3, 44);
            this._leaveButton.Name = "_leaveButton";
            this._leaveButton.Size = new System.Drawing.Size(120, 35);
            this._leaveButton.TabIndex = 2;
            this._leaveButton.Text = "LEAVE SESSION";
            this._leaveButton.UseVisualStyleBackColor = false;
            this._leaveButton.Click += new System.EventHandler(this.LeaveButton_Click);
            // 
            // _muteMicButton
            // 
            this._muteMicButton.Location = new System.Drawing.Point(129, 44);
            this._muteMicButton.Name = "_muteMicButton";
            this._muteMicButton.Size = new System.Drawing.Size(100, 30);
            this._muteMicButton.TabIndex = 3;
            this._muteMicButton.Text = "Mute Mic";
            this._muteMicButton.UseVisualStyleBackColor = true;
            this._muteMicButton.Click += new System.EventHandler(this.MuteMicButton_Click);
            // 
            // _muteSpeakerButton
            // 
            this._muteSpeakerButton.Location = new System.Drawing.Point(235, 44);
            this._muteSpeakerButton.Name = "_muteSpeakerButton";
            this._muteSpeakerButton.Size = new System.Drawing.Size(100, 30);
            this._muteSpeakerButton.TabIndex = 4;
            this._muteSpeakerButton.Text = "Mute Speaker";
            this._muteSpeakerButton.UseVisualStyleBackColor = true;
            this._muteSpeakerButton.Click += new System.EventHandler(this.MuteSpeakerButton_Click);
            // 
            // _videoGroup
            // 
            this._videoGroup.Controls.Add(this.videoFlowLayoutPanel);
            this._videoGroup.Dock = System.Windows.Forms.DockStyle.Fill;
            this._videoGroup.Location = new System.Drawing.Point(3, 263);
            this._videoGroup.Name = "_videoGroup";
            this._videoGroup.Padding = new System.Windows.Forms.Padding(10);
            this._videoGroup.Size = new System.Drawing.Size(380, 74);
            this._videoGroup.TabIndex = 2;
            this._videoGroup.TabStop = false;
            this._videoGroup.Text = "Video Controls";
            // 
            // videoFlowLayoutPanel
            // 
            this.videoFlowLayoutPanel.Controls.Add(this._startVideoButton);
            this.videoFlowLayoutPanel.Controls.Add(this._stopVideoButton);
            this.videoFlowLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.videoFlowLayoutPanel.Location = new System.Drawing.Point(10, 23);
            this.videoFlowLayoutPanel.Name = "videoFlowLayoutPanel";
            this.videoFlowLayoutPanel.Size = new System.Drawing.Size(360, 41);
            this.videoFlowLayoutPanel.TabIndex = 0;
            // 
            // _startVideoButton
            // 
            this._startVideoButton.Location = new System.Drawing.Point(3, 3);
            this._startVideoButton.Name = "_startVideoButton";
            this._startVideoButton.Size = new System.Drawing.Size(100, 30);
            this._startVideoButton.TabIndex = 0;
            this._startVideoButton.Text = "Start Video";
            this._startVideoButton.UseVisualStyleBackColor = true;
            this._startVideoButton.Click += new System.EventHandler(this.StartVideoButton_Click);
            // 
            // _stopVideoButton
            // 
            this._stopVideoButton.Location = new System.Drawing.Point(109, 3);
            this._stopVideoButton.Name = "_stopVideoButton";
            this._stopVideoButton.Size = new System.Drawing.Size(100, 30);
            this._stopVideoButton.TabIndex = 1;
            this._stopVideoButton.Text = "Stop Video";
            this._stopVideoButton.UseVisualStyleBackColor = true;
            this._stopVideoButton.Click += new System.EventHandler(this.StopVideoButton_Click);
            // 
            // _deviceGroup
            // 
            this._deviceGroup.Controls.Add(this.deviceTableLayoutPanel);
            this._deviceGroup.Dock = System.Windows.Forms.DockStyle.Fill;
            this._deviceGroup.Location = new System.Drawing.Point(3, 343);
            this._deviceGroup.Name = "_deviceGroup";
            this._deviceGroup.Padding = new System.Windows.Forms.Padding(10);
            this._deviceGroup.Size = new System.Drawing.Size(380, 256);
            this._deviceGroup.TabIndex = 3;
            this._deviceGroup.TabStop = false;
            this._deviceGroup.Text = "Device Selection";
            // 
            // deviceTableLayoutPanel
            // 
            this.deviceTableLayoutPanel.ColumnCount = 2;
            this.deviceTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 100F));
            this.deviceTableLayoutPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.deviceTableLayoutPanel.Controls.Add(this.microphoneLabel, 0, 0);
            this.deviceTableLayoutPanel.Controls.Add(this._microphoneComboBox, 1, 0);
            this.deviceTableLayoutPanel.Controls.Add(this.speakerLabel, 0, 1);
            this.deviceTableLayoutPanel.Controls.Add(this._speakerComboBox, 1, 1);
            this.deviceTableLayoutPanel.Controls.Add(this.cameraLabel, 0, 2);
            this.deviceTableLayoutPanel.Controls.Add(this._cameraComboBox, 1, 2);
            this.deviceTableLayoutPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.deviceTableLayoutPanel.Location = new System.Drawing.Point(10, 23);
            this.deviceTableLayoutPanel.Name = "deviceTableLayoutPanel";
            this.deviceTableLayoutPanel.RowCount = 3;
            this.deviceTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.deviceTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.deviceTableLayoutPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.deviceTableLayoutPanel.Size = new System.Drawing.Size(360, 223);
            this.deviceTableLayoutPanel.TabIndex = 0;
            // 
            // microphoneLabel
            // 
            this.microphoneLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.microphoneLabel.AutoSize = true;
            this.microphoneLabel.Location = new System.Drawing.Point(3, 8);
            this.microphoneLabel.Name = "microphoneLabel";
            this.microphoneLabel.Size = new System.Drawing.Size(66, 13);
            this.microphoneLabel.TabIndex = 0;
            this.microphoneLabel.Text = "Microphone:";
            // 
            // _microphoneComboBox
            // 
            this._microphoneComboBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._microphoneComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this._microphoneComboBox.FormattingEnabled = true;
            this._microphoneComboBox.Location = new System.Drawing.Point(103, 4);
            this._microphoneComboBox.Name = "_microphoneComboBox";
            this._microphoneComboBox.Size = new System.Drawing.Size(254, 21);
            this._microphoneComboBox.TabIndex = 1;
            // 
            // speakerLabel
            // 
            this.speakerLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.speakerLabel.AutoSize = true;
            this.speakerLabel.Location = new System.Drawing.Point(3, 38);
            this.speakerLabel.Name = "speakerLabel";
            this.speakerLabel.Size = new System.Drawing.Size(50, 13);
            this.speakerLabel.TabIndex = 2;
            this.speakerLabel.Text = "Speaker:";
            // 
            // _speakerComboBox
            // 
            this._speakerComboBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._speakerComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this._speakerComboBox.FormattingEnabled = true;
            this._speakerComboBox.Location = new System.Drawing.Point(103, 34);
            this._speakerComboBox.Name = "_speakerComboBox";
            this._speakerComboBox.Size = new System.Drawing.Size(254, 21);
            this._speakerComboBox.TabIndex = 3;
            // 
            // cameraLabel
            // 
            this.cameraLabel.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.cameraLabel.AutoSize = true;
            this.cameraLabel.Location = new System.Drawing.Point(3, 135);
            this.cameraLabel.Name = "cameraLabel";
            this.cameraLabel.Size = new System.Drawing.Size(46, 13);
            this.cameraLabel.TabIndex = 4;
            this.cameraLabel.Text = "Camera:";
            // 
            // _cameraComboBox
            // 
            this._cameraComboBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this._cameraComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this._cameraComboBox.FormattingEnabled = true;
            this._cameraComboBox.Location = new System.Drawing.Point(103, 131);
            this._cameraComboBox.Name = "_cameraComboBox";
            this._cameraComboBox.Size = new System.Drawing.Size(254, 21);
            this._cameraComboBox.TabIndex = 5;
            // 
            // videoPanel
            // 
            this.videoPanel.ColumnCount = 1;
            this.videoPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.videoPanel.Controls.Add(this._selfVideoPanel, 0, 0);
            this.videoPanel.Controls.Add(this._remoteVideoPanel, 0, 1);
            this.videoPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.videoPanel.Location = new System.Drawing.Point(405, 13);
            this.videoPanel.Name = "videoPanel";
            this.videoPanel.RowCount = 2;
            this.videoPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.videoPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.videoPanel.Size = new System.Drawing.Size(582, 602);
            this.videoPanel.TabIndex = 1;
            // 
            // _selfVideoPanel
            // 
            this._selfVideoPanel.BackColor = System.Drawing.Color.Black;
            this._selfVideoPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this._selfVideoPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this._selfVideoPanel.Location = new System.Drawing.Point(3, 3);
            this._selfVideoPanel.Name = "_selfVideoPanel";
            this._selfVideoPanel.Size = new System.Drawing.Size(576, 295);
            this._selfVideoPanel.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this._selfVideoPanel.TabIndex = 0;
            this._selfVideoPanel.TabStop = false;
            // 
            // _remoteVideoPanel
            // 
            this._remoteVideoPanel.BackColor = System.Drawing.Color.Black;
            this._remoteVideoPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this._remoteVideoPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this._remoteVideoPanel.Location = new System.Drawing.Point(3, 304);
            this._remoteVideoPanel.Name = "_remoteVideoPanel";
            this._remoteVideoPanel.Size = new System.Drawing.Size(576, 295);
            this._remoteVideoPanel.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this._remoteVideoPanel.TabIndex = 1;
            this._remoteVideoPanel.TabStop = false;
            // 
            // _statusStrip
            // 
            this._statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._statusLabel});
            this._statusStrip.Location = new System.Drawing.Point(0, 628);
            this._statusStrip.Name = "_statusStrip";
            this._statusStrip.Size = new System.Drawing.Size(1000, 22);
            this._statusStrip.TabIndex = 1;
            this._statusStrip.Text = "statusStrip1";
            // 
            // _statusLabel
            // 
            this._statusLabel.Name = "_statusLabel";
            this._statusLabel.Size = new System.Drawing.Size(39, 17);
            this._statusLabel.Text = "Ready";
            // 
            // selfVideoLabel
            // 
            this.selfVideoLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.selfVideoLabel.AutoSize = true;
            this.selfVideoLabel.BackColor = System.Drawing.Color.Transparent;
            this.selfVideoLabel.ForeColor = System.Drawing.Color.White;
            this.selfVideoLabel.Location = new System.Drawing.Point(261, 146);
            this.selfVideoLabel.Name = "selfVideoLabel";
            this.selfVideoLabel.Size = new System.Drawing.Size(57, 13);
            this.selfVideoLabel.TabIndex = 0;
            this.selfVideoLabel.Text = "Self Video";
            this.selfVideoLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // remoteVideoLabel
            // 
            this.remoteVideoLabel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.remoteVideoLabel.AutoSize = true;
            this.remoteVideoLabel.BackColor = System.Drawing.Color.Transparent;
            this.remoteVideoLabel.ForeColor = System.Drawing.Color.White;
            this.remoteVideoLabel.Location = new System.Drawing.Point(253, 458);
            this.remoteVideoLabel.Name = "remoteVideoLabel";
            this.remoteVideoLabel.Size = new System.Drawing.Size(73, 13);
            this.remoteVideoLabel.TabIndex = 0;
            this.remoteVideoLabel.Text = "Remote Video";
            this.remoteVideoLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1000, 650);
            this.Controls.Add(this.mainTableLayoutPanel);
            this.Controls.Add(this._statusStrip);
            this.Name = "MainForm";
            this.Text = "Zoom Video SDK Demo";
            this.mainTableLayoutPanel.ResumeLayout(false);
            this.controlsPanel.ResumeLayout(false);
            this._sessionGroup.ResumeLayout(false);
            this.sessionTableLayoutPanel.ResumeLayout(false);
            this.sessionTableLayoutPanel.PerformLayout();
            this._audioGroup.ResumeLayout(false);
            this.audioFlowLayoutPanel.ResumeLayout(false);
            this._videoGroup.ResumeLayout(false);
            this.videoFlowLayoutPanel.ResumeLayout(false);
            this._deviceGroup.ResumeLayout(false);
            this.deviceTableLayoutPanel.ResumeLayout(false);
            this.deviceTableLayoutPanel.PerformLayout();
            this.videoPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this._selfVideoPanel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._remoteVideoPanel)).EndInit();
            this._statusStrip.ResumeLayout(false);
            this._statusStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel mainTableLayoutPanel;
        private System.Windows.Forms.TableLayoutPanel controlsPanel;
        private System.Windows.Forms.GroupBox _sessionGroup;
        private System.Windows.Forms.TableLayoutPanel sessionTableLayoutPanel;
        private System.Windows.Forms.Label sessionNameLabel;
        private System.Windows.Forms.TextBox _sessionNameTextBox;
        private System.Windows.Forms.Label tokenLabel;
        private System.Windows.Forms.TextBox _tokenTextBox;
        private System.Windows.Forms.Label userNameLabel;
        private System.Windows.Forms.TextBox _userNameTextBox;
        private System.Windows.Forms.Label passwordLabel;
        private System.Windows.Forms.TextBox _passwordTextBox;
        private System.Windows.Forms.GroupBox _audioGroup;
        private System.Windows.Forms.FlowLayoutPanel audioFlowLayoutPanel;
        private System.Windows.Forms.Button _previewTokenButton;
        private System.Windows.Forms.Button _joinButton;
        private System.Windows.Forms.Button _leaveButton;
        private System.Windows.Forms.Button _muteMicButton;
        private System.Windows.Forms.Button _muteSpeakerButton;
        private System.Windows.Forms.GroupBox _videoGroup;
        private System.Windows.Forms.FlowLayoutPanel videoFlowLayoutPanel;
        private System.Windows.Forms.Button _startVideoButton;
        private System.Windows.Forms.Button _stopVideoButton;
        private System.Windows.Forms.GroupBox _deviceGroup;
        private System.Windows.Forms.TableLayoutPanel deviceTableLayoutPanel;
        private System.Windows.Forms.Label microphoneLabel;
        private System.Windows.Forms.ComboBox _microphoneComboBox;
        private System.Windows.Forms.Label speakerLabel;
        private System.Windows.Forms.ComboBox _speakerComboBox;
        private System.Windows.Forms.Label cameraLabel;
        private System.Windows.Forms.ComboBox _cameraComboBox;
        private System.Windows.Forms.TableLayoutPanel videoPanel;
        private System.Windows.Forms.PictureBox _selfVideoPanel;
        private System.Windows.Forms.PictureBox _remoteVideoPanel;
        private System.Windows.Forms.StatusStrip _statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel _statusLabel;
        private System.Windows.Forms.Label selfVideoLabel;
        private System.Windows.Forms.Label remoteVideoLabel;
    }
}
