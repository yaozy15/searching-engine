#include"AVL.h"
AVLTree::AVLTree()
{
		root = NULL;
		num = 0;
}
int AVLTree::height(TreeNode*& node)
{

	if(node)
	{
		return node->height;


	}
	else
		return -1;


}
int AVLTree::Max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;


}

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

TreeNode* AVLTree::DoubleRotateLR(TreeNode *&node)
{
	node->left = (node->left);
	return SingleRotateLeft(node);



}

TreeNode* AVLTree::DoubleRotateRL(TreeNode *&node)
{
	node->right = (node->right);
	return SingleRotateRight(node);



}
TreeNode* AVLTree::Insert_ptr(TreeNode*&node, CharString& x, CharString &filename, int rank, string &name)
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
		node->fileSet.Add(filename, rank, name);
		num++;



	}
	else
	{
		if(wcscmp(node->data.data , x.data) > 0)
		{
			node->left = Insert_ptr(node->left, x, filename, rank, name);
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
			Insert_ptr(node->right, x, filename, rank, name);
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
		   node->fileSet.Add(filename, rank, name);

	   }
	   node->height = Max(height(node->left), height(node->right));

	}
	node->height = Max(height(node->left), height(node->right)) + 1;
	return node;
}

TreeNode* AVLTree::Insert(CharString& x, CharString&filename, int rank, string& name)
{
	return Insert_ptr(root, x, filename, rank, name);
}

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

TreeNode *AVLTree::Search(CharString& x)
{
	return Search_ptr(root, x);
}
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
void AVLTree::Remove(CharString& x)
{

	Remove_ptr(root, x);

}

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
		delete root;
		root = NULL;
		}
	}


}