object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'AT Navitar Control'
  ClientHeight = 708
  ClientWidth = 1026
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
    Top = 460
    Width = 1026
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitLeft = -32
    ExplicitTop = 424
    ExplicitWidth = 929
  end
  object TopPanel: TPanel
    Left = 257
    Top = 0
    Width = 769
    Height = 460
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 191
    ExplicitWidth = 818
    inline TNavitarMotorFrame1: TNavitarMotorFrame
      Left = 415
      Top = 1
      Width = 353
      Height = 458
      Align = alRight
      TabOrder = 0
      ExplicitLeft = 585
      ExplicitTop = 1
      ExplicitWidth = 353
      ExplicitHeight = 350
      inherited MotorGB: TGroupBox
        Width = 353
        Height = 458
      end
    end
    inline TNavitarMotorFrame2: TNavitarMotorFrame
      Left = 1
      Top = 1
      Width = 414
      Height = 458
      Align = alClient
      TabOrder = 1
      ExplicitLeft = 197
      ExplicitTop = 1
      ExplicitWidth = 388
      ExplicitHeight = 350
      inherited MotorGB: TGroupBox
        Width = 414
        Height = 458
      end
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 463
    Width = 1026
    Height = 245
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 355
    ExplicitWidth = 939
    DesignSize = (
      1026
      245)
    object Splitter2: TSplitter
      Left = 444
      Top = 1
      Height = 243
      Align = alRight
      ExplicitLeft = 881
      ExplicitTop = 9
    end
    object mInfoMemo: TMemo
      Left = 1
      Top = 1
      Width = 443
      Height = 243
      Align = alClient
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
      ExplicitWidth = 592
    end
    object InfoPanel: TPanel
      Left = 447
      Top = 1
      Width = 578
      Height = 243
      Align = alRight
      TabOrder = 1
      ExplicitLeft = 360
      inline TPresetsFrame1: TPresetsFrame
        Left = 1
        Top = 1
        Width = 576
        Height = 241
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 104
        ExplicitTop = 48
        inherited GroupBox1: TGroupBox
          Width = 576
          Height = 241
          inherited TNavitarPreset1: TNavitarPreset
            Width = 572
            ExplicitLeft = 2
            ExplicitTop = 81
            ExplicitWidth = 572
            inherited GroupBox1: TGroupBox
              Width = 572
              ExplicitWidth = 572
            end
          end
          inherited NavitarPreset1: TNavitarPreset
            Width = 572
            ExplicitLeft = 2
            ExplicitTop = 15
            ExplicitWidth = 572
            inherited GroupBox1: TGroupBox
              Width = 572
              ExplicitWidth = 572
            end
          end
          inherited NavitarPreset2: TNavitarPreset
            Width = 572
            ExplicitLeft = 2
            ExplicitTop = 147
            ExplicitWidth = 572
            inherited GroupBox1: TGroupBox
              Width = 572
              ExplicitWidth = 572
            end
          end
        end
      end
    end
    object Button1: TButton
      Left = 339
      Top = 20
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Clear'
      TabOrder = 2
      OnClick = Button1Click
      ExplicitLeft = 322
    end
  end
  object LeftPanel: TGroupBox
    Left = 0
    Top = 0
    Width = 257
    Height = 460
    Align = alLeft
    Caption = 'Misc.'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 2
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
      Left = 2
      Top = 343
      Width = 253
      Height = 115
      Align = alBottom
      Caption = 'Controller Info'
      TabOrder = 1
      ExplicitLeft = 1
      ExplicitTop = 344
      ExplicitWidth = 255
      object Label1: TLabel
        Left = 16
        Top = 24
        Width = 55
        Height = 13
        Caption = 'Product ID:'
        Transparent = True
      end
      object Label2: TLabel
        Left = 16
        Top = 45
        Width = 89
        Height = 13
        Caption = 'Hardware Version:'
        Transparent = True
      end
      object Label3: TLabel
        Left = 16
        Top = 66
        Width = 82
        Height = 13
        Caption = 'Software Version'
        Transparent = True
      end
      object Label4: TLabel
        Left = 16
        Top = 85
        Width = 74
        Height = 13
        Caption = 'Firmware Date:'
        Transparent = True
      end
      object ProdIdLbl: TLabel
        Left = 120
        Top = 22
        Width = 18
        Height = 13
        Caption = 'N/A'
        Transparent = True
      end
      object HWVerLbl: TLabel
        Left = 120
        Top = 43
        Width = 18
        Height = 13
        Caption = 'N/A'
        Transparent = True
      end
      object SWVerLbl: TLabel
        Left = 120
        Top = 64
        Width = 18
        Height = 13
        Caption = 'N/A'
        Transparent = True
      end
      object FirmWareDateLbl: TLabel
        Left = 120
        Top = 85
        Width = 18
        Height = 13
        Caption = 'N/A'
        Transparent = True
      end
    end
  end
  object mShutDownTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = mShutDownTimerTimer
    Left = 904
    Top = 80
  end
end
