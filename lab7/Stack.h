//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
#include "Unit1.h"
template <typename T>
class Node
{
public:
	Node* next;
	int key;
	T data;
	Node(int key = int(),T data = T(), Node* next = nullptr)
	{
		this->key = key;
		this->data = data;
		this->next = next;
	}
};

template <typename T>
class Stack
{
public:
	Stack();

	~Stack();

	void PopFront();

	void PushFront(T data, int key);

	void Clear();

	int GetSize();

	void Sort();

	T GetData(int key);
	////////////////////////////////////////////////////////////////////////////
	T GetDataByOrder(int index);

	int GetKey(int index);
	////////////////////////////////////////////////////////////////////////////
	void Show(TMemo *memo);
private:
	int size;

	Node<T>* head;
};

template <typename T>
Stack<T>::Stack()
{
	size = 0;
	head = nullptr;
}

template <typename T>
int Stack<T>::GetSize()
{
	return size;
}

template<typename T>
T Stack<T>::GetData(int index)
{
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (current->key == index)
		{
			return current->data;
		}
		current = current->next;
	}
}


template<typename T>
T Stack<T>::GetDataByOrder(int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if(counter == index)
		{
			return current->data;
		}
		counter++;
		current=current->next;
	}
}

template<typename T>
int Stack<T>::GetKey(int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if(counter == index)
		{
			return current->key;
		}
		counter++;
		current=current->next;
	}
}

template <typename T>
void Stack<T>::PopFront()
{
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}

template <typename T>
void Stack<T>::Sort()
{
	for(int i=0; i<GetSize();i++)
	{
		Node<T>*current = this->head;
		while(current->next!=nullptr)
		{
			if(current->key<current->next->key)
			{
				int temp_key = current->key;
				current->key = current->next->key;
				current->next->key = temp_key;

				T temp_data = current->data;
				current->data = current->next->data;
				current->next->data = temp_data;
			}
			current = current->next;
		}
	}
}

template <typename T>
void Stack<T>::Clear()
{
	while (size)
	{
		PopFront();
	}
}

template <typename T>
void Stack<T>::PushFront(T data, int key)
{
	head = new Node<T>(key, data, head);
	size++;
}


template <typename T>
void Stack<T>::Show(TMemo *memo)
{
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		memo->Lines->Add("   Key:"+IntToStr(current->key)+"   Data:"+IntToStr(current->data));
		current = current->next;
	}
}

template <typename T>
Stack<T>::~Stack()
{
	Clear();
}

#endif
