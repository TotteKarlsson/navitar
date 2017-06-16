object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'AT Navitar Control'
  ClientHeight = 663
  ClientWidth = 1044
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
    Top = 512
    Width = 1044
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitLeft = -32
    ExplicitTop = 424
    ExplicitWidth = 929
  end
  object TopPanel: TPanel
    Left = 313
    Top = 0
    Width = 731
    Height = 512
    Align = alClient
    TabOrder = 0
    inline TNavitarMotorFrame1: TNavitarMotorFrame
      Left = 1
      Top = 1
      Width = 729
      Height = 144
      Align = alTop
      TabOrder = 0
      ExplicitLeft = 1
      ExplicitTop = 1
      ExplicitWidth = 729
      ExplicitHeight = 144
      inherited MotorGB: TGroupBox
        Width = 729
        Height = 144
        ExplicitWidth = 729
        ExplicitHeight = 144
      end
    end
    inline TNavitarMotorFrame2: TNavitarMotorFrame
      Left = 1
      Top = 145
      Width = 729
      Height = 136
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 1
      ExplicitTop = 145
      ExplicitWidth = 729
      ExplicitHeight = 136
      inherited MotorGB: TGroupBox
        Width = 729
        Height = 136
        ExplicitWidth = 729
        ExplicitHeight = 136
      end
    end
    inline TPresetsFrame1: TPresetsFrame
      Left = 1
      Top = 281
      Width = 729
      Height = 230
      Align = alClient
      TabOrder = 2
      ExplicitLeft = 1
      ExplicitTop = 281
      ExplicitWidth = 729
      ExplicitHeight = 230
      inherited GroupBox1: TGroupBox
        Width = 729
        Height = 230
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 729
        ExplicitHeight = 230
        inherited TNavitarPreset1: TNavitarPreset
          Width = 725
          ExplicitLeft = 2
          ExplicitTop = 81
          ExplicitWidth = 725
          inherited GroupBox1: TGroupBox
            Width = 725
            ExplicitWidth = 725
          end
        end
        inherited NavitarPreset1: TNavitarPreset
          Width = 725
          ExplicitLeft = 2
          ExplicitTop = 15
          ExplicitWidth = 725
          inherited GroupBox1: TGroupBox
            Width = 725
            ExplicitWidth = 725
          end
        end
        inherited NavitarPreset2: TNavitarPreset
          Width = 725
          ExplicitLeft = 2
          ExplicitTop = 147
          ExplicitWidth = 725
          inherited GroupBox1: TGroupBox
            Width = 725
            ExplicitWidth = 725
          end
        end
      end
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 515
    Width = 1044
    Height = 148
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      1044
      148)
    object Splitter2: TSplitter
      Left = 1040
      Top = 1
      Height = 146
      Align = alRight
      ExplicitLeft = 881
      ExplicitTop = 9
      ExplicitHeight = 243
    end
    object mInfoMemo: TMemo
      Left = 1
      Top = 1
      Width = 1039
      Height = 146
      Align = alClient
      Lines.Strings = (
        'Memo1')
      TabOrder = 0
    end
    object Button1: TButton
      Left = 925
      Top = 20
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Clear'
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object LeftPanel: TGroupBox
    Left = 0
    Top = 0
    Width = 313
    Height = 512
    Align = alLeft
    Caption = 'Misc.'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 2
    object ConnectBtn: TButton
      Left = 20
      Top = 24
      Width = 153
      Height = 57
      Caption = 'Connect'
      TabOrder = 0
      OnClick = ButtonClick
    end
    object ControllerInfoGB: TGroupBox
      Left = 2
      Top = 395
      Width = 309
      Height = 115
      Align = alBottom
      Caption = 'Controller Info'
      TabOrder = 1
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
