object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'AT Navitar Control'
  ClientHeight = 665
  ClientWidth = 962
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 423
    Width = 962
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitLeft = 73
    ExplicitTop = 414
    ExplicitWidth = 865
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 962
    Height = 423
    Align = alTop
    TabOrder = 0
    object ConnectBtn: TButton
      Left = 32
      Top = 36
      Width = 153
      Height = 57
      Caption = 'Connect'
      TabOrder = 0
      OnClick = ButtonClick
    end
    object ZoomGB: TGroupBox
      Left = 200
      Top = 36
      Width = 361
      Height = 341
      Caption = 'ZoomGB'
      TabOrder = 1
      object HomeZoomBtn: TButton
        Left = 22
        Top = 281
        Width = 91
        Height = 41
        Caption = 'Home'
        TabOrder = 0
        OnClick = ButtonClick
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
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 420
    Width = 962
    Height = 245
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      962
      245)
    object Splitter2: TSplitter
      Left = 717
      Top = 1
      Height = 243
      Align = alRight
      ExplicitLeft = 881
      ExplicitTop = 9
    end
    object mInfoMemo: TMemo
      Left = 1
      Top = 1
      Width = 716
      Height = 243
      Align = alClient
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
    end
    object InfoPanel: TPanel
      Left = 720
      Top = 1
      Width = 241
      Height = 243
      Align = alRight
      TabOrder = 1
      object ControllerInfoGB: TGroupBox
        Left = 1
        Top = 1
        Width = 239
        Height = 241
        Align = alClient
        Caption = 'Controller Info'
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 24
          Width = 55
          Height = 13
          Caption = 'Product ID:'
        end
        object Label2: TLabel
          Left = 16
          Top = 45
          Width = 89
          Height = 13
          Caption = 'Hardware Version:'
        end
        object Label3: TLabel
          Left = 16
          Top = 66
          Width = 82
          Height = 13
          Caption = 'Software Version'
        end
        object Label4: TLabel
          Left = 16
          Top = 85
          Width = 74
          Height = 13
          Caption = 'Firmware Date:'
        end
        object ProdIdLbl: TLabel
          Left = 120
          Top = 22
          Width = 18
          Height = 13
          Caption = 'N/A'
        end
        object HWVerLbl: TLabel
          Left = 120
          Top = 43
          Width = 18
          Height = 13
          Caption = 'N/A'
        end
        object SWVerLbl: TLabel
          Left = 120
          Top = 64
          Width = 18
          Height = 13
          Caption = 'N/A'
        end
        object FirmWareDateLbl: TLabel
          Left = 120
          Top = 85
          Width = 18
          Height = 13
          Caption = 'N/A'
        end
      end
    end
    object Button1: TButton
      Left = 622
      Top = 12
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Clear'
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object mShutDownTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = mShutDownTimerTimer
    Left = 608
    Top = 120
  end
end
