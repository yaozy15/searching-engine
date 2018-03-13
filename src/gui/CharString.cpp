#include"CharString.h"
#include<iostream>
#include"Windows.h"
using namespace std;
#define MAX 10000
//#include"CharString.h"
#include<iostream>
#include"Windows.h"
using namespace std;
#define MAX 10000
bool CharString::reset()//重置CharString
{
	if(data)
	{
		delete[] data;
	}
	length = 0;
	data = NULL;
	maxlength = 300 - 40;
	data = new wchar_t[300 - 40];
	if(!data)
	{
		return false;
	}


	return true;
}
CharString::CharString()
{
	length = 0;
	data = NULL;
	beTag = false;
	maxlength = 0;
}
CharString::CharString(const CharString &s)
{

	beTag = s.beTag;
	maxlength = 300 - 40;
	
	
	data = new wchar_t[maxlength];
	length = 0;
    for(int i = 0; i < s.length; i++)
    {
        if(length >= maxlength)
        {
            maxlength *= 2;
            wchar_t* block = new wchar_t[maxlength];
            for(int j = 0; j < length; j++)
            {
               block[j] = data[j];
            }
            delete[] data;
			data = NULL;
            data = block;
        }
        data[length] = s.data[i];
        length++;
     }
     data[length] = '\0';
	  

	

}
CharString::~CharString()
{
	if(data)
	{
		delete[]data;
		data = NULL;

	}
}
CharString::CharString(const wchar_t *st)
{
	length = 0;
	maxlength = 300 - 40;
	data = new wchar_t[wcslen(st) + 1];
    for(int i = 0; st[i] != '\0'; i++)
    {
            data[length] = st[i];
            length++;
      }
      data[length] = '\0';
}

/*
以下函数
实现KMP算法，即找到字符串s中子串st的第一个出现的位置

*/
int CharString::indexOf(CharString &s, CharString &st)
{
	st.next = new int[st.length + 2];
	int n = st.length;
	int i = 1;
	st.next[1] = 0;
	int j = 0;
	
	while(i < n)
	{
		if(j == 0 || st.data[i - 1] == st.data[j - 1])
		{
			++i;
			++j;
			st.next[i] = j;
		}
		
		else
			j = st.next[j];

	}
	i = 1;
	j = 1;
	while(i <= s.length && j <= n)
	{
		if(j == 0 || s.data[i - 1] == st.data[j - 1])
		{
			++i;
			++j;
		}
		else
			j = st.next[j];
		
	}
	delete []st.next;
	if(j > n)
		return i - st.length - 1;
	else
		return -1;

}
/*
以下函数是让字符串本身再加上字符串st

*/
CharString CharString::addCharString(const CharString& st)
{
	CharString newStr;
	wchar_t *temp = new wchar_t[length + st.length + 2];
	memset(temp, L'\0', sizeof(wchar_t) * (length + st.length + 5));
	int i, j;
	for(j = 0; j < length; j++)
	{
		temp[j] = data[j];
	}
	for(i = length; i < st.length + length; i++)
	{
		temp[i] = st.data[i - length];
	}
	data = temp;
	length = length + st.length;
	return *this;




}
/*
以下函数是将字符串进行连接

*/
void CharString::concat(const CharString& st)
{
	

	int l = st.length;
	for(int i = 0; i < l; i++)
	{
		push_back(st.data[i]);
	}

}


int CharString::substring(int start, int end, CharString& target)
{
	target.reset();
	int n;
	if(end > length)
		n = length;
	else
		n = end;
	for(int i = start - 1; i <= n - 1; i++)
	{
		target.push_back(data[i]);
	}
	return 0;
}
int CharString::getsubCharString(int i, CharString& target)
{
	target.reset();
	
	target.push_back(data[i - 1]);
	
	return 0;
}

bool CharString::operator==(const CharString &compare) const
{
	if(wcscmp(this->data, compare.data) == 0)
		return true;
	else
		return false;


}
bool CharString::operator>(const CharString &compare) const
{
	if(wcscmp(this->data, compare.data) > 0)
		return true;
	else
		return false;


}
bool CharString::operator<(const CharString &compare) const
{
	
	if(wcscmp(this->data, compare.data) < 0)
		return true;
	else
		return false;

}


bool CharString::strcmp_CharString(CharString *p, CharString *q)
{

	if(wcscmp(p->data, q->data) == 0)
		return true;
	else
		return false;


}



/*

将常字符串赋值给自定义字符串

*/
CharString& CharString::operator=(const char *sourceCharString)
{
	
	int nLen = MultiByteToWideChar(CP_UTF8, 0, sourceCharString, -1, NULL, 0);
	wchar_t* pResult = new wchar_t[nLen + 1];
	MultiByteToWideChar(CP_UTF8, 0, sourceCharString, -1, pResult, nLen);


//	reset();
	if(data)
	{
		delete[] data;
		data = NULL;
	}
	length = 0;
	data = NULL;
	data = new wchar_t[wcslen(pResult) + 1];
	maxlength = 300 - 40;
	for(int i = 0; pResult[i] != '\0'; i++)
	{
		data[length] = pResult[i];
		length++;
	}
	data[length] = '\0';
	delete[]pResult;
	return *this;
}
CharString& CharString::operator=(wchar_t* aim)
{
	beTag = false;
	if(data)
	{
		delete[] data;
		data = NULL;
	}
	length = 0;
	data = NULL;
	data = new wchar_t[wcslen(aim) + 1];
	maxlength = 300 - 40;
	length = 0;
    for(int i = 0; aim[i] != '\0'; i++)
	{
		data[length] = aim[i];
		length++;
	}
	data[length] = '\0';
	return *this;



}
CharString& CharString::operator=(CharString &aim)
{

	beTag = aim.beTag;
	reset();
	int l = aim.length;
    for(int i = 0; i < l; i++)
	{
          push_back(aim.data[i]);
    }
    return *this;
}

int CharString::concat(const CharString& source, CharString& target)
  {
	target = *this;
	int l1 = source.length;
	for(int i = 0; i < l1; i++)
	{
		target.push_back(source.data[i]);
	}
	return 0;
}

int CharString::push_back(const wchar_t c)
{
	if(!maxlength)
	{
		reset();

	}
	if(length >= maxlength - 1)
	{
		maxlength *= 2;
		wchar_t* temp = new wchar_t[maxlength];
		for(int j = 0; j < length; j++)
		{
			temp[j] = data[j];
		}
		delete[] data;
		data = NULL;
		data = temp;
		
	}
	data[length] = c;
	length++;
	data[length] = '\0';
	return length;
}