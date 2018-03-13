#ifndef FILELINK_H
#define FILELINK_H
#include"CharString.h"
#include<string>
struct file
{
	string name;
    CharString filename; //�ڵ㴢����ַ���
	int rank;
	file *next; //��һ���ڵ�
};
class fileLink
{

public:
	fileLink();
	~fileLink();
public:
	file *head; //�ַ�������ı�ͷ
	file *tail; //�ַ�������ı�β
	int size; //�ַ�������ĳ���
public:
	void Add(CharString &p, int rank, string &name); // ����ֵΪp�Ľڵ�
	bool Remove(CharString aim);  // ɾȥ����ֵΪaim�Ľڵ�
	bool Search(CharString aim);//��Ѱ�����е�һ��ֵΪaim�Ľڵ�
	void destroy(); //�ٵ�����
	void Edit(fileLink& t);
	

};





























#endif