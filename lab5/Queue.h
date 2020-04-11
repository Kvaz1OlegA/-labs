//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH

template <typename T>
class Node
{
public:
	Node* next;
	Node* prev;
	T data;
	Node(T data = T(), Node* prev = nullptr , Node* next = nullptr)
	{
		this->prev = prev;
		this->data = data;
		this->next = next;
	}
};

template <typename T>
class Queue
{
public:
	Queue();

	~Queue();

	void PopFront();

	void PushBack(T);

	int GetSize();

	T Front();

	T Back();

protected:

	int size;

	Node<T>* head;

	Node<T>* tail;
};

template <typename T>
Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
void Queue<T>::PushBack(T data)
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		tail = tail->next = new Node<T>(data, tail);
	}
	size++;
}

template<typename T>
void Queue<T>::PopFront()
{
	if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return;
	}
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
	size--;
}

template<typename T>
int Queue<T>::GetSize()
{
	return size;
}

template <typename T>
T Queue<T>::Front()
{
	return head->data;
}

template <typename T>
T Queue<T>::Back()
{
	return tail->data;
}

template <typename T>
Queue<T>::~Queue()
{
	while (size)
	{
		PopFront();
	}
}

#endif

