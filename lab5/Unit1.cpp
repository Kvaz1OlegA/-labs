//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Queue.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

Queue<int> nums;

List<int> box1;

List<int> box2;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	switch (choose)
	{
		case 1:
			box1.PushBack(StrToInt(Edit1->Text));
			ListBox1->Items->Add(Edit1->Text);
			break;
		case 2:
			box2.PushBack(StrToInt(Edit1->Text));
			ListBox2->Items->Add(Edit1->Text);
			break;
		case 3:
			nums.PushBack(StrToInt(Edit1->Text));
			ListBox3->Items->Add(Edit1->Text);
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	switch (choose)
	{
		case 1:
			box1.PopBack();
			ListBox1->Items->Delete(box1.GetSize());
			break;
		case 2:
			box2.PopBack();
			ListBox2->Items->Delete(box2.GetSize());
			break;
		case 3:
			nums.PopFront();
			ListBox3->Items->Delete(0);
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    choose = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    choose = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	choose = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int min = box1[0];
	int max = box1[0];
	int min_index=0;
	int max_index=0;
	for(int i=0; i<box1.GetSize(); i++)
	{
		if(box1[i]<min)
		{
			min=box1[i];
			min_index=i;
		}
		if(box1[i]>max)
		{
			max=box1[i];
			max_index=i;
		}
	}
	if(min_index<max_index)
	{
		while(min_index+1!=max_index)
		{
			ListBox1->Items->Delete(min_index+1);
			max_index--;
		}
		box1.InsertList(box2, min_index+1);
		for(int i=0; i<box2.GetSize(); i++)
		{
			ListBox1->Items->Insert(min_index+1+i, IntToStr(box2[i]));
		}
	}
	else
	{
		while(max_index+1!=min_index)
		{
			ListBox1->Items->Delete(max_index+1);
			min_index--;
		}
		box1.InsertList(box2, max_index+1);
		for(int i=0; i<box2.GetSize(); i++)
		{
			ListBox1->Items->Insert(max_index+1+i, IntToStr(box2[i]));
		}
    }
}
//---------------------------------------------------------------------------

