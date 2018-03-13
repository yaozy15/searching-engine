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
本类主要用来进行中文分词
find_key()函数是按课上讲的中文分词方式进行操作操作复杂度为O(n2)
divideWords()函数是实验要求的接口本实验用这个进行中文分词，复杂度可达到O(n)
更快一些
initDictionary()用来加载词典用中文字典树实现


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
	Trie fast_dictionary; //构建的中文字典树
	Stack<StringLink> resultSet; //所得的分词结果
	AVLTree balanceTree;
	unordered_set<CharString, hash_new> v;
	hashtable v1;
public:
	StringLink divideWords(CharString &context, wofstream &fs, CharString &filename, string name);//中文分词算法
	void dividefast_key(CharString context, CharString &filename, int i, string name); 
	void shortdividefast_key(CharString context, StringLink& verb); //用来对query.txt中的关键词进行分词
	void initDictionary(); //加载词典
	void get_qurey(wofstream &fs);
	void Get_qurey(wofstream &fs);
	int get_num(int i, StringLink& listWord);
	bool isChinese(CharString &s);
	bool beChinese(wchar_t s);
	void Delete();
};







#endif