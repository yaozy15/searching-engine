#ifndef FILELINK_H
#define FILELINK_H
#include"CharString.h"
/*
�������ĵ�����Ĺ���

*/
struct file
{
    CharString filename; //�ڵ㴢����ַ���
	int rank; //�ĵ������򣨵�ַ��
	CharString stockword; //���ĵ������ĸ��ַ���
	int fre; //��Ƶ
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
	CharString stockWord; //���ĵ����������ĸ���
public:
	void Add(CharString &p, int rank); // ����ֵΪp�Ľڵ�
	void Addplus(CharString &p, int rank, file* &q);
	bool Remove(CharString aim);  // ɾȥ����ֵΪaim�Ľڵ�
	bool Search(CharString aim);//��Ѱ�����е�һ��ֵΪaim�Ľڵ�
	file* find(CharString aim);//��Ѱ�����е�һ��ֵΪaim�Ľڵ�
	void destroy(); //�ٵ�����
	void Edit(fileLink& t); //�༭�ĵ�����
	

};





























#endif