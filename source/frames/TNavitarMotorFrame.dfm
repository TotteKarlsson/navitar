object NavitarMotorFrame: TNavitarMotorFrame
  Left = 0
  Top = 0
  Width = 605
  Height = 471
  TabOrder = 0
  object MotorGB: TGroupBox
    Left = 32
    Top = 36
    Width = 361
    Height = 341
    Caption = 'UnitGB'
    TabOrder = 0
    object MaxPosLabel: TIntLabel
      Left = 224
      Top = 282
      Width = 33
      Height = 13
      Caption = '0'
      TheFont.Charset = DEFAULT_CHARSET
      TheFont.Color = clWindowText
      TheFont.Height = -11
      TheFont.Name = 'Tahoma'
      TheFont.Style = []
    end
    object Label1: TLabel
      Left = 127
      Top = 282
      Width = 91
      Height = 13
      Caption = 'Motor Max Position'
    end
    object MotorPosition: TIntegerLabeledEdit
      Left = 232
      Top = 47
      Width = 81
      Height = 33
      EditLabel.Width = 77
      EditLabel.Height = 13
      EditLabel.Caption = 'Current Position'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0'
    end
    object TrackBar1: TTrackBar
      Left = 30
      Top = 64
      Width = 45
      Height = 211
      Orientation = trVertical
      TabOrder = 1
    end
    object HomeBtn: TButton
      Left = 30
      Top = 272
      Width = 75
      Height = 35
      Caption = 'HomeBtn'
      TabOrder = 2
      OnClick = FrameBtnClick
    end
    object LimitBtn: TButton
      Left = 30
      Top = 33
      Width = 75
      Height = 35
      Caption = 'Limit'
      TabOrder = 3
      OnClick = FrameBtnClick
    end
  end
  object MotorPositionTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = MotorPositionTimerTimer
    Left = 48
    Top = 192
  end
end
