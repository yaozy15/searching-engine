#ifndef MYHASH_H
#define MYHASH_H


#include"CharStringLink.h"

class hashtable
{
public:
	StringLink *elem;
	int size;
public:
	hashtable()
	{
		size = 150000;
		elem = new StringLink[size + 2];
	}
	~hashtable(){}
public:
	void insert_ptr(CharString &aim);
	
	bool search(CharString &aim);
	unsigned int hash_value(CharString & s);
   

};














#endif