#ifndef CharStringLINK_H
#define CharStringLINK_H
#include"CharString.h"
/*
CharStringNodeΪ�ַ��������Ԫ��
�����ַ���
CharStringLink��Ϊ�ַ�������

*/
struct CharStringNode
{
    CharString context; //�ڵ㴢����ַ���
	int num; //�ôʵĴ�Ƶ
	CharStringNode *next; //��һ���ڵ�
};
class StringLink
{

public:
	StringLink();
	~StringLink();
public:
	CharStringNode *head; //�ַ�������ı�ͷ
	CharStringNode *tail; //�ַ�������ı�β
	int size; //�ַ�������ĳ���
	bool beContext; //�Ƿ�Ϊ��ǩ
public:
	bool add(CharString &p); // ����ֵΪp�Ľڵ�
	bool addNode(CharString &p);
	bool remove(CharString aim);  // ɾȥ����ֵΪaim�Ľڵ�
	CharStringNode* search(CharString aim);//��Ѱ�����е�һ��ֵΪaim�Ľڵ�
	int investigate(CharString &aim); //��û��ַ��������йؼ��ʵĴ�Ƶ
	void destroy(); //�ٵ����� 
	

};


#endif