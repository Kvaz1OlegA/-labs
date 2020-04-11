object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 449
  ClientWidth = 452
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
    Left = 40
    Top = 10
    Width = 26
    Height = 16
    Caption = 'List1'
  end
  object Label2: TLabel
    Left = 160
    Top = 10
    Width = 26
    Height = 16
    Caption = 'List2'
  end
  object Label3: TLabel
    Left = 280
    Top = 10
    Width = 37
    Height = 16
    Caption = 'Queue'
  end
  object ListBox1: TListBox
    Left = 8
    Top = 32
    Width = 97
    Height = 377
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 351
    Top = 32
    Width = 97
    Height = 24
    TabOrder = 1
  end
  object Button1: TButton
    Left = 351
    Top = 69
    Width = 97
    Height = 25
    Caption = 'Add'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 351
    Top = 100
    Width = 97
    Height = 25
    Caption = 'Delete'
    TabOrder = 3
    OnClick = Button2Click
  end
  object ListBox2: TListBox
    Left = 128
    Top = 32
    Width = 97
    Height = 377
    TabOrder = 4
  end
  object ListBox3: TListBox
    Left = 248
    Top = 32
    Width = 97
    Height = 377
    TabOrder = 5
  end
  object RadioButton1: TRadioButton
    Left = 50
    Top = 415
    Width = 15
    Height = 17
    TabOrder = 6
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 169
    Top = 415
    Width = 16
    Height = 17
    TabOrder = 7
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 288
    Top = 415
    Width = 17
    Height = 17
    TabOrder = 8
    OnClick = RadioButton3Click
  end
  object Button3: TButton
    Left = 351
    Top = 131
    Width = 97
    Height = 25
    Caption = 'Execute'
    TabOrder = 9
    OnClick = Button3Click
  end
end
