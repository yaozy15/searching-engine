#include"AVL.h"
AVLTree::AVLTree()
{
		root = NULL;
		num = 0;
}
/*
以下函数使用来求节点的高度，空节点的高度定义为-1


*/
int AVLTree::height(TreeNode*& node)
{

	if(node)
	{
		return node->height;


	}
	else
		return -1;


}
/*
以下函数使用来求两个数的最大值

*/
int AVLTree::Max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;


}
/*

以下函数是平衡树的单左旋操作

*/
TreeNode* AVLTree::SingleRotateLeft(TreeNode *&node)
{
	if(node)
	{
	TreeNode* temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	node->height = Max(height(node->left), height(node->right)) + 1;
	temp->height = Max(height(temp->left), node->height) + 1;
	return temp;
	}

}
/*
以下函数是平衡树的单右旋操作

*/
TreeNode* AVLTree::SingleRotateRight(TreeNode *&node)
{
	if(node)
	{
	TreeNode* temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node->height = Max(height(node->left), height(node->right)) + 1;
	temp->height = Max(height(temp->left), node->height) + 1;
	return temp;
	}

}
/*
以下函数是平衡树操作的双旋转从左到右

*/
TreeNode* AVLTree::DoubleRotateLR(TreeNode *&node)
{
	node->left = (node->left);
	return SingleRotateLeft(node);



}
/*
以下函数是平衡树的双旋转从右到左

*/
TreeNode* AVLTree::DoubleRotateRL(TreeNode *&node)
{
	node->right = (node->right);
	return SingleRotateRight(node);



}
/*
以下函数是平衡树的插入操作，在插入节点的同时，也给节点建了倒排文档

*/
TreeNode* AVLTree::Insert_ptr(TreeNode*&node, CharString& x, CharString &filename, int rank)
{
	if(!node)
	{
		node = new TreeNode();
		node->data.data = new wchar_t[x.length + 1];
		node->data.length = x.length;
		node->data.beTag = x.beTag;
		for(int i = 0; i < x.length; i++)
		{
			node->data.data[i] = x.data[i];

		}
		node->data.data[x.length] = '\0';
		node->fileSet.Add(filename, rank);
		node->fileSet.stockWord = x;
		num++;



	}
	else
	{
		if(wcscmp(node->data.data , x.data) > 0)
		{
			node->left = Insert_ptr(node->left, x, filename, rank);
			if(height(node->left) - height(node->right) == 2)
			{
				//if(x < node->left->data)
				if(wcscmp(node->data.data , x.data) > 0)
				{
					node = SingleRotateLeft(node);

				}
				else
					node = DoubleRotateLR(node);

			}
			


			
	   } 
	   else if(wcscmp(node->data.data , x.data) < 0)
	   {
			Insert_ptr(node->right, x, filename, rank);
			if(height(node->right) - height(node->left) == 2)
			{
				//if(x > node->right->data)
				if(wcscmp(node->data.data , x.data) < 0)
				{
					node = SingleRotateRight(node);

				}
				else
			     node = DoubleRotateRL(node);


			 }

		
		}
	   else
	   {

		   ++(node->frequent);
		   node->fileSet.Add(filename, rank);

	   }
	   node->height = Max(height(node->left), height(node->right));

	}
	//node->fileSet.Add(filename, rank);
	 node->height = Max(height(node->left), height(node->right)) + 1;
	 return node;
}
/*
总体插入节点
*/
TreeNode* AVLTree::Insert(CharString& x, CharString&filename, int rank)
{
		return Insert_ptr(root, x, filename, rank);

}
/*
平衡树搜索节点

*/
TreeNode* AVLTree::Search_ptr(TreeNode*&node, CharString& x)
{

	if(node == NULL)
	{

		return NULL;

	}
	else
	{
		if(wcscmp(node->data.data , x.data) > 0)
		{

			return Search_ptr(node->left, x);
		}
		else if(wcscmp(node->data.data , x.data) < 0)
		{
			return Search_ptr(node->right, x);

		}
		else
			return node;


	}


}
 /*
 总体搜索节点

 */
TreeNode *AVLTree::Search(CharString& x)
{
	return Search_ptr(root, x);


}
/*

删除节点
*/
void AVLTree::Remove_ptr(TreeNode *node, CharString& x)
{
	if(!node)
	{

		return;

	}
	if(x < node->data)
	{
		Remove_ptr(node->left, x);
		if(height(node->right) - height(node->left) == 2)
		{
			if(node->right->left != NULL &&(height(node->right->left) > height(node->right->right)))
			{
				DoubleRotateRL(node);

			}
			else
				SingleRotateRight(node);

		}


	}
	else if(x > node->data)
	{
		Remove_ptr(node->right, x);
		if(height(node->left) - height(node->right) == 2)
		{
			if(node->left->right != NULL &&(height(node->left->right) > height(node->left->left)))
			{
				DoubleRotateLR(node);

			}
			else
				SingleRotateLeft(node);

		}


	}
	else
	{
		if(node->left && node->right)
		{
			TreeNode *temp = node->right;
			while(temp->left != NULL)
			{
				temp = temp->left;

			}
			node->data = temp->data;
			node->frequent = temp->frequent;
			Remove_ptr(node->right, temp->data);
			if(height(node->left) - height(node->right) == 2)
			{
				if(node->left->right != NULL && (height(node->left->right) > height(node->left->left)))
				{
					DoubleRotateLR(node);

				}
				else
					SingleRotateLeft(node);

			}


		}
		else
		{
			TreeNode *temp = node;
			if(node->left == NULL)
				node = node->right;
			else if(node->right == NULL)
			{
				node = node->left;

			}
			delete temp;
			temp = NULL;

		}


	}
	if(node == NULL)
		return;
	node->height = Max(height(node->left), height(node->right)) + 1;
	return;


}
/*
总体删除节点

*/
void AVLTree::Remove(CharString& x)
{

	Remove_ptr(root, x);

}
/*
析构平衡树

*/
void AVLTree::destroy(TreeNode* &root)
{
	if(root)
	{
		if(root->left)
		{
		destroy(root->left);
		root->left = NULL;
		}
		if(root->right)
		{
		destroy(root->right);
		root->right = NULL;
		}
		if(root)
		{
		root->fileSet.destroy();
		delete root;
		root = NULL;
		}
	}


}