#include "screen.h"
#include <qtimer.h>
#include"thread.h"
#include<qmessagebox.h>
#include<qnetwork.h>
void getFiles(string path, vector<string>& files)
{
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign("input").append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if((fileinfo.attrib & _A_SUBDIR))
			{

				if(strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{

					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);


				}


			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));

			}
		}while(_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);


	}






}
screen::screen(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	char *filePath = "input";
	wchar_t *coma = L"，";
	CharString Coma;
	Coma = coma;
	getFiles(filePath, files);
	StringLink Link;
	m_pProgressBar = new QProgressBar(this);
    //设置文本、进度条取值范围
    m_pProgressBar->setFixedHeight(25);
	m_pProgressBar->setFixedWidth(100);
    m_pProgressBar->setRange(0, files.size());
    m_pProgressBar->setValue(0);

    QVBoxLayout *pLayout = new QVBoxLayout();
     
    pLayout->addWidget(m_pProgressBar);
    pLayout->setSpacing(50);
    pLayout->setContentsMargins(10, 10, 10, 10);
    setLayout(pLayout);
	QTimer::singleShot(50, this, SLOT(startThread()));

   
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(getContext()));
	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(getText(QListWidgetItem *)));
}

screen::~screen()
{

}
/*
在listWidget显示网页名称

*/
void screen::getContext()
{
	ui.listWidget->clear();
	QString text = ui.lineEdit->text();
	QByteArray ba = text.toLatin1();  
	char *mm = ba.data();  
	string str = text.toStdString();
	int n = 0;
	CharString block;
	block = str.c_str();
	int l = str.length();
	int begin = 0;
	int end = 0;
	fileLink fileVerb;
	StringLink verb;
	web_chinese.shortdividefast_key(block, verb);
	CharStringNode *q = verb.head;
	myString.Top = 0;
	while(q)
	{
		TreeNode *temp = web_chinese.balanceTree.Search(q->context);
		if(temp)
		{

			fileVerb.Edit(temp->fileSet);
			myString.push(QString::fromStdWString(q->context.data));
		}
		q = q->next;

	}
	if(myString.Top == 0)
	{
		int ret = QMessageBox::warning(this, QObject::tr("Warning"),
        QObject:: tr("The document is not correct, do you want to continue"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
	file *p = fileVerb.head;
	int i;
	for(i = 0; i < fileVerb.size; i++)
	{
			  
			//for(int j = 0; j < fileVerb.size - i; j++)
		    while(p)
			{
				if(p->next)
				{
					if(p->rank > p->next->rank)
				    {
						int temp;
						CharString te;
						temp = p->rank;
						te = p->filename;
						p->rank = p->next->rank;
						p->next->rank = temp;
						p->filename = p->next->filename;
						p->next->filename = te;
						

					}

				}
				p = p->next;

			}
			 p = fileVerb.head;
	}
	p = fileVerb.head;
	while(p)
	{
		QString temp = QString::fromStdWString(p->filename.data);
		ui.listWidget->addItem(temp);
		p = p->next;
	}


}
/*
在testbrowser上显示文章内容

*/
void screen::getText(QListWidgetItem *item)
{
	ui.textBrowser->clear();
	ifstream in;
	string myCharString = item->text().toStdString();
	 in.open("output\\" + myCharString);
	string Text;
	getline(in, Text);
	int nLen = MultiByteToWideChar(CP_ACP, 0, Text.c_str(), -1, NULL, 0);
	wchar_t* pResult = new wchar_t[nLen + 1];
	MultiByteToWideChar(CP_ACP, 0, Text.c_str(), -1, pResult, nLen);
	QString stock = QString::fromStdWString(pResult);
	QString aim = item->text();
	int l = myString.size();
	while(myString.size() > 0)
	{
		QString word = myString.top();
		int p1 = 0;
		int p2 = 0;
		QString line;
		while(1)
		{
			p1 = stock.indexOf(word, p2);
			if(p1 < 0)
				break;
			line += stock.mid(p2, p1 - p2);
			line += "<font color=red>";
			line += word;
			line += "<font color=black>";
			p2 = p1 + word.length();


		}
		line += stock.mid(p2, stock.length() - p2);
		stock = line;
		myString.pop();

	}
	myString.Top = l;
	
	ui.textBrowser->setText(stock);
	

	


}


void screen::startThread()
{
	
    WorkerThread *workerThread = new WorkerThread(this);
    connect(workerThread, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
    // 线程结束后，自动销毁
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    workerThread->start();
}