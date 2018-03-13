#include"find_key_word.h"
//#include"dictionary.h"
#define MAX 10

/*
���ฺ�����ķִ�
��Ҫ������������
void initDictionary����������Ҫ����������ʵ�
CharStringLink find_key��CharString����Ҫ��ʹ�������������㷨�������ķִ�һ�μ���ʮ�ĸ��ַ�Ȼ����зָ�
void divideWords(���Ǹ����ֵ���д�����ķִ��㷨



*/


find_chinese::find_chinese()
{
	 
	regist = 0;
	oregist = 0;
}
/*
�ֵ�����룬���뵽��ϣ��

*/
void find_chinese::initDictionary( )
{
	
	ifstream in;
	 string myCharString;
	 in.open("�ʿ�\\�ʿ�.dic");
	 int n  = 0;
	 while(getline(in, myCharString))
	 {
	 int l = myCharString.length();
	 if(n > 0)
	 {
	
	 CharString context;
	 context = myCharString.c_str();
	 v1.insert_ptr(context);
	 
	 }
	 n++;
   
	 }
	
	


}

find_chinese::~find_chinese()
{



}
/*
�������ƥ�������㷨�� �ù�ϣ����в�ѯ��

*/


void find_chinese::divideWords(CharString context, wofstream &ff, CharString &filename, int rank)
{
    StringLink stock;
	CharString tempCharString;
	tempCharString = context;
	CharString temp;
	int r;
	r = 1;
	int l = context.size();
	bool single_judge = false;
	bool tag = false;
	bool judge = false;
	int i, j;
	int max = MAX;
	for(i = 0; i < l; i++)
	{
		if(!beChinese(context.data[i]))
			continue;
		if(l < MAX)
			max = l;
		else
			max = MAX;
		for(j = max; j > 0; j--)
		{

			context.substring(i + 1, i + j, temp);
			if(v1.search(temp))
			{
				bool judge_repeat = stock.add(temp);
				if(judge_repeat)
				balanceTree.Insert(temp,filename, rank);
				i = i + j - 1;
				break;
				
			 }
			




		}
		if(j == 0)
		{
			if(isChinese(temp))
			{
				bool judge_repeat = stock.add(temp);
				if(judge_repeat)
				balanceTree.Insert(temp,filename, rank);
			}

		}
		

	}
		
			


	resultSet.push(stock);
//	return result;
}

/*
������query.txt �еĹؼ��ֽ��зִ�

*/
void find_chinese::shortdividefast_key(CharString context, StringLink& verb)
{

	CharString tempCharString;
	tempCharString = context;
	CharString temp;
	int r;
	r = 1;
	int l = context.size();
	bool single_judge = false;
	bool tag = false;
	bool judge = false;
	int i, j;
	int max = MAX;
	for(i = 0; i < l; i++)
	{
		if(!beChinese(context.data[i]))  //������ַ��������ľ�ֱ������
			continue;
		if(l < MAX)
			max = l;
		else
			max = MAX;
		for(j = max; j > 0; j--)
		{

			context.substring(i + 1, i + j, temp);
			if(v1.search(temp))
			{
				bool judge_repeat = verb.add(temp);
				i = i + j - 1;
				break;
				
			 }
			




		}
		if(j == 0)
		{
			if(isChinese(temp))  //�жϸõ����Ƿ�������
			{
				bool judge_repeat = verb.add(temp); //
			
			}

		}
		

	}




}


//��������query.txt�Ĺؼ��ʽ����������뵽result.txt��
void find_chinese::get_qurey(wofstream &fs)
{
	  ifstream in;
	  in.open("query.txt");
      string str;
	  int n1 = 0;
	  while(getline(in, str))
	  {
		  if(n1 == 0)
		  {
			  str = str.substr(3, str.length() - 3);
			  //�ó������������Ϊ��ȡ��txt�ĵ���ǰ�����ĵ���ʽ�ַ�ʹ�ĵ��ܹ�˳���Ľ��
		  }
		  fileLink fileVerb;
		  StringLink verb;
		  int begin = 0;
		  int end = 0;
		  int n = 0;
		  CharString block;
		  block = str.c_str();
		  int l = str.length();
		  for(int i = 0; i < block.length; i++)
		  {
			  if(block.data[i] == L' ')
			  {
				  end = i;
				  CharString temp;
				  block.substring(begin + 1, end, temp);
				  //verb.add(temp);
				  shortdividefast_key(temp, verb);
				  if(balanceTree.Search(temp))
				      fileVerb.Edit(balanceTree.Search(temp)->fileSet);
				  begin = end + 1;
				  n++;


			  }



		  }
		  if(n == 0)
		  {
			   CharString temp;
			   temp = str.c_str();
			   if(balanceTree.Search(temp))
               fileVerb.Edit(balanceTree.Search(temp)->fileSet);
			   //verb.add(temp);
			   shortdividefast_key(temp, verb);

		  }
		  else
		  {
			   CharString temp;
			   block.substring(begin + 1 , block.length, temp);
			   if(balanceTree.Search(temp))
			   fileVerb.Edit(balanceTree.Search(temp)->fileSet);
			   //verb.add(temp);
			   shortdividefast_key(temp, verb);
		  }
		  file *p = fileVerb.head;
		  while(p)
		  {

			  p->fre = get_num(p->rank, verb);
			  p = p->next;

		  }
		  p = fileVerb.head;
		  int i;
		  for(i = 0; i < fileVerb.size; i++)
		  {
			  
			//for(int j = 0; j < fileVerb.size - i; j++)
			while(p)
			{
				if(p->next)
				{
					if(p->fre < p->next->fre)
				    {
						int temp;
						CharString te;
						temp = p->rank;
						te = p->filename;
						p->rank = p->next->rank;
						p->next->rank = temp;
						p->filename = p->next->filename;
						p->next->filename = te;
						int n = p->fre;
						p->fre = p->next->fre;
					    p->next->fre = n;

					}

				}
				p = p->next;

			}
			 p = fileVerb.head;
		  }
		  
		  while(p)
		  {
			  fs<<"("<<p->rank<<","<<p->fre<<")";
			  p = p->next;
			  if(p)
				  fs<<" ";

		  }
		  fs<<std::endl;
		  n1++;
		  

	  }




}
//��ȡ�ؼ������ĵ��г��ֵĴ���
int find_chinese::get_num(int i, StringLink& listWord)
{
	int n = 0;
	CharStringNode*p = listWord.head;

	StringLink temp = resultSet.items[i - 1];
	CharStringNode*q = temp.head;
	while(p)
	{
		n = n + temp.investigate(p->context);
		p = p->next;


	}
	return n;


}
//����ջ
void find_chinese::Delete()
{
	while(resultSet.size())
	{
		resultSet.top().destroy();
		resultSet.pop();


	}



}

bool find_chinese::isChinese(CharString &s)
{
	if(s.data[0] > 0x4000 && s.data[0] < 0x9fbb)
		return true;
	else
		return false;


}