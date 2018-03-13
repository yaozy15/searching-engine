#include"find_key_word.h"
//#include"dictionary.h"
#define MAX 9

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
字典的载入

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
	// v.insert(context);
	 v1.insert_ptr(context);
	 
	 }
	 n++;
   
	 }
	
	


}

find_chinese::~find_chinese()
{



}
/*
最大正向匹配中文算法

*/

void find_chinese::dividefast_key(CharString context, CharString &filename, int rank, string name)
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
	for(i = 0; i < l; i++)
	{
		if(!beChinese(context.data[i]))
			continue;
		for(j = MAX; j > 0; j--)
		{

			context.substring(i + 1, i + j, temp);
			if(v1.search(temp))
			{
				bool judge_repeat = stock.add(temp);
				//ff<<temp.data<<std::endl;
				if(judge_repeat)
				balanceTree.Insert(temp,filename, rank, name);
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
				balanceTree.Insert(temp,filename, rank, name);
			}

		}
		

	}
		
			


	resultSet.push(stock);
	//return result;
}
/*
字典树搜索最大中文子串算法

*/
StringLink find_chinese::divideWords(CharString &context, wofstream &fs, CharString &filename, string name)
{
	StringLink getResult;
	//CharStringLink stock;
	int l = context.size();
	int n = 1;
	CharString temp;
	temp = context;
	int begin = 0; 
	int end = 0;
	int flag = 0;
	//int l = context.size();
	Node *cur;
	bool judge = false;
	while(begin < l)
	{
		cur = fast_dictionary.root->son;
		flag = begin;
		end = begin;
		judge = false;
		while(flag < l && cur != NULL)
		{
			if(cur->data_word == temp.data[flag])
			{
				if(cur->beWord == true)
				{
					end = flag;
					//judge = true;
					//break;

				}
				cur = cur->son;
				flag++;

			}
			else
				cur = cur->brother;

		}
		if(end > begin) //
		{
			CharString stock;
			context.substring(begin + 1, end + 1, stock);
			getResult.add(stock);
			balanceTree.Insert(stock, filename, resultSet.size() + 1, name);
			fs<<stock.data<<std::endl;

		}
		begin = end + 1;



	}
	resultSet.push(getResult);
	//getResult.destroy();
	return resultSet.top();
//	return getResult;





}


void find_chinese::get_qurey(wofstream &fs)
{
	  ifstream in;
	  in.open("query.txt");
      string str;
	  int n1 = 0;
	  while(getline(in, str))
	  {
		  if(n1 > 0)
		  {
		  fileLink fileVerb;
		  StringLink verb;
		  int begin = 0;
		  int end = 0;
		  int n = 0;
		  CharString block;
		  block = str.c_str();
		  int l = str.length();
	    
		 
		 // fs<<block.data<<endl;
		  for(int i = 0; i < block.length; i++)
		  {
			  if(block.data[i] == L' ')
			  {
				 // string subtemp = str.substr(begin, end - begin);
				  end = i;
				  CharString temp;
				  block.substring(begin + 1, end, temp);
				  
				  verb.add(temp);
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
			   verb.add(temp);

		  }
		  else
		  {
			   CharString temp;
			  // temp = str.substr(begin, str.length() - begin).c_str();
			   block.substring(begin + 1 , block.length, temp);
			   if(balanceTree.Search(temp))
			   fileVerb.Edit(balanceTree.Search(temp)->fileSet);
			   verb.add(temp);
		  }
		  file *p = fileVerb.head;
		  while(p)
		  {
			  fs<<"("<<p->rank<<","<<get_num(p->rank, verb)<<")";
			  p = p->next;

		  }
		  //if(p)
		  fs<<std::endl;
		  }
		  n1++;
		  

	  }




}

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

void find_chinese::Delete()
{
	while(resultSet.size())
	{
		resultSet.top().destroy();
		resultSet.pop();


	}



}
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
void find_chinese::Get_qurey(wofstream &fs)
{
	  ifstream in;
	  in.open("query.txt");
      string str;
	  int n1 = 0;
	  while(getline(in, str))
	  {
		  if(n1 > 0)
		  {
		  fileLink fileVerb;
		  StringLink verb;
		  int begin = 0;
		  int end = 0;
		  int n = 0;
		  CharString block;
		  block = str.c_str();
		  int l = str.length();
	    
		 
		 // fs<<block.data<<endl;
		  for(int i = 0; i < block.length; i++)
		  {
			  if(block.data[i] == L' ')
			  {
				 // string subtemp = str.substr(begin, end - begin);
				  end = i;
				  CharString temp;
				  block.substring(begin + 1, end, temp);
				  
				  verb.add(temp);
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
			   verb.add(temp);

		  }
		  else
		  {
			   CharString temp;
			  // temp = str.substr(begin, str.length() - begin).c_str();
			   block.substring(begin + 1 , block.length, temp);
			   if(balanceTree.Search(temp))
			   fileVerb.Edit(balanceTree.Search(temp)->fileSet);
			   verb.add(temp);
		  }
		  file *p = fileVerb.head;
		  CharStringNode *q = verb.head;

		  while(p)
		  {

			 // fs<<"("<<p->rank<<","<<get_num(p->rank, verb)<<")";
			  fstream in;
	          in.open(p->name);
              string str;
	          int n = 0;
			  int i = 0;
	          while(getline(in, str))
			  {
				if(i > 0)
				{
	               CharString context;
	               context = str.c_str();
				   while(q)
				   {
				   if(wcscmp(context.data, q->context.data) == 0)
					   n++;
				   q = q->next;
				   }
				   q = verb.head;
				}
				i++;
			  }
			  fs<<"("<<p->rank<<","<<n<<")";
			  n = 0;
			  p = p->next;

		  }
		  //if(p)

		  fs<<std::endl;
		  }
		  n1++;
		  

	  }




}

bool find_chinese::isChinese(CharString &s)
{
	if(s.data[0] > 0x4000 && s.data[0] < 0x9fbb)
		return true;
	else
		return false;

}

bool find_chinese::beChinese(wchar_t s)
{
	if(s > 0x4000 && s < 0x9fbb)
		return true;
	else
		return false;


}