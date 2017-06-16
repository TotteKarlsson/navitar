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
    object HomeZoomBtn: TButton
      Left = 22
      Top = 281
      Width = 91
      Height = 41
      Caption = 'Home'
      TabOrder = 0
    end
    object LimitBtn: TButton
      Left = 22
      Top = 17
      Width = 91
      Height = 41
      Caption = 'Limit'
      TabOrder = 1
      OnClick = ButtonClick
    end
    object CurrentPosition: TIntegerLabeledEdit
      Left = 176
      Top = 37
      Width = 121
      Height = 21
      EditLabel.Width = 77
      EditLabel.Height = 13
      EditLabel.Caption = 'Current Position'
      TabOrder = 2
      Text = '0'
    end
    object TrackBar1: TTrackBar
      Left = 30
      Top = 64
      Width = 45
      Height = 211
      Orientation = trVertical
      TabOrder = 3
    end
  end
  object MotorPositionTimer: TTimer
    Enabled = False
    Interval = 100
    Left = 296
    Top = 128
  end
end
