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
    object MotorPosition: TIntegerLabeledEdit
      Left = 176
      Top = 37
      Width = 121
      Height = 21
      EditLabel.Width = 77
      EditLabel.Height = 13
      EditLabel.Caption = 'Current Position'
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
    Left = 296
    Top = 128
  end
end
