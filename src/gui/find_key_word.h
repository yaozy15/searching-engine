#ifndef FIND_KEY_WORD_H
#define FIND_KEY_WORD_H
#include"CharString.h"
#include<fstream>
#include"CharStringLink.h"
#include<string>
#include"AVL.h"
#include"Windows.h"
//#include"dictionary.h"
#include"stack.h"
#include"Tries.h"
#include <tchar.h>
#include <Windows.h>
#include <io.h>
#include"fileLink.h"
#include <unordered_set>
#include<hash_map>
#include"myhash.h"
//#include"analyse.h"
using namespace std;
/*
������Ҫ�����������ķִ�
find_key()�����ǰ����Ͻ������ķִʷ�ʽ���в����������Ӷ�ΪO(n2)
divideWords()������ʵ��Ҫ��Ľӿڱ�ʵ��������������ķִʣ����ӶȿɴﵽO(n)
����һЩ
initDictionary()�������شʵ��������ֵ���ʵ��


*/

struct hash_new
{
//	hash<wchar_t*>s1;
	
	size_t operator() (const CharString & s) const
    {  
		int ch = 0;
		int hash = 0;
		
	/*	while(ch = (unsigned int)(*(t++)))
		{
			hash = hash * 131 + ch;
		}
		delete []t;*/
		for(int i = 0; i < s.length; i++)
		{
			ch = (unsigned int)(s.data[i]);
			hash = hash * 131 + ch;

		}
		return hash%200000;
	}

};

class find_chinese
{
public:
	find_chinese();
	~find_chinese();
public:
	CharString key; 
	StringLink result;
	int regist;
	int oregist;
	Trie fast_dictionary; //�����������ֵ���
	Stack<StringLink> resultSet; //���õķִʽ��
	AVLTree balanceTree;
	unordered_set<CharString, hash_new> v;
	hashtable v1;
public:
	StringLink divideWords(CharString &context, wofstream &fs, CharString &filename, string name);//���ķִ��㷨
	void dividefast_key(CharString context, CharString &filename, int i, string name); 
	void shortdividefast_key(CharString context, StringLink& verb); //������query.txt�еĹؼ��ʽ��зִ�
	void initDictionary(); //���شʵ�
	void get_qurey(wofstream &fs);
	void Get_qurey(wofstream &fs);
	int get_num(int i, StringLink& listWord);
	bool isChinese(CharString &s);
	bool beChinese(wchar_t s);
	void Delete();
};







#endif