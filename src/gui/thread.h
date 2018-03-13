#ifndef THREAD_H
#define THREAD_H
#include<iostream>
#include<hash_map>
//#include"dictionary.h"
#include"Windows.h"
#include<fstream>
#include<string>
#include<vector>
#include"CharString.h"
#include"stack.h"
#include<locale>
#include"analyse.h"
#include"CharStringLink.h"
#include"find_key_word.h"
#include"Tries.h"
#include<tchar.h>
#include<io.h>
#include<functional>
#include<map>
#include <unordered_set>
#include <QThread>
#include"screen.h"
/*
进度条的实现

*/
class WorkerThread : public QThread
{
	Q_OBJECT

public:
	explicit WorkerThread(screen *parent)
		: QThread(parent)
	{
		father = parent;
	}
public:
	screen* father;
public:
	virtual void run() Q_DECL_OVERRIDE 
	{
		wchar_t *coma = L"，";
	    CharString Coma;
	    Coma = coma;
		int nValue = 0;
		father->web_chinese.initDictionary();
		for(int i = 0; i < father->files.size(); i++)
		{

			analyse_web web;
			wofstream ff("output\\" + father->files[i].substr(6, father->files[i].length() - 10) + "info");

			ff.imbue(std::locale("chs"));
			//web.fastExtractInfo(father->files[i], ff);
			web.simplifyInfo(father->files[i], ff);
			wofstream fs("output\\" + father->files[i].substr(6, father->files[i].length() - 10) + "txt");
			fs.imbue(std::locale("chs"));
			string name = father->files[i].substr(6, father->files[i].length() - 10) + "info";
			string name1 = "output\\" + father->files[i].substr(6, father->files[i].length() - 10) + "txt";
			CharString filename;
			filename = name.c_str();
			father->web_chinese.dividefast_key(web.context_CharString, filename, i + 1, name1);
			emit resultReady(i + 1);
		}
		emit resultReady(-1);

	}
signals:
	void resultReady(int value);
};





















#endif