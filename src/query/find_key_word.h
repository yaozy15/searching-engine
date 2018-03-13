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
本类主要用来进行网页解析和中文分词，该类较实验一时出现了很大的变化。
首先该类加载字典不是构建字典树了而是用哈希表储存字典，原因是字典树查询效率较慢于哈希表。
其次中文分词不再是在字典树中查找，而是用老师课上讲的最大正向匹配算法通过哈希表查询来进行分词。



*/

struct hash_new
{

	
	size_t operator() (const CharString & s) const
    {  
		int ch = 0;
		int hash = 0;
		for(int i = 0; i < s.length; i++)
		{
			ch = (unsigned int)(s.data[i]);
			hash = hash * 131 + ch;

		}
		return hash * 2;
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
	Trie fast_dictionary; //构建的中文字典树（实验二中由于速度过慢不再需要了）
	Stack<StringLink> resultSet; //所得每一个网页的分词结果
	AVLTree balanceTree;//构建的平衡树
	unordered_set<CharString, hash_new> v;
	hashtable v1;//构建的哈希表
public:
	void divideWords(CharString context, wofstream &ff, CharString &filename, int i);  //实验二所写的优化了的中文分词算法
	void shortdividefast_key(CharString context, StringLink& verb); //用来对query.txt中的关键词进行分词
	void initDictionary(); //加载词典
	void get_qurey(wofstream &fs);//用来处理query.txt的关键词将处理结果输入到result.txt中
	int get_num(int i, StringLink& listWord); //获取关键词在文档中出现的次数
	void Delete();  // 析构栈
	bool isChinese(CharString &s); //判断该单字是否是中文
	bool beChinese(wchar_t s) //判断该宽字符是否是中文
	{
		if(s > 0x4000 && s < 0x9fbb)
			return true;
		else
			return false;


	}
};







#endif