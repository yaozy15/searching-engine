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
�����ַ�������
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
 ���ӽڵ�,����֮ǰ�����ڵ�������������ͼ���ýڵ㣬��֮���ôʵĴ�Ƶ��һ��

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
�����ڵ�

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
ɾ���ڵ�

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

���aim����ַ������ַ��������е�Ƶ��

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