#ifndef MYHASH_H
#define MYHASH_H

/*
该类主要是哈希表的构建，用的是链式哈希表

*/
#include"CharStringLink.h"

class hashtable
{
public:
	StringLink *elem; //哈希表每个元素都是一个字符串链表
	int size; //哈希表长度
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
	void insert_ptr(CharString &aim); //哈希表插入元素
	
	bool search(CharString &aim); //哈希表搜索
	unsigned int hash_value(CharString & s); //哈希函数
   

};














#endif