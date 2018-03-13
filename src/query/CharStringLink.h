#ifndef CharStringLINK_H
#define CharStringLINK_H
#include"CharString.h"
/*
CharStringNode为字符串链表的元素
储存字符串
CharStringLink类为字符串链表

*/
struct CharStringNode
{
    CharString context; //节点储存的字符串
	int num; //该词的词频
	CharStringNode *next; //下一个节点
};
class StringLink
{

public:
	StringLink();
	~StringLink();
public:
	CharStringNode *head; //字符串链表的表头
	CharStringNode *tail; //字符串链表的表尾
	int size; //字符串链表的长度
	bool beContext; //是否为标签
public:
	bool add(CharString &p); // 增加值为p的节点
	bool addNode(CharString &p);
	bool remove(CharString aim);  // 删去所有值为aim的节点
	CharStringNode* search(CharString aim);//搜寻链表中第一个值为aim的节点
	int investigate(CharString &aim); //获得还字符串链表中关键词的词频
	void destroy(); //毁掉链表 
	

};


#endif