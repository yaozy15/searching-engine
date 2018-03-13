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
�����ַ�������
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
 ���ӽڵ㣬�������������ڵ㣬������������ͽ�����뵽�����У�����������ͽ����ĵ�������ʵĴ�Ƶ��1��

*/
void fileLink::Add(CharString &s, int r)
{
 file *t = find(s);
 if(!t)
 {
	file *p = new file;
	p->filename = s;
	p->rank = r;
	p->fre = 1;
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
 else
 {
	 t->fre ++;
 }

}
void fileLink::Addplus(CharString &s, int r, file*& q)
{
 file *t = find(s);
 if(!t)
 {
	file *p = new file;
	p->filename = s;
	p->rank = r;
	p->fre = q->fre;
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
 else
 {
	 t->fre += q->fre;
 }

}
/*
�����ڵ㣬����������ͷ����������Ľڵ㣬��֮���ؿ�ָ��

*/
file* fileLink::find(CharString aim)
{
	int n;
	bool judge = false;
	file *q, *block;
	file temp;
	if(head == NULL)
		return NULL;
	else
	{
		q = head;
		while(q != NULL)
		{
			if(wcscmp(q->filename.data, aim.data)== 0)
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
�����ڵ㣬����������ͷ���true����֮����false

*/
bool fileLink::Search(CharString aim)
{
	int n;
	bool judge = false;
	file *q, *block;
	file temp;
	if(head == NULL)
		return false;
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
ɾ���ڵ�

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

/*
���º�������Ҫ�����ǽ�������ͬ�ʵ��ĵ�����������ϱ༭������������ȥ�غϳ�һ��

*/
void fileLink::Edit(fileLink& t)
{


		file*p = t.head;
		while(p)
		{
			Add(p->filename, p->rank);
			p = p->next;
		}


}


