object Form1: TForm1
  Left = 731
  Top = 289
  Width = 1248
  Height = 598
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 104
    Top = 144
    Width = 75
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 376
    Top = 8
    Width = 857
    Height = 553
    ColCount = 13
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
    TabOrder = 1
    OnMouseDown = StringGrid1MouseDown
  end
  object init: TGroupBox
    Left = 104
    Top = 16
    Width = 225
    Height = 121
    Caption = #1048#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
    TabOrder = 2
    object Label1: TLabel
      Left = 36
      Top = 24
      Width = 29
      Height = 13
      Caption = #1089#1086#1082#1077#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 43
      Top = 48
      Width = 22
      Height = 13
      Caption = #1093#1086#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 24
      Top = 72
      Width = 41
      Height = 13
      Caption = 'IP '#1093#1086#1089#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 10
      Top = 96
      Width = 55
      Height = 13
      Caption = 'IP '#1089#1077#1088#1074#1077#1088#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 72
      Top = 20
      Width = 145
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 72
      Top = 44
      Width = 145
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 72
      Top = 68
      Width = 145
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 72
      Top = 92
      Width = 145
      Height = 21
      TabOrder = 3
    end
  end
  object Button2: TButton
    Left = 208
    Top = 144
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1086#1085#1095#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 32
    Top = 176
    Width = 337
    Height = 113
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
  object StringGrid2: TStringGrid
    Left = 34
    Top = 312
    Width = 319
    Height = 249
    ColCount = 10
    DefaultColWidth = 30
    RowCount = 7
    TabOrder = 5
  end
end
