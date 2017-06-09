object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Navitar Control'
  ClientHeight = 645
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
  DesignSize = (
    962
    645)
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
  object mInfoMemo: TMemo
    Left = 0
    Top = 426
    Width = 962
    Height = 219
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 962
    Height = 423
    Align = alTop
    TabOrder = 1
    object ConnectBtn: TButton
      Left = 32
      Top = 36
      Width = 153
      Height = 57
      Caption = 'Connect'
      TabOrder = 0
      OnClick = ButtonClick
    end
    object Zoom: TGroupBox
      Left = 224
      Top = 32
      Width = 361
      Height = 153
      Caption = 'Zoom'
      TabOrder = 1
      object Button3: TButton
        Left = 14
        Top = 24
        Width = 91
        Height = 41
        Caption = 'Home'
        TabOrder = 0
      end
      object Button4: TButton
        Left = 111
        Top = 24
        Width = 91
        Height = 41
        Caption = 'Limit'
        TabOrder = 1
      end
      object CurrentPosition: TIntegerLabeledEdit
        Left = 224
        Top = 40
        Width = 121
        Height = 21
        EditLabel.Width = 77
        EditLabel.Height = 13
        EditLabel.Caption = 'Current Position'
        TabOrder = 2
        Text = '0'
      end
    end
    object ControllerInfoGB: TGroupBox
      Left = 704
      Top = 36
      Width = 225
      Height = 149
      Caption = 'Controller Info'
      TabOrder = 2
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
    Left = 854
    Top = 448
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Clear'
    TabOrder = 2
    OnClick = Button1Click
  end
  object mShutDownTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = mShutDownTimerTimer
    Left = 456
    Top = 272
  end
end
