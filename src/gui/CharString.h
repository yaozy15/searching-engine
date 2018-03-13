#ifndef CharString_H
#define CharString_H
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
/*
本类为自定义的字符串类
储存的是宽字符
本类包含了所有的实验要求的函数
还重载了一些函数
特殊说明本类由于重载了=所以不再写assign函数

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
	CharString(const CharString &s); //拷贝构造函数
	CharString(string temp);
	~CharString();
public:
	int substring(int start, int end, CharString& target);
	int getsubCharString(int i, CharString& target);
	void concat(const CharString& st); // 字符串的连接
	CharString addCharString(const CharString& st); //字符串相加
	int indexOf(CharString &s, CharString &st);//内部用KMP算法实现
	bool strcmp_CharString(CharString *p, CharString *q); //两个字符串指针的比较
	int size() //获得字符串的长度
	{
		return length;
	}
	
public:
	wchar_t* getData()
	{
		return data;
	}//获得类包含的宽字符串
	//因为重载了等号所以不再写assign函数
	CharString& operator=(const char *sourceCharString); //将一个字符串先转换成宽字符串然后赋值给自定义的字符串
	CharString& operator=(CharString &aim);//字符串之间的赋值
	CharString& operator=(wchar_t* aim); //
	bool operator>(const CharString &compare) const;//
	bool operator<(const CharString &compare) const;//
	bool operator==(const CharString &compare) const;//
	bool strcmp_wCharString(CharString p, CharString q) //比较函数
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