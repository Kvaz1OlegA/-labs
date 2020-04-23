//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Tree *tree;

bool check=false;
int choose;
int n = 0;
// Доступ к удалению строки в стринггрид
class TExtStringGrid: public  TStringGrid
{
	public:
		using TStringGrid::DeleteRow;
};

void ViewTree(Tree *p, int kl)

{
	if (p == NULL) return;
	if (kl == -1)
		Form1->TreeView1->Items->AddFirst(NULL,p->info.data+"= "+IntToStr(p->info.key));
	else
		Form1->TreeView1->Items->AddChildFirst(Form1->TreeView1->Items->Item[kl], p->info.data+" = "+IntToStr(p->info.key));
	kl++;
	ViewTree(p->left,kl);
	ViewTree(p->right,kl);
	kl--;
}

void Search(Tree *p, int index)
{
if (p == NULL) return;

	if (p->info.key == index) {
		Form1->Memo1->Lines->Add(p->info.data);
	}
	if (p->info.key > index) {
		Search(p->left,index);
	}
	if (p->info.key < index ) {
		Search(p->right,index);
	}
}
  // Обход 1
void WrtTree(Tree*p) {

if (p == NULL)return;

Form1->Memo1->Lines->Add(p->info.data+" "+p->info.key);

WrtTree(p->left);

WrtTree(p->right);

}
  // Обход 2
void WrtTreeB(Tree*p) {

if (p == NULL)return;

WrtTreeB(p->left);

Form1->Memo1->Lines->Add(p->info.data+" "+p->info.key);


WrtTreeB(p->right);

}
  // Обход 3
void WrtTreeP(Tree*p) {

 if (p == NULL)return;
WrtTreeP(p->left);

WrtTreeP(p->right);

Form1->Memo1->Lines->Add(p->info.data+" "+p->info.key);

}

  // Задание
void Task(Tree*p) {

	if (p == NULL)return;

	Task(p->left);
	Task(p->right);

	if(p->left!=nullptr && p->right!=nullptr)
	{
		Form1->Memo1->Lines->Add(p->info.data+" "+p->info.key);
	}

}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->FixedCols=0;
	StringGrid1->ColCount=2;
	StringGrid1->RowCount=1;
	StringGrid1->Cells[0][0] = "Data";
	StringGrid1->Cells[1][0]="Key";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Info A;
	for (int i = 1; i <= n; i++)
	{

		A.data = StringGrid1->Cells[0][i];
		A.key = StrToInt(StringGrid1->Cells[1][i]);
		tree = Add(tree,A);
	}

	int kl=-1;
	TreeView1->Items->Clear();
	ViewTree(tree,kl);
	TreeView1->FullExpand();
	StringGrid1->FixedCols=0;
	StringGrid1->ColCount=2;
	StringGrid1->RowCount=1;
	StringGrid1->Cells[0][0] = "Data";
	StringGrid1->Cells[1][0]="Key";
    n=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	tree = Delete(tree,StrToInt(Edit1->Text));
	int kl=-1;
	TreeView1->Items->Clear();
	ViewTree(tree,kl);
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	n++;
	StringGrid1->RowCount = n+1;
	StringGrid1->Cells[0][n] = Edit2->Text;
	StringGrid1->Cells[1][n] = Edit3->Text;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Clear();

	Search(tree, StrToInt(Edit1->Text));
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
	Memo1->Clear();
	switch(choose)
	{
		case 1:
			WrtTree(tree);
			break;
		case 2:
			WrtTreeB(tree);
			break;
		case 3:
			WrtTreeP(tree);
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Clear();
	Task(tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Info A;
	A.data = Edit2->Text;

	A.key = StrToInt(Edit3->Text);
	tree = Add(tree,A);
	n++;
	StringGrid1->RowCount = n+1;
	StringGrid1->Cells[0][n] = Edit2->Text;
	StringGrid1->Cells[1][n] = Edit3->Text;

	int kl=-1;
	TreeView1->Items->Clear();
	ViewTree(tree,kl);
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------

