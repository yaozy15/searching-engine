#include"myhash.h"



/*
¹şÏ£±í²åÈë

*/
void hashtable::insert_ptr(CharString& aim)
{
	unsigned int m = hash_value(aim);
	elem[m].add(aim);

}
/*
¹şÏ£±íËÑË÷

*/
bool hashtable::search(CharString &aim)
{

	unsigned int m = hash_value(aim);
	CharStringNode *p = elem[m].search(aim);
	if(p)
		return true;
	else
		return false;

}
/*
¹şÏ£º¯Êı

*/
unsigned int hashtable::hash_value(CharString & s)
{  
	unsigned int ch = 0;
	unsigned int hash = 0;
	for(int i = 0; i < s.length; i++)
	{
		ch = (unsigned int)(s.data[i]);
		hash = hash * 131 + ch;

	}
	return hash % size;
}