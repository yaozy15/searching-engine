#ifndef STACK_H
#define STACK_H
//int M = 5000;
/*
����Ϊջ��ʵ��

*/
template<class T>
class Stack
{
public:
	enum {MAX = 5000};
	T *items;
	int Top;
	bool have;
public:
	Stack();
	~Stack(){}
public:
	int size();  //ջԪ�ص�����
	bool empty(); // ջ�Ƿ�Ϊ��
	bool push(T& item); // Ԫ�ؽ�ջ
	bool pop();  // Ԫ�س�ջ
	bool clearStack(); //����ջ
	T top(); //����ջ��Ԫ��
	void reverse();  // ջ�ķ�ת
public:
	int capacity; //ջ������

};

template<class T>
Stack<T>::Stack()
{
	Top = 0;
	capacity = 5000;
	have = false;
	items = new T[capacity];
}
template<class T>
int Stack<T>::size()
{
	return Top;
}
template<class T>
bool Stack<T>::empty()
{
	if(Top == 0)
		return true;
	else
		return false;

}
 /*
 ��ջ��Ԫ��������������ʱջ������

 */
template<class T>
bool Stack<T>::push(T& item)
{
	if(Top < capacity)
	{
		items[Top] = item;
		Top++;
		return true;
	}
	else if(Top >= capacity)
	{
		capacity = capacity * 2;
		T *items_new = new T[capacity];
		for(int i = 0; i < Top; i++)
		{
			items_new[i] = items[i];
		}
		delete []items;
		items = items_new;
		items[Top] = item;
		Top++;
		return true;
	}
	else
	return false;
}

template<class T>
bool Stack<T>::pop()
{
	if(Top > 0)
	{
		Top--;
		return true;
	}
	else
		return false;
}

template<class T>
T Stack<T>::top()
{
	if(Top > 0)
	return items[Top - 1];

}

template<class T>
bool Stack<T>::clearStack()
{
	Top = 0;
	return true;

}

template<class T>
void Stack<T>::reverse()
{

	if(Top % 2 == 1)
	{
	for(int i = 0; i < (Top - 1)/2; i++)
	{
		T temp;
		temp = items[Top - i - 1];
		items[Top - i - 1] = items[i];
		items[i] = temp;


	}
	}
	else
	{
    for(int i = 0; i < (Top)/2; i++)
	{
		T temp;
		temp = items[Top - i - 1];
		items[Top - i - 1] = items[i];
		items[i] = temp;


	}


	}

}




















#endif



