//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include "Unit1.h"

using namespace std;

template <typename T>
class Node
{
public:
	unsigned char height;
	Node<T>* left;
	Node<T>* right;
	T data;
	int key;
	Node(T data = T(), int key = int())
	{
		this->data = data;
		this->key = key;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

template <typename T>
class Tree
{
public:
	Tree();
	void AddItem(T data, int key);
	void DeleteItem(int key);
	void GetInfo(int key,TMemo*);
	void Show(TTreeView*, int);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void DirectCrawl(TMemo* memo);
	void ReverseCrawl(TMemo* memo);
	void AscendingCrawl(TMemo* memo);
	void LabTask(TMemo* memo);
private:
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void Add(Node<T>*& node, T data, int key);
	void Delete(Node<T>*& node, int key);
	void Get(Node<T>* node, TMemo*, int key);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	unsigned char Height(Node<T>* root);
	int BalanceFactor(Node<T>* root);
	void Fix(Node<T>* root);
	Node<T>* RotateRight(Node<T>* p);
	Node<T>* RotateLeft(Node<T>* q);
	Node<T>* Balance(Node<T>* p);
	Node<T>* FindMin(Node<T>* p);
	Node<T>* RemoveMin(Node<T>* p);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void TreeView(Node<T>*& node, TTreeView*, int);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void Direct(Node<T>*& node,TMemo* memo);
	void Reverse(Node<T>*& node,TMemo* memo);
	void Ascending(Node<T>*& node,TMemo* memo);
	void Task(Node<T>*& node,TMemo* memo);
	Node<T>* root;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
template <typename T>
Tree<T>::Tree()
{
	root = nullptr;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
void Tree<T>::Add(Node<T>*& node, T data, int key)
{
	if (node == nullptr)
	{
		node = new Node<T>(data, key);
		return;
	}
	if (key < node->key)
	{
		Add(node->left, data, key);
	}
	else
	{
		Add(node->right, data, key);
	}
	node = Balance(node);
}

template<typename T>
void Tree<T>::Delete(Node<T>*& node, int key)
{
	if (!node)
		return;
	if (key < node->key)
		 Delete(node->left, key);
	else if (key > node->key)
		Delete(node->right, key);
	else
	{
		Node<T>* q = node->left;
		Node<T>* r = node->right;
		delete node;
		if (!r)
		{
			node = q;
			return;
		}
		Node<T>* min = FindMin(r);
		min->right = RemoveMin(r);
		min->left = q;
		node = Balance(min);
	}
}

template<typename T>
void Tree<T>::Get(Node<T>* node,TMemo* memo, int key)
{
	if(node->key==key)
	{
		memo->Lines->Add(node->data);
		return;
	}
	if(key<node->key)
	{
		Get(node->left,memo, key);
	}
	else
	{
		Get(node->right,memo, key);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
unsigned char Tree<T>::Height(Node<T>* root)
{
	return root?root->height:0;
}
template<typename T>
int Tree<T>::BalanceFactor(Node<T>* root)
{
	return Height(root->right)-Height(root->left);
}
template<typename T>
void Tree<T>::Fix(Node<T>* root)
{
	unsigned char hl = Height(root->left);
	unsigned char hr = Height(root->right);
	root->height = (hl > hr ? hl : hr) + 1;
}
template<typename T>
Node<T>* Tree<T>::RotateRight(Node<T>* p)
{
	Node<T>* q = p->left;
	p->left = q->right;
	q->right = p;
	Fix(p);
	Fix(q);
	return q;
}
template<typename T>
Node<T>* Tree<T>::RotateLeft(Node<T>* q)
{
	Node<T>* p = q->right;
	q->right = p->left;
	p->left = q;
	Fix(q);
	Fix(p);
	return p;
}
template<typename T>
Node<T>* Tree<T>::Balance(Node<T>* p)
{
	Fix(p);
	if (BalanceFactor(p) == 2)
	{
		if (BalanceFactor(p->right) < 0)
			p->right = RotateRight(p->right);
		return RotateLeft(p);
	}
	if (BalanceFactor(p) == -2)
	{
		if (BalanceFactor(p->left) > 0)
			p->left = RotateLeft(p->left);
		return RotateRight(p);
	}
	return p;
}
template<typename T>
Node<T>* Tree<T>::FindMin(Node<T>* p)
{
	return p->left ? FindMin(p->left) : p;
}
template<typename T>
Node<T>* Tree<T>::RemoveMin(Node<T>* p)
{
	if (p->left == 0)
		return p->right;
	p->left = RemoveMin(p->left);
	return Balance(p);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
void Tree<T>::AddItem(T data, int key)
{
	Add(root, data, key);
}


template<typename T>
void Tree<T>::DeleteItem(int key)
{
	Delete(root, key);
}

template<typename T>
void Tree<T>::GetInfo(int key, TMemo* memo)
{
	return Get(root, memo, key);
}

template<typename T>
void Tree<T>::TreeView(Node<T>*& node, TTreeView* treeview, int k)
{
	if(node == nullptr)
		return;
	if(k == -1)
		treeview->Items->AddFirst(NULL,IntToStr(node->key)+" - "+node->data);
	else
		treeview->Items->AddChildFirst(treeview->Items->Item[k], IntToStr(node->key)+" - "+node->data);
	k++;
	TreeView(node->left, treeview, k);
	TreeView(node->right, treeview, k);
	k--;
}


template<typename T>
void Tree<T>::Show(TTreeView* treeview, int k)
{
	TreeView(root, treeview, k);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
void Tree<T>::Direct(Node<T>*& node,TMemo* memo)
{
	if(node==nullptr)
		return;
	memo->Lines->Add(IntToStr(node->key)+" - "+node->data);
	Direct(node->left, memo);
	Direct(node->right, memo);
}
template<typename T>
void Tree<T>::Reverse(Node<T>*& node,TMemo* memo)
{
	if(node==nullptr)
		return;
	Reverse(node->left, memo);
	memo->Lines->Add(IntToStr(node->key)+" - "+node->data);
	Reverse(node->right, memo);
}
template<typename T>
void Tree<T>::Ascending(Node<T>*& node,TMemo*memo)
{
	if(node==nullptr)
		return;
	Ascending(node->left, memo);
	Ascending(node->right, memo);
	memo->Lines->Add(IntToStr(node->key)+" - "+node->data);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
template<typename T>
void Tree<T>::DirectCrawl(TMemo* memo)
{
	Direct(root, memo);
}
template<typename T>
void Tree<T>::ReverseCrawl(TMemo* memo)
{
	Reverse(root, memo);
}
template<typename T>
void Tree<T>::AscendingCrawl(TMemo*memo)
{
	Ascending(root, memo);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
    template<typename T>
void Tree<T>::Task(Node<T>*& node,TMemo*memo)
{
	if(node==nullptr)
		return;
	if(node->left && node->right)
		memo->Lines->Add(IntToStr(node->key)+" - "+node->data);
	Task(node->left, memo);
	Task(node->right, memo);
}

template<typename T>
void Tree<T>::LabTask(TMemo*memo)
{
	Task(root, memo);
}
#endif
