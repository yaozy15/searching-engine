#ifndef TRIES_H
#define TRIES_H

#include"CharString.h"
#include<string>
/*
本类主要功能是中文字典树的建立
Node为中文字典树的节点

*/
struct Node
{

	Node *son; //儿子节点
	Node *brother; //兄弟节点
	bool beWord; //是否是完整词的最后节点
	bool beRoot; //是否是根
	CharString word;
	CharString words;
	wchar_t data_word; // 储存的宽字符串
    
};
class Trie
{

public:
	Trie();
	~Trie(){}
public:
	Node *root;
public:
//	void addNode(CharString s); //用来增加节点
	void insert_word(CharString &s); //用来增加节点
    bool searchWord(CharString s); // 用来查询词
	bool check_word(CharString s); // 用来查询词
	//void addCharString(CharString s);
};

















#endif