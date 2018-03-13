#include"fileLink.h"

#define M 1000


fileLink::fileLink()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

fileLink::~fileLink()
{
	
   
}
/*
销毁字符串链表
*/
void fileLink::destroy()
{
	file *temp;
	file *q;
	temp = head;
	while(temp != NULL)
	{
		q = temp;
		temp = temp->next;
		delete q;

	}


}
/*
 增加节点

*/
void fileLink::Add(CharString &s, int r, string& name)
{
 if(!Search(s))
 {
	file *p = new file;
	p->filename = s;
	p->rank = r;
	p->name = name;
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
 }

}
/*
搜索节点

*/
bool fileLink::Search(CharString aim)
{
	int n;
	bool judge = false;
	file *q, *block;
	file temp;
	if(size == 0)
	{
		return false;
	}
	else
	{
		q = head;
		while(q != NULL)
		{
			if(wcscmp(q->filename.data, aim.data)== 0)
			{
				//block = q;
				judge = true;
				break;
			}
			q = q->next;
		}
		if(judge == false)
			return false;
		else
			return true;

	}

}
/*
删除节点

*/
bool fileLink::Remove(CharString aim)
{
	
	if(Search(aim) == false)
		return false;
	file *p, *q;
	p = head;
	while(p != NULL)
	{
		if(wcscmp(p->filename.data, aim.data) == 0)
		{
			if(wcscmp(head->filename.data, aim.data) == 0)
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


void fileLink::Edit(fileLink& t)
{


		file*p = t.head;
		while(p)
		{
			Add(p->filename, p->rank, p->name);

			p = p->next;
		}


}


