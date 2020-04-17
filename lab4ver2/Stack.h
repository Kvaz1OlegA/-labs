//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
template <typename T>
class Node
{
	public:
		Node *next;
		T data;
		Node(T data = T(), Node *next = nullptr)
		{
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

		void PushFront(T);

		void Clear();

		int GetSize();

		T& operator[](const int);
	private:
		int size;

		Node<T> *head;
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
T& Stack<T>::operator[](const int index)
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

template <typename T>
void Stack<T>::PopFront()
{
	Node<T> *temp = head;
	head=head->next;
	delete temp;
	size--;
}

template <typename T>
void Stack<T>::Clear()
{
	while(size)
	{
		PopFront();
	}
}

template <typename T>
void Stack<T>::PushFront(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template <typename T>
Stack<T>::~Stack()
{
	Clear();
}
#endif
