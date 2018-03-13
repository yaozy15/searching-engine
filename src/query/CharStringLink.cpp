#include"CharStringLink.h"
#include"CharString.h"
#define M 1000


StringLink::StringLink()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

StringLink::~StringLink()
{
	
   
}
/*
销毁字符串链表
*/
void StringLink::destroy()
{
	CharStringNode *temp;
	CharStringNode *q;
	temp = head;
	while(temp != NULL)
	{
		q = temp;
		temp = temp->next;
		delete q;

	}


}
/*
 增加节点,增加之前搜索节点如果搜索不到就加入该节点，反之将该词的词频加一。

*/
bool StringLink::add(CharString &s)
{
 if(!search(s))
 {
	CharStringNode *p = new CharStringNode;
	p->context = s;
	p->num = 1;
	if(head == NULL)
	{
		head = p;
		tail = p;
		head->next = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = p;
		p->next = NULL;
		tail = p;
	}
	size++;
	return true;
 }
 else
 {
	 search(s)->num++;
	 return false;

 }

}
bool StringLink::addNode(CharString &s)
{
 
	CharStringNode *p = new CharStringNode;
	p->context = s;
	p->num = 1;
	if(head == NULL)
	{
		head = p;
		tail = p;
		head->next = NULL;
		tail->next = NULL;
	}
	else
	{
		tail->next = p;
		p->next = NULL;
		tail = p;
	}
	size++;
	return true;
 
}
/*
搜索节点

*/
CharStringNode* StringLink::search(CharString aim)
{
	int n;
	bool judge = false;
	CharStringNode *q, *block;
	CharStringNode temp;
	if(head == NULL)
		return NULL;
	if(size == 0)
	{
		return NULL;
	}
	else
	{
		q = head;
		while(q != NULL)
		{
			if(wcscmp(q->context.data, aim.data)== 0)
			{
				block = q;
				judge = true;
				break;
			}
			q = q->next;
		}
		if(judge == false)
			return NULL;
		else
			return block;

	}

}
/*
删除节点

*/
bool StringLink::remove(CharString aim)
{
	CharStringNode *temp = search(aim);
	if(temp == NULL)
		return false;
	CharStringNode *p, *q;
	p = head;
	while(p != NULL)
	{
		if(wcscmp(p->context.data, aim.data) == 0)
		{
			if(wcscmp(head->context.data, aim.data) == 0)
			{
				head = head->next;
				p = head;
				size--;
			}
			else
			{
				size--;
				q->next = p->next;
				p = p->next;
			}

		}
		else
		{
			q = p;
			p = p->next;
		}


	}
	
}
/*

求出aim这个字符串在字符串链表中的频率

*/
int StringLink::investigate(CharString &aim)
{
	CharStringNode*p = head;
	int n = 0;
	while(p)
	{
		if(wcscmp(p->context.data, aim.data) == 0)
		{
			n = n + p->num;
			//break;
		}
		p = p->next;


	}
	return n;

}