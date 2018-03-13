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
using namespace std;

/*

������������ȡinput�ļ��е�������vector�������������


*/
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

/*
���������ڶ���ȡ���ļ����ֽ�����ҳ���������ķִʲ��Ұѽ�������output�ļ��е���Ӧ�ļ���

*/
int main()
{
	char *filePath = "input";
	wchar_t *coma = L"��";
	CharString Coma;
	Coma = coma;
	vector<string> files;
	getFiles(filePath, files);
	find_chinese web_chinese;
	web_chinese.initDictionary();
	StringLink Link;
	cout<<"dictionary is loaded"<<endl;
	//system("pause");
	for(int i = 0; i < files.size(); i++)
	{

		analyse_web web;
		wofstream ff("output\\" + files[i].substr(6, files[i].length() - 10) + "info");

		ff.imbue(std::locale("chs"));
		web.fastExtractInfo(files[i], ff);
		//web.extractInfo(files[i], ff);
		cout<<i + 1<<"info"<<" ";
		
		wofstream fs("output\\" + files[i].substr(6, files[i].length() - 10) + "txt");
		fs.imbue(std::locale("chs"));
		string name = files[i].substr(6, files[i].length() - 10) + "txt";
		CharString filename;
		filename = name.c_str();
		web_chinese.divideWords(web.context_CharString, fs, filename, i + 1);
		cout<<i + 1<<"txt"<<" "<<endl;
	}
	//system("pause");
	wofstream fs("result.txt");
	fs.imbue(std::locale("chs"));
	web_chinese.get_qurey(fs);
	fs.close();
    web_chinese.Delete();
	web_chinese.balanceTree.destroy(web_chinese.balanceTree.root);
	for(int i = 0; i < web_chinese.v1.size;i++)
	{
		web_chinese.v1.elem[i].destroy();

	}
	cout<<"the program is executed successfully.";
	system("pause");

	return 0;
}