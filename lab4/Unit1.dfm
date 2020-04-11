object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 112
  ClientWidth = 512
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 148
    Top = 2
    Width = 187
    Height = 16
    Caption = 'Enter a mathematical expression'
  end
  object Label2: TLabel
    Left = 44
    Top = 58
    Width = 133
    Height = 16
    Caption = 'Reverse Polish notation'
  end
  object Label3: TLabel
    Left = 300
    Top = 58
    Width = 35
    Height = 16
    Caption = 'Result'
  end
  object Edit1: TEdit
    Left = 4
    Top = 24
    Width = 425
    Height = 24
    TabOrder = 0
    Text = '(8+2*5)/(1+3*2-4)'
  end
  object Button1: TButton
    Left = 435
    Top = 24
    Width = 69
    Height = 80
    Caption = 'Calculate'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 4
    Top = 80
    Width = 209
    Height = 24
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 220
    Top = 80
    Width = 209
    Height = 24
    TabOrder = 3
  end
end
