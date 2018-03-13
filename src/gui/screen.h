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
������Ҫ�Ĺ��ܾ��ǽ���UI��ʵ�֣����������ö��̣߳����������Ľ�������һ������������ϸ�Ľ��ܣ����ﲻ���ظ�


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
    // ���½���
    void handleResults(int value)
    {
		if(value == -1)
		{
			delete m_pProgressBar;
			return;
		}
        m_pProgressBar->setValue(value);
		
    }

    // �����߳�
    void startThread();
  

public:
	find_chinese web_chinese;
	QProgressBar *m_pProgressBar; //������
	Stack<QString>myString;
   // WorkerThread *m_workerThread;
	vector<string> files;
	vector<QString> sQ;
private:
	Ui::screenClass ui;
};

#endif // SCREEN_H
