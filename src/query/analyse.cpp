#include"analyse.h"
#include"stack.h"
#include"CharString.h"
#include"CharStringLink.h"
#include<fstream>
#include<queue>
/*
extractInfo������Ҫ����������ҳ�ؼ���Ϣ����ȡ
��ʵ������ҷ�����ԭ����extractInfo��������ǩ���½�����һ�飬������ʵ���������д��һ���Ż�����ҳ��������fastExtractInfo��
ֻ��ջ����һ�ν������㹻�ˣ�������ٶȡ�

*/




void analyse_web::extractInfo(string filename ,wofstream &ff)
{
	ifstream in;
	in.open(filename);
	CharString whole_web;
	string temp;
	CharString result;
	CharString context;
	int n = 0;
	while(getline(in, temp))
	{
		context = temp.c_str();
		result.concat(context);
	    n++;
	}
	bool read_context = false;
	bool read = false;
	char *begin = "<";
	CharString start_tag;
	start_tag = begin;
	char *end = ">";
	CharString end_tag ;
	end_tag = end;
	Stack<CharString> v;
	//queue<CharString> v;
	int l = result.length;
	int i = 0;
	n = 0;
	bool judge;
	CharString tempCharString;
	tempCharString = result;
	while(1)
	{
		if(tempCharString.indexOf(tempCharString, start_tag) == 0)
		{
			while(tempCharString.indexOf(tempCharString, end_tag) != n - i)
			{
				n++;

			}
			
			CharString tempBlock;
			result.substring(i + 1, n + 1, tempBlock);
			tempBlock.beTag = true;
			v.push(tempBlock);
			if(n + 2 < l)
			result.substring(n + 2, l, tempCharString);
			else
				break;
			n++;
			i = n;
			
			
		}
		else if(tempCharString.indexOf(tempCharString, start_tag) > 0)
		{
	    	while(tempCharString.indexOf(tempCharString, start_tag) != n - i)
			{
				n++;

			}
			CharString tempBlockContext;
			result.substring(i + 1, n, tempBlockContext);
			tempBlockContext.beTag = false;
			v.push(tempBlockContext);
			if(n+1 < l)
			result.substring(n + 1, l, tempCharString);
			else
				break;
			
			i = n;
		}
		else
			break;

		



	}
	v.reverse();
	bool had = false;
	int num = v.size();
	CharString block;
	CharString head_title;
	CharString paragraph;
	char *Paragraph = "content";
	paragraph = Paragraph;
	CharString Title;
	char *headTitle = "headline-title";
	head_title = headTitle;
	char *title = "<title>";
	Title = title;
	CharString Pcontext;
	char *pcontext = "<p>";
	Pcontext = pcontext;
	CharString _Pcontext;
	char *_pcontext = "</p>";
	_Pcontext = _pcontext;
	CharString Lcontext;
	char *lcontext = "<li>";
	Lcontext = lcontext;
	CharString _Lcontext;
	char *_lcontext = "</li>";
	_Lcontext = _lcontext;
	CharString h;
	char *h2 = "</h2>";
	h = h2;
	CharString Bio;
	char *bio = "bio";
	Bio = bio;
	CharString Strong;
	char *strong = "strong";
	Strong = strong;
	CharString Href;
	char *href = "href";
	Href = href;
	CharString Http;
	char *http = "http";
	Http = http;
	wchar_t *no_use = L"�͹٣���ƪ��������˼��";
	CharString noUse(no_use);
	wchar_t *no_use_two = L"�ٹ���";
	CharString noUse_two;
	noUse_two = no_use_two;
	CharString question;
	char *questionTitle = "question-title";
	question = questionTitle;
	char *_author = "author";
	CharString author;
	author = _author;
	Stack<CharString>ts;
	while(v.size() > 0)
	{
      if(v.top().beTag == true)
	  {
		if(v.top().indexOf(v.top(), head_title) >= 0 )
		{
			v.pop();
		 
	        v.pop();
		}
		else if(v.top().indexOf(v.top(), Title) >= 0)
		{
			v.pop();
			title_CharString = v.top();

		}
		else if(v.top().indexOf(v.top(), question) >= 0 )
		{
			v.pop();    
			problem.push(v.top());
			question_CharString = v.top();
		    had = true;

		}
	    else if(v.top().indexOf(v.top(), author) >= 0)
		{
			v.pop();
		    author_CharString = v.top();

		}
		else if(v.top().indexOf(v.top(), Bio) >= 0)
		{
			//read_context = true;
			v.pop();
		    v.pop();

		}
		else if(v.top().indexOf(v.top(), paragraph) >= 0)
		{
			read_context = true;
			v.pop();
		    //v.pop();

		}
		else if(v.top().indexOf(v.top(), Pcontext) >= 0 && read_context == true)
		{
			 v.pop();
			 while(v.top().indexOf(v.top(), _Pcontext) == -1)
			 {
			 
			    if(v.top().beTag == false && v.top().indexOf(v.top(), noUse) == -1 && v.top().indexOf(v.top(), Href) == -1 && v.top().indexOf(v.top(), Http) == -1&& v.top().indexOf(v.top(), noUse_two) == -1)
				{
				     if(context_CharString.size() == 0)
				     {
					   context_CharString = v.top();
					   ff<<context_CharString.data;
				     }
				     else
					 {
						 context_CharString.concat(v.top());
					 ff<<v.top().data;
					 }
					  //context_CharString = context_CharString + v.top();
					  v.pop();

				}
				else
					v.pop();

			}
		
			v.pop();
		 }
		 else if(v.top().indexOf(v.top(), Lcontext) >= 0 )
		 {
			 v.pop();
			 while(v.top().indexOf(v.top(), _Lcontext) == -1)
			 {
			 
			    if(v.top().beTag == false)
				{
				     if(context_CharString.size() == 0)
				     {
					   context_CharString = v.top();
					   ff<<v.top().data;
				     }
				     else
					 {
					  //context_CharString = context_CharString + v.top();
					  context_CharString.concat(v.top());
					  ff<<v.top().data;
					 }
					  v.pop();

				}
				else
					v.pop();

			}
		
			v.pop();
		 }
		 else
			 v.pop();
		}
	  else
		  v.pop();
	}
	ff.close();


}


void analyse_web::fastExtractInfo(string filename, wofstream &ff)
{
	CharString question;
	char *questionTitle = "question-title";
	question = questionTitle;
	char *_author = "author";
	CharString author;
	author = _author;
	CharString head_title;
	CharString Title;
	char *headTitle = "headline-title";
	head_title = headTitle;
	char *title = "<title>";
	Title = title;

	CharString paragraph;
	char *Paragraph = "content";
	paragraph = Paragraph;


	CharString Pcontext;
	char *pcontext = "<p>";
	Pcontext = pcontext;

	CharString Lcontext;
	char *lcontext = "<li>";
	Lcontext = lcontext;

	CharString Strong;
	char *strong = "strong";
	Strong = strong;

	CharString Href;
	char *href = "href";
	Href = href;

	CharString Http;
	char *http = "http";
	Http = http;

	wchar_t *no_use = L"�͹٣���ƪ��������˼��";
	CharString noUse(no_use);

	wchar_t *no_use_two = L"�ٹ���";
	CharString noUse_two;
	noUse_two = no_use_two;

	ifstream in;
	in.open(filename);
	CharString whole_web;
	string temp;
	CharString result;
	CharString context;
	int n = 0;
	while(getline(in, temp))
	{
		context = temp.c_str();
		result.concat(context);
	    n++;
	}
	bool read_context = false;
	bool read = false;

	char *begin = "<";
	CharString start_tag;
	start_tag = begin;

	char *end = ">";
	CharString end_tag ;
	end_tag = end;

	Stack<CharString> v;
	int l = result.length;
	int i = 0;
	n = 0;
	bool judge;
	CharString tempCharString;
	tempCharString = result;
	while(1)
	{
		if(tempCharString.indexOf(tempCharString, start_tag) == 0)
		{
			while(tempCharString.indexOf(tempCharString, end_tag) != n - i)
			{
				n++;

			}
			
			CharString tempBlock;
			result.substring(i + 1, n + 1, tempBlock);
			tempBlock.beTag = true;
			v.push(tempBlock);
			if(v.top().indexOf(v.top(), paragraph) >= 0)
			{
				read_context = true;
				
			}
			if(n + 2 < l)
			result.substring(n + 2, l, tempCharString);
			else
				break;
			n++;
			i = n;
			
			
		}
		else if(tempCharString.indexOf(tempCharString, start_tag) > 0)
		{
	    	while(tempCharString.indexOf(tempCharString, start_tag) != n - i)
			{
				n++;

			}
			CharString tempBlockContext;
			result.substring(i + 1, n, tempBlockContext);
			tempBlockContext.beTag = false;
			
			if(v.top().indexOf(v.top(), Pcontext) >= 0 && read_context == true && tempBlockContext.indexOf(tempBlockContext, noUse) == -1)
			{
			
			
				if(context_CharString.size() == 0)
				{
					context_CharString = tempBlockContext;
					//ff<<context_CharString.data;
				}
				else
				{
					context_CharString.concat(tempBlockContext);
				   // ff<<tempBlockContext.data;
				}

			}
			else if(v.top().indexOf(v.top(), Lcontext) >= 0  || v.top().indexOf(v.top(), Strong) >= 0&&tempBlockContext.indexOf(tempBlockContext, noUse) == -1)
			{
				
			   if(context_CharString.size() == 0)
			   {
					   context_CharString = tempBlockContext;
					 //  ff<<tempBlockContext.data;
				}
				else
				{
					  context_CharString.concat(tempBlockContext);
					 // ff<<tempBlockContext.data;
				}
					  

			}
			else if(v.top().indexOf(v.top(), Title) >= 0)
		    {
			
			   title_CharString = v.top();

		    }
		    else if(v.top().indexOf(v.top(), question) >= 0 )
		    {
			
			   problem.push(v.top());
			   question_CharString = v.top();
		   

		    }
	        else if(v.top().indexOf(v.top(), author) >= 0)
		    {
			
		       author_CharString = v.top();

		    }
			if(n+1 < l)
			result.substring(n + 1, l, tempCharString);
			else
				break;
			
			i = n;
		}
		else
			break;

		



	}
	while(v.size() > 0)
	{

		v.pop();

	}
	
	


}



