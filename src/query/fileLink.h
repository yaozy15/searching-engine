#ifndef FILELINK_H
#define FILELINK_H
#include"CharString.h"
/*
该类是文档链表的构建

*/
struct file
{
    CharString filename; //节点储存的字符串
	int rank; //文档的排序（地址）
	CharString stockword; //该文档属于哪个字符串
	int fre; //词频
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
	CharString stockWord; //该文档链表属于哪个词
public:
	void Add(CharString &p, int rank); // 增加值为p的节点
	void Addplus(CharString &p, int rank, file* &q);
	bool Remove(CharString aim);  // 删去所有值为aim的节点
	bool Search(CharString aim);//搜寻链表中第一个值为aim的节点
	file* find(CharString aim);//搜寻链表中第一个值为aim的节点
	void destroy(); //毁掉链表
	void Edit(fileLink& t); //编辑文档链表
	

};





























#endif