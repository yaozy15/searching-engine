#include"Tries.h"
#include"CharString.h"


Trie::Trie()
{
	root = new Node;
	root->son = NULL;
	root->brother = NULL;
	root->beRoot = true;
	
}

bool Trie::searchWord(CharString s)
{
	int n = 0;
	Node *p;
	Node *temp;
	temp = NULL;
	p = root->son;
	temp = root->son;
	if(p == NULL)
		return false;
	else
	{
		while(temp != NULL)
		{
			if(temp->data_word == s.data[n])
			{
				temp = temp->son;
				n++;

			}
			else
			{
				//stock = temp;
				temp = temp->brother;
				//if(temp == NULL)

			}


		}
		int a = n;
		if(n == s.size())
			return true;
		else
			return false;


	}


}

/*void Trie::addNode(CharString s)
{
	Node *p;
	p = NULL;
	Node *q;
	q = NULL;
	int t = 0;
	if(root->son == NULL)
	{

		for(int i = 0; i < s.size(); i++)
		{
			p = new Node;
			CharString sub_str = s.getsubCharString(i + 1);
			p->word = sub_str;
			p->son = NULL;
			p->brother = NULL;
			p->beRoot = false;
			if(i == s.size() - 1)
			p->beWord = true;
			else
				p->beWord = false;
			if(root->son == NULL)
			{
				root->son = p;
				q = p;
				t++;

			}
			else
			{
				t++;
				q->son = p;
				q->brother = NULL;
				
			}


		}


	}
	else
	{
		Node *r, *m;
		r = NULL;
		m = NULL;
		Node *newNode;
		newNode = NULL;
		Node *temp;
		temp = NULL;
		temp = root->son;
		Node *stock;
		stock = root;
		Node *tempNode;
		tempNode = NULL;
		int n = 0;
	    
		while(temp != NULL)
		{
		  
			if(wcscmp(temp->word.data, s.getsubCharString(n + 1).data) == 0)
			{
				stock = temp;
				temp = temp->son;
				n++;

			}
			else
			{
				temp = temp->brother;
	
			}


		}

	if(n < s.size())
	{
		newNode = new Node;
		newNode->son = NULL;
		newNode->brother = NULL;
		newNode->word = s.getsubCharString(n + 1);
		n++;
		newNode->brother = stock->son;
		stock->son = newNode;
		m = newNode;
		while(n < s.size())
		{
			r = new Node;
			r->word = s.getsubCharString(n + 1);
			r->son = NULL;
			r->brother = NULL;
			if(n == s.size() - 1)
				r->beWord = true;
			else
			r->beWord = false;

			m->son = r;
			m = r;
			n++;


		}
		
			



		


	}
	}

	




}*/

/*

添加字典节点

*/
void Trie::insert_word(CharString &s)
{
	int l = s.length;
	Node *p;
	p = root->son;
	Node *q = root;
	for(int i = 0; i < l; i++)
	{
	  wchar_t c = s.data[i];
	  while(1)
	  {
		if(!p)
		{
			Node *temp = new Node;
			temp->son = NULL;
			temp->brother = q->son;
			temp->data_word = c;
			temp->beWord = false;
			q->son = temp;
			q = temp;
			p = temp->son;
			break;




		}
		if(p->data_word == c)
		{
			q = p;
			p = p->son;
			break;

		}
		p = p->brother;

	  }
	  //q->beWord = true;




	}
	q->beWord = true;

}

/*

查询字典
*/
bool Trie::check_word(CharString s)
{
	Node *p = root->son;
	Node *q = root;
	int l = s.length;
	int i = 0;
	for(; i < l; i++)
	{
		wchar_t c = s.data[i];
		while(p)
		{
			if(p->data_word == c)
			{

				break;

			}
			else
				p = p->brother;

		}
		if(!p)
			break;
		q = p;
		p = p->son;


	}
	if(i >= l && q->beWord == true)
		return true;
	else
		return false;





}