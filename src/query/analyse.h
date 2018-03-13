#ifndef ANALYSE_H
#define ANALYSE_H
//#include<iostream>
//using namespace std;
#include"CharString.h"
#include"CharStringLink.h"
#include"stack.h"
#include<string>
/*
 本类主要用于网页关键信息的抓取
 extractInfo函数为实验所要求的的接口用来解析网页

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
	void extractInfo(string filename ,wofstream &ff); // 文件的关键信息的提取
	void fastExtractInfo(string filename, wofstream &ff); //网页解析优化
public:
	StringLink analyse_result; 
	CharString question_CharString; //问题标签的内容
	CharString author_CharString;  //作者
	CharString context_CharString; //正文
	CharString title_CharString;   //标题
	Stack<CharString>problem; //问题标签内容的提取

};



















#endif