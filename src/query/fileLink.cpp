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
 增加节点，操作室先搜索节点，如果搜索不到就将其加入到链表中，如果搜索到就将该文档的这个词的词频加1。

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
搜索节点，如果搜索到就返回搜索到的节点，反之返回空指针

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
搜索节点，如果搜索到就返回true，反之返回false

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

/*
以下函数的主要作用是将两个不同词的文档链表进行整合编辑，将两个链表去重合成一个

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


