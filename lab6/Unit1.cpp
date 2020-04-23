//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Tree.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TForm1 *Form1;

Tree <AnsiString> tree;
int choose;
int n = 0;
// Доступ к удалению строки в стринггрид
class TExtStringGrid: public  TStringGrid
{
	public:
		using TStringGrid::DeleteRow;
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	try
	{
		if(Edit2->Text==""||Edit3->Text=="")
			throw Exception("Empty fields");
	}
	catch(Exception *ex)
	{
		ShowMessage(ex->Message);
	}
	n++;
	StringGrid1->RowCount = n+1;
	StringGrid1->Cells[0][n] = Edit3->Text;
	StringGrid1->Cells[1][n] = Edit2->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->FixedCols=0;
	StringGrid1->ColCount=2;
	StringGrid1->RowCount=1;
	StringGrid1->Cells[0][0] = "Key";
	StringGrid1->Cells[1][0]="Data";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	for (int i = 1; i <= n; i++)
	{
		tree.AddItem(StringGrid1->Cells[1][i], StrToInt(StringGrid1->Cells[0][i]));
	}
	int k=-1;
	TreeView1->Items->Clear();
	tree.Show(TreeView1, k);
	TreeView1->FullExpand();
	StringGrid1->RowCount = 1;
	n=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	try
	{
		if(Edit2->Text==""||Edit3->Text=="")
			throw Exception("Empty fields");
	}
	catch(Exception *ex)
	{
		ShowMessage(ex->Message);
	}
	tree.AddItem(Edit2->Text, StrToInt(Edit3->Text));
	int k=-1;
	TreeView1->Items->Clear();
	tree.Show(TreeView1, k);
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	try
	{
		if(Edit1->Text=="")
			throw Exception("Empty fields");
	}
	catch(Exception *ex)
	{
		ShowMessage(ex->Message);
	}
	tree.DeleteItem(StrToInt(Edit1->Text));
    int k=-1;
	TreeView1->Items->Clear();
	tree.Show(TreeView1, k);
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	try
	{
		if(Edit1->Text=="")
			throw Exception("Empty fields");
	}
	catch(Exception *ex)
	{
		ShowMessage(ex->Message);
	}
	Memo1->Clear();
	tree.GetInfo((StrToInt(Edit1->Text)), Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    choose = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    choose = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
    choose = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	switch(choose)
	{
		case 1:
			tree.DirectCrawl(Memo1);
			break;
		case 2:
			tree.ReverseCrawl(Memo1);
			break;
		case 3:
			tree.AscendingCrawl(Memo1);
			break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	tree.LabTask(Memo1);
}
//---------------------------------------------------------------------------

