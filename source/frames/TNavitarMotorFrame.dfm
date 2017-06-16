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
      Left = 273
      Top = 195
      Width = 10
      Height = 13
      Caption = '-1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Value = -1
      TheFont.Charset = DEFAULT_CHARSET
      TheFont.Color = clWindowText
      TheFont.Height = -11
      TheFont.Name = 'Tahoma'
      TheFont.Style = []
    end
    object Label1: TLabel
      Left = 223
      Top = 195
      Width = 44
      Height = 13
      Caption = 'Max Pos.'
    end
    object MotorPosition: TIntegerLabeledEdit
      Left = 135
      Top = 175
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
      OnKeyDown = MotorPositionKeyDown
    end
    object PositionTB: TTrackBar
      Left = 103
      Top = 127
      Width = 145
      Height = 25
      ShowSelRange = False
      TabOrder = 1
      TickStyle = tsNone
    end
    object HomeBtn: TButton
      Left = 14
      Top = 127
      Width = 75
      Height = 35
      Caption = 'Home'
      TabOrder = 2
      OnClick = FrameBtnClick
    end
    object LimitBtn: TButton
      Left = 263
      Top = 127
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
