#ifndef CharString_H
#define CharString_H
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
/*
����Ϊ�Զ�����ַ�����
������ǿ��ַ�
������������е�ʵ��Ҫ��ĺ���
��������һЩ����
����˵����������������=���Բ���дassign����

*/
class CharString
{

public:
	char *str;
	wchar_t *data;
	int length;
	int *next;
	bool beTag;
	int maxlength;
public:
	CharString();
	CharString(const char* str);
	CharString(const wchar_t *s);
	CharString(const CharString &s); //�������캯��
	CharString(string temp);
	~CharString();
public:
	int substring(int start, int end, CharString& target);
	int getsubCharString(int i, CharString& target);
	void concat(const CharString& st); // �ַ���������
	CharString addCharString(const CharString& st); //�ַ������
	int indexOf(CharString &s, CharString &st);//�ڲ���KMP�㷨ʵ��
	bool strcmp_CharString(CharString *p, CharString *q); //�����ַ���ָ��ıȽ�
	int size() //����ַ����ĳ���
	{
		return length;
	}
	
public:
	wchar_t* getData()
	{
		return data;
	}//���������Ŀ��ַ���
	//��Ϊ�����˵Ⱥ����Բ���дassign����
	CharString& operator=(const char *sourceCharString); //��һ���ַ�����ת���ɿ��ַ���Ȼ��ֵ���Զ�����ַ���
	CharString& operator=(CharString &aim);//�ַ���֮��ĸ�ֵ
	CharString& operator=(wchar_t* aim); //
	bool operator>(const CharString &compare) const;//
	bool operator<(const CharString &compare) const;//
	bool operator==(const CharString &compare) const;//
	bool strcmp_wCharString(CharString p, CharString q) //�ȽϺ���
    {
	if(wcscmp(p.data, q.data) == 0)
		return true;
	else
		return false;


	}
	bool reset();
	int concat(const CharString& source, CharString& target);
	int push_back(const wchar_t c);
};






















#endif