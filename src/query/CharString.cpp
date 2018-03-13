#include"CharString.h"
#include<iostream>
#include"Windows.h"
using namespace std;
#define MAX 10000
 /*
 该类的构建属于实验一的范围，之前我写的这个类并没有很好的内存处理，在实验二中我相当于重写了该类。函数功能在实验一中已说明，在这里不再重复叙述。


 */
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
一下函数现将普通字符串转换为宽字符串然后赋值给自定义的字符串


以下函数
实现KMP算法，即找到字符串s中子串st的第一个出现的位置

*/
int CharString::indexOf(CharString &s, CharString &st)
{
	int i, n, j;

	st.next = new int[st.length + 2];
	n = st.length;
	i = 1;
	st.next[1] = 0;
	j = 0;
	
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

/*
获得字符串第l个位置到第r个位置的子串
l与r均在1到该字符串长度之间
特殊说明只能对长度2以上的字符串进行操作

*/

int CharString::substring(int start, int end, CharString& aim)
{
	aim.reset();
	int n;
	if(end > length)
		n = length;
	else
		n = end;
	for(int i = start - 1; i <= n - 1; i++)
	{
		aim.push_back(data[i]);
	}
	aim.length = n - start + 1;
	return 0;
}
int CharString::getsubCharString(int i, CharString& aim)
{
	aim.reset();
	
	aim.push_back(data[i - 1]);
	
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


std::istream& operator>>(std::istream& in, CharString& CharString)
{
	char *temp = new char[MAX];
	in>>temp;
	CharString.length = strlen(temp);
	char *r = new char[CharString.length + 1];
	for(int i = 0; i < CharString.length; ++i)
	{
		r[i] = temp[i];

	}
	r[CharString.length] = '\0';
	CharString.str = new char[MAX];
	memset(CharString.str, '\0', sizeof(CharString.str));
	delete []CharString.str;
	CharString.str = r;
	return in;

}
bool CharString::strcmp_CharString(CharString *p, CharString *q)
{

	if(wcscmp(p->data, q->data) == 0)
		return true;
	else
		return false;


}
std::ostream& operator<<(std::ostream& out, CharString& CharString)
{

	for(int i = 0; i < CharString.length; i++)
	{
		out<<CharString.data[i];
	}
	return out;

}
CharString operator+(const CharString &plus, const CharString &addplus)
{
	
	CharString newStr;

	int l = plus.length + addplus.length;
	wchar_t *temp = new wchar_t[l + 2];
	memset(temp, L'\0', sizeof(wchar_t) * (l + 1));
	swprintf_s(temp, l + 1, L"%s%s", plus.data, addplus.data);

	newStr.length = l;
	newStr.data = temp;
	return newStr;



}


ifstream &operator >> (ifstream &fin, CharString &yc)
{
	CharString temp;
	fin>>yc.str;
	yc.length = strlen(yc.str);
	return fin;
}
/*

将常字符串赋值给自定义字符串

*/
CharString& CharString::operator=(const char *sourceCharString)
{
	
	int nLen = MultiByteToWideChar(CP_UTF8, 0, sourceCharString, -1, NULL, 0);
	wchar_t* pResult = new wchar_t[nLen + 1];
	MultiByteToWideChar(CP_UTF8, 0, sourceCharString, -1, pResult, nLen);
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

int CharString::concat(const CharString& source, CharString& aim)
  {
	aim = *this;
	int l1 = source.length;
	for(int i = 0; i < l1; i++)
	{
		aim.push_back(source.data[i]);
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