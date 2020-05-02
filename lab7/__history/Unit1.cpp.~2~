//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "HashChain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HashChain <int> *hash;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	hash=new HashChain<int>(StrToInt(Edit4->Text));
	for(int i=0; i<hash->GetKey(); i++)
	{
		Memo1->Lines->Add("#"+IntToStr(i));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	hash->Insert(StrToInt(Edit1->Text),StrToInt(Edit2->Text));
	Memo1->Lines->Clear();
	for(int i=0; i<hash->GetKey(); i++)
	{
		Memo1->Lines->Add("#"+IntToStr(i));
		hash->ShowInf(Memo1, i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	hash->Delete(StrToInt(Edit3->Text));
	Memo1->Lines->Clear();
	for(int i=0; i<hash->GetKey(); i++)
	{
		Memo1->Lines->Add("#"+IntToStr(i));
		hash->ShowInf(Memo1, i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo2->Lines->Clear();
    Memo2->Lines->Add("Data:"+IntToStr(hash->GetInfo(StrToInt(Edit3->Text))));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	hash=new HashChain<int>(StrToInt(Edit4->Text));
	for(int i=0; i<hash->GetKey(); i++)
	{
		hash->Insert(StrToInt(rand()%+StrToInt(Edit6->Text)),rand()%100);
	}
	for(int i=0; i<hash->GetKey(); i++)
	{
		Memo1->Lines->Add("#"+IntToStr(i));
		hash->ShowInf(Memo1, i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    hash->Task(Memo2);
}
//---------------------------------------------------------------------------

