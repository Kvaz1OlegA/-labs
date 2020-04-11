//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Stack.h"

TForm1 *Form1;

Stack <float> nums;

Stack <char> operations;

using namespace std;

string temp;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString exeption = Edit1->Text;
	for (int i = 1; i <= exeption.Length(); i++)
	{
		if ((exeption[i] >= '0' && exeption[i] <= '9')|| exeption[i] == '.')
		{
			temp.push_back(exeption[i]);
		}
		else
		{
			if (i - 1 >= 1 && (exeption[i-1] >= '0' && exeption[i-1] <= '9'))
			{
				temp.push_back('|');
			}
			if (exeption[i] == ')')
			{
				while (operations[0]!='(')
				{
					temp.push_back(operations[0]);
					operations.PopFront();
				}
				operations.PopFront();
			}
			else if (exeption[i] == '+' || exeption[i] == '-')
			{
				if (operations[0] == '(')
				{
					operations.PushFront(exeption[i]);
				}
				else
				{
					while (operations.GetSize()!=0 && operations[0] != '(')
					{
						temp.push_back(operations[0]);
						operations.PopFront();
					}
					operations.PushFront(exeption[i]);
				}
			}
			else if (exeption[i] == '/' || exeption[i] == '*')
			{
				if (operations[0] == '(' || operations[0] == '+' || operations[0] == '-')
				{
					operations.PushFront(exeption[i]);
				}
				else
				{
					while (operations.GetSize() != 0 && operations[0] != '(')
					{
						temp.push_back(operations[0]);
						operations.PopFront();
					}
					operations.PushFront(exeption[i]);
				}
			}
			else
			{
				operations.PushFront(exeption[i]);
			}
		}
	}
	if(temp[temp.size()-1]>='0' && temp[temp.size() - 1] <= '9')
		temp.push_back('|');
	while (operations.GetSize()!= 0)
	{
		temp.push_back(operations[0]);
		operations.PopFront();
	}
	Edit2->Text = temp.c_str();
	int lenght = 0;
	string number;
	float result;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] >= 48 && temp[i] <= 57)
		{
			int k = i;
			while (temp[i] != '|')
			{
				lenght++;
				i++;
			}
			number = temp.substr(k, lenght);
			nums.PushFront(atof(number.c_str()));
		}
		else
		{
			switch (temp[i])
			{
			case '+':
				result = nums[1] + nums[0];
				nums.PopFront();
				nums.PopFront();
				nums.PushFront(result);
				break;
			case '-':
				result = nums[1] - nums[0];
				nums.PopFront();
				nums.PopFront();
				nums.PushFront(result);
				break;
			case '*':
				result = nums[1] * nums[0];
				nums.PopFront();
				nums.PopFront();
				nums.PushFront(result);
				break;
			case '/':
				result = nums[1] / nums[0];
				nums.PopFront();
				nums.PopFront();
				nums.PushFront(result);
				break;
			}
		}
		lenght = 0;
	}
	Edit3->Text = FloatToStr(nums[0]);
    temp="";
}
//---------------------------------------------------------------------------
