#ifndef MYHASH_H
#define MYHASH_H

/*
������Ҫ�ǹ�ϣ��Ĺ������õ�����ʽ��ϣ��

*/
#include"CharStringLink.h"

class hashtable
{
public:
	StringLink *elem; //��ϣ��ÿ��Ԫ�ض���һ���ַ�������
	int size; //��ϣ����
public:
	hashtable()
	{
		size = 1450000;
		elem = new StringLink[size + 2];
	}
	hashtable(int n)
	{
		size = n;
		elem = new StringLink[size + 2];

	}
	~hashtable(){}
public:
	void insert_ptr(CharString &aim); //��ϣ�����Ԫ��
	
	bool search(CharString &aim); //��ϣ������
	unsigned int hash_value(CharString & s); //��ϣ����
   

};














#endif