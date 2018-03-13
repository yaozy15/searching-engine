#include"find_key_word.h"
//#include"dictionary.h"
#define MAX 10

/*
该类负责中文分词
主要含有三个函数
void initDictionary（）函数主要是用来载入词典
CharStringLink find_key（CharString）主要是使用最大正向分配算法进行中文分词一次加载十四个字符然后进行分割
void divideWords(）是根据字典树写的中文分词算法



*/


find_chinese::find_chinese()
{
	 
	regist = 0;
	oregist = 0;
}
/*
字典的载入，载入到哈希表

*/
void find_chinese::initDictionary( )
{
	
	ifstream in;
	 string myCharString;
	 in.open("词库\\词库.dic");
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
最大正向匹配中文算法， 用哈希表进行查询。

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
用来对query.txt 中的关键字进行分词

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
		if(!beChinese(context.data[i]))  //如果该字符不是中文就直接跳过
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
			if(isChinese(temp))  //判断该单字是否是中文
			{
				bool judge_repeat = verb.add(temp); //
			
			}

		}
		

	}




}


//用来处理query.txt的关键词将处理结果输入到result.txt中
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
			  //该出用这个函数是为了取出txt文档的前三个文档格式字符使文档能够顺利的解读
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
//获取关键词在文档中出现的次数
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
//析构栈
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