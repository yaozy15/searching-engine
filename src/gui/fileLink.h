#ifndef FILELINK_H
#define FILELINK_H
#include"CharString.h"
#include<string>
struct file
{
	string name;
    CharString filename; //节点储存的字符串
	int rank;
	file *next; //下一个节点
};
class fileLink
{

public:
	fileLink();
	~fileLink();
public:
	file *head; //字符串链表的表头
	file *tail; //字符串链表的表尾
	int size; //字符串链表的长度
public:
	void Add(CharString &p, int rank, string &name); // 增加值为p的节点
	bool Remove(CharString aim);  // 删去所有值为aim的节点
	bool Search(CharString aim);//搜寻链表中第一个值为aim的节点
	void destroy(); //毁掉链表
	void Edit(fileLink& t);
	

};





























#endif