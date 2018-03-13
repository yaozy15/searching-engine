#ifndef TRIES_H
#define TRIES_H

#include"CharString.h"
#include<string>
/*
������Ҫ�����������ֵ����Ľ���
NodeΪ�����ֵ����Ľڵ�

*/
struct Node
{

	Node *son; //���ӽڵ�
	Node *brother; //�ֵܽڵ�
	bool beWord; //�Ƿ��������ʵ����ڵ�
	bool beRoot; //�Ƿ��Ǹ�
	CharString word;
	CharString words;
	wchar_t data_word; // ����Ŀ��ַ���
    
};
class Trie
{

public:
	Trie();
	~Trie(){}
public:
	Node *root;
public:
//	void addNode(CharString s); //�������ӽڵ�
	void insert_word(CharString &s); //�������ӽڵ�
    bool searchWord(CharString s); // ������ѯ��
	bool check_word(CharString s); // ������ѯ��
	//void addCharString(CharString s);
};

















#endif