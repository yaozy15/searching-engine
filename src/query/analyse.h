#ifndef ANALYSE_H
#define ANALYSE_H
//#include<iostream>
//using namespace std;
#include"CharString.h"
#include"CharStringLink.h"
#include"stack.h"
#include<string>
/*
 ������Ҫ������ҳ�ؼ���Ϣ��ץȡ
 extractInfo����Ϊʵ����Ҫ��ĵĽӿ�����������ҳ

*/
class analyse_web
{
public:
	analyse_web()
	{


	}
	~analyse_web()
	{

	}
public:
	void extractInfo(string filename ,wofstream &ff); // �ļ��Ĺؼ���Ϣ����ȡ
	void fastExtractInfo(string filename, wofstream &ff); //��ҳ�����Ż�
public:
	StringLink analyse_result; 
	CharString question_CharString; //�����ǩ������
	CharString author_CharString;  //����
	CharString context_CharString; //����
	CharString title_CharString;   //����
	Stack<CharString>problem; //�����ǩ���ݵ���ȡ

};



















#endif