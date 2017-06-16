object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'AT Navitar Control'
  ClientHeight = 600
  ClientWidth = 939
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
    Top = 352
    Width = 939
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitLeft = -32
    ExplicitTop = 424
    ExplicitWidth = 929
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 939
    Height = 352
    Align = alClient
    TabOrder = 0
    inline TNavitarMotorFrame1: TNavitarMotorFrame
      Left = 585
      Top = 1
      Width = 353
      Height = 350
      Align = alRight
      TabOrder = 0
      ExplicitLeft = 585
      ExplicitTop = 1
      ExplicitWidth = 353
      ExplicitHeight = 350
      inherited MotorGB: TGroupBox
        Left = 0
        Top = 0
        Width = 353
        Height = 350
        Align = alClient
        ExplicitLeft = 25
        ExplicitTop = 35
        ExplicitWidth = 353
        ExplicitHeight = 350
      end
    end
    object LeftPanel: TPanel
      Left = 1
      Top = 1
      Width = 185
      Height = 350
      Align = alLeft
      BevelInner = bvLowered
      BevelOuter = bvNone
      TabOrder = 1
      ExplicitLeft = 64
      ExplicitTop = 208
      ExplicitHeight = 41
      object ConnectBtn: TButton
        Left = 16
        Top = 35
        Width = 153
        Height = 57
        Caption = 'Connect'
        TabOrder = 0
        OnClick = ButtonClick
      end
      object ControllerInfoGB: TGroupBox
        Left = 1
        Top = 234
        Width = 183
        Height = 115
        Align = alBottom
        Caption = 'Controller Info'
        TabOrder = 1
        ExplicitTop = 408
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
    inline TNavitarMotorFrame2: TNavitarMotorFrame
      Left = 197
      Top = 1
      Width = 388
      Height = 350
      Align = alRight
      TabOrder = 2
      ExplicitLeft = 197
      ExplicitTop = 1
      ExplicitWidth = 388
      ExplicitHeight = 350
      inherited MotorGB: TGroupBox
        Left = 0
        Top = 0
        Width = 388
        Height = 350
        Align = alClient
        ExplicitLeft = 4
        ExplicitTop = 17
        ExplicitWidth = 388
        ExplicitHeight = 340
      end
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 355
    Width = 939
    Height = 245
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 420
    ExplicitWidth = 962
    DesignSize = (
      939
      245)
    object Splitter2: TSplitter
      Left = 694
      Top = 1
      Height = 243
      Align = alRight
      ExplicitLeft = 881
      ExplicitTop = 9
    end
    object mInfoMemo: TMemo
      Left = 1
      Top = 1
      Width = 693
      Height = 243
      Align = alClient
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
      ExplicitWidth = 716
    end
    object InfoPanel: TPanel
      Left = 697
      Top = 1
      Width = 241
      Height = 243
      Align = alRight
      TabOrder = 1
      ExplicitLeft = 911
      ExplicitTop = 5
    end
    object Button1: TButton
      Left = 599
      Top = 12
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Clear'
      TabOrder = 2
      OnClick = Button1Click
      ExplicitLeft = 622
    end
  end
  object mShutDownTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = mShutDownTimerTimer
    Left = 1016
    Top = 72
  end
end
