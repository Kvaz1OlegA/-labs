//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
#include "Queue.h"

template <typename T>
class List:public Queue<T>
{
public:
	List();

	~List();

	void PopBack();

	void PushFront(T);

	void Insert(T, int);

	void RemoveAt(int);

	void InsertList(List<T>&, int);

	T& operator[](const int);
};

template <typename T>
List<T>::List()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template <typename T>
void List<T>::PopBack()
{
	if (this->size == 1)
	{
		delete this->tail;
		this->head = nullptr;
		this->tail = nullptr;
		this->size--;
		return;
	}
	this->tail = this->tail->prev;
	delete this->tail->next;
	this->tail->next = nullptr;
	this->size--;
}

template <typename T>
void List<T>::PushFront(T data)
{
	if (this->head == nullptr)
	{
		this->head = this->tail = new Node<T>(data);
	}
	else
	{
		this->head->prev = new Node<T>(data, nullptr, this->head);
		this->head = this->head->prev;
	}
	this->size++;
}

template <typename T>
void List<T>::Insert(T data, int index)
{
	Node<T>* current;
	if (index == 0)
	{
		PushFront(data);
		return;
	}
	else if (index == this->size)
	{
		this->PushBack(data);
		return;
	}
	else if (index <= this->size / 2)
	{
		current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
	}
	else
	{
		current = this->tail;
		for (int i = this->size - 1; i > index - 1; i--)
		{
			current = current->prev;
		}
	}
	current->next = new Node<T>(data, current, current->next);
	current->next->next->prev = current->next;
	this->size++;
}

template <typename T>
void List<T>::RemoveAt(int index)
{
	if (index == 0)
	{
		this->PopFront();
	}
	else if (index == this->size - 1)
	{
		PopBack();
	}
	else if (index <= this->size / 2)
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		Node<T>* todelete = current->next;
		current->next = todelete->next;
		todelete->next->prev = current;
		delete todelete;
		this->size--;
	}
	else
	{
		Node<T>* current = this->tail;
		for (int i = this->size - 1; i > index - 2; i--)
		{
			current = current->prev;
		}
		Node<T>* todelete = current->next;
		current->next = todelete->next;
		todelete->next->prev = current;
		delete todelete;
		this->size--;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	if (index <= this->size / 2)
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->next;
			counter++;
		}
	}
	else
	{
		int counter = this->size - 1;
		Node<T>* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->prev;
			counter--;
		}
	}
}

template<typename T>
void List<T>::InsertList(List<T>&temp, int index)
{
	for (int i = 0; i < temp.GetSize(); i++)
	{
		Insert(temp[i], index + i);
	}
}

template <typename T>
List<T>::~List()
{
	while (this->size)
	{
		this->PopFront();
	}
}

#endif
