//---------------------------------------------------------------------------

#ifndef HashChainH
#define HashChainH
#include "Stack.h"
#include "Unit1.h"
template <typename T>
class HashChain {
private:
	int key;
	Stack<T> *flow;
	int Hash(int key);
public:
	HashChain(int num);
	void Insert(int key, T data);
	void Delete(int key);
	void ShowInf(TMemo *memo, int key);
	T GetInfo(int key);
	int GetKey();
	////////////////////////////////////////////////////////////////////////////
	void Task(TMemo *memo);
	////////////////////////////////////////////////////////////////////////////
	~HashChain();
};

template<typename T>
HashChain<T>::HashChain(int num)
{
	key = num;
	flow = new Stack<T>[num];
}

template<typename T>
void HashChain<T>::Insert(int key, T data)
{
	flow[Hash(key)].PushFront(data, key);
}

template<typename T>
void HashChain<T>::Delete(int key)
{
	flow[Hash(key)].PopFront();
}

template<typename T>
T HashChain<T>::GetInfo(int key)
{
	return flow[Hash(key)].GetData(key);
}

template<typename T>
int HashChain<T>::GetKey()
{
	return key;
}

template<typename T>
int HashChain<T>::Hash(int key)
{
	return key%this->key;
}


template<typename T>
void HashChain<T>::ShowInf(TMemo *memo, int key)
{
	flow[Hash(key)].Show(memo);
}


template<typename T>
void HashChain<T>::Task(TMemo *memo)
{
	Stack<T> *temp = new Stack<T>();
	for(int i=0; i<key;i++)
	{
		for(int q=0;q<flow[i].GetSize();i++)
		{
			temp->PushFront(flow[i].GetDataByOrder(q),flow[i].GetKey(q));
		}
	}
	temp->Sort();
	for(int i=0; i<temp->GetSize(); i++)
	{
		memo->Lines->Add("   Key:"+IntToStr(temp->GetKey(i))+"   Data:"+IntToStr(temp->GetDataByOrder(i)));
	}
	delete temp;
}

template<typename T>
HashChain<T>::~HashChain()
{
	for (int i = 0; i < key; i++)
	{
		while (flow[i].GetSize() != 0)
		{
			flow[i].PopFront();
		}
	}
}

#endif
