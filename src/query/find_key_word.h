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
������Ҫ����������ҳ���������ķִʣ������ʵ��һʱ�����˺ܴ�ı仯��
���ȸ�������ֵ䲻�ǹ����ֵ����˶����ù�ϣ�����ֵ䣬ԭ�����ֵ�����ѯЧ�ʽ����ڹ�ϣ��
������ķִʲ��������ֵ����в��ң���������ʦ���Ͻ����������ƥ���㷨ͨ����ϣ���ѯ�����зִʡ�



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
	Trie fast_dictionary; //�����������ֵ�����ʵ����������ٶȹ���������Ҫ�ˣ�
	Stack<StringLink> resultSet; //����ÿһ����ҳ�ķִʽ��
	AVLTree balanceTree;//������ƽ����
	unordered_set<CharString, hash_new> v;
	hashtable v1;//�����Ĺ�ϣ��
public:
	void divideWords(CharString context, wofstream &ff, CharString &filename, int i);  //ʵ�����д���Ż��˵����ķִ��㷨
	void shortdividefast_key(CharString context, StringLink& verb); //������query.txt�еĹؼ��ʽ��зִ�
	void initDictionary(); //���شʵ�
	void get_qurey(wofstream &fs);//��������query.txt�Ĺؼ��ʽ����������뵽result.txt��
	int get_num(int i, StringLink& listWord); //��ȡ�ؼ������ĵ��г��ֵĴ���
	void Delete();  // ����ջ
	bool isChinese(CharString &s); //�жϸõ����Ƿ�������
	bool beChinese(wchar_t s) //�жϸÿ��ַ��Ƿ�������
	{
		if(s > 0x4000 && s < 0x9fbb)
			return true;
		else
			return false;


	}
};







#endif