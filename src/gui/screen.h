#ifndef SCREEN_H
#define SCREEN_H
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
#include<vector>
#include"CharStringLink.h"
#include"find_key_word.h"
#include"Tries.h"
#include<tchar.h>
#include<io.h>
#include<functional>
#include<map>
#include <unordered_set>
#include<qnetwork.h>
#include<qprogressbar.h>
using namespace std;
#include <QtWidgets/QMainWindow>
#include "ui_screen.h"
/*
该类主要的功能就是进行UI的实现，进度条采用多线程，其他函数的介绍在另一个程序中有详细的介绍，这里不再重复


*/
class WorkerThread;
class screen : public QMainWindow
{
	Q_OBJECT

public:
	screen(QWidget *parent = 0);
	~screen();
public slots:
	void getContext();
	void getText(QListWidgetItem *);
    // 更新进度
    void handleResults(int value)
    {
		if(value == -1)
		{
			delete m_pProgressBar;
			return;
		}
        m_pProgressBar->setValue(value);
		
    }

    // 开启线程
    void startThread();
  

public:
	find_chinese web_chinese;
	QProgressBar *m_pProgressBar; //进度条
	Stack<QString>myString;
   // WorkerThread *m_workerThread;
	vector<string> files;
	vector<QString> sQ;
private:
	Ui::screenClass ui;
};

#endif // SCREEN_H
