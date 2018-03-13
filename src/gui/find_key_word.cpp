#include"find_key_word.h"
//#include"dictionary.h"
#define MAX 9

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
�ֵ������

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
�������ƥ�������㷨

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
�ֵ���������������Ӵ��㷨

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