#ifndef STACK_H
#define STACK_H
//int M = 5000;
/*
本类为栈的实现

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
	int size();  //栈元素的数量
	bool empty(); // 栈是否为空
	bool push(T& item); // 元素进栈
	bool pop();  // 元素出栈
	bool clearStack(); //清理栈
	T top(); //返回栈顶元素
	void reverse();  // 栈的翻转
public:
	int capacity; //栈的容量

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
 当栈的元素数量超过容量时栈会扩容

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



