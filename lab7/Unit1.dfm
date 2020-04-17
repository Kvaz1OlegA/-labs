object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 511
  ClientWidth = 587
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
    Left = 341
    Top = 39
    Width = 20
    Height = 16
    Caption = 'Key'
  end
  object Label2: TLabel
    Left = 341
    Top = 85
    Width = 26
    Height = 16
    Caption = 'Data'
  end
  object Label3: TLabel
    Left = 512
    Top = 85
    Width = 20
    Height = 16
    Caption = 'Key'
  end
  object Label4: TLabel
    Left = 510
    Top = 126
    Width = 22
    Height = 16
    Caption = 'Info'
  end
  object Label5: TLabel
    Left = 400
    Top = 301
    Width = 90
    Height = 16
    Caption = 'Number of Keys'
  end
  object Label7: TLabel
    Left = 424
    Top = 344
    Width = 47
    Height = 16
    Caption = 'Max Key'
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 281
    Height = 495
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 295
    Top = 8
    Width = 121
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 456
    Top = 54
    Width = 121
    Height = 25
    Caption = 'Delete'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 295
    Top = 55
    Width = 121
    Height = 24
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 295
    Top = 99
    Width = 121
    Height = 24
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 456
    Top = 99
    Width = 121
    Height = 24
    TabOrder = 5
  end
  object Button3: TButton
    Left = 456
    Top = 8
    Width = 121
    Height = 25
    Caption = 'Get Data'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Memo2: TMemo
    Left = 456
    Top = 142
    Width = 121
    Height = 67
    TabOrder = 7
  end
  object Button4: TButton
    Left = 384
    Top = 478
    Width = 121
    Height = 25
    Caption = 'Task'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 384
    Top = 270
    Width = 121
    Height = 25
    Caption = 'Create'
    TabOrder = 9
    OnClick = Button5Click
  end
  object Edit4: TEdit
    Left = 384
    Top = 320
    Width = 121
    Height = 24
    TabOrder = 10
  end
  object Button6: TButton
    Left = 384
    Top = 239
    Width = 121
    Height = 25
    Caption = 'Fill the Random'
    TabOrder = 11
    OnClick = Button6Click
  end
  object Edit6: TEdit
    Left = 384
    Top = 358
    Width = 121
    Height = 24
    TabOrder = 12
  end
end
