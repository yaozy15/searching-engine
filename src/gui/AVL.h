#ifndef AVL_H
#define AVL_H
#include"fileLink.h"
#include"CharString.h"
#include<string>
class TreeNode
{
public:
	CharString data;
	int height;
	unsigned int frequent;
	TreeNode *left;
	TreeNode *right;
	fileLink fileSet;

public:
	TreeNode()
	{
		left = NULL;
	    right = NULL;
		frequent = 1;
		height = 0;

	}
	





};


class AVLTree
{
public:
	AVLTree();
	~AVLTree(){}
public:
	TreeNode *root;
	int num;
public:
	TreeNode* Insert_ptr(TreeNode*&node, CharString& x, CharString &filename, int rank, string& name);
	TreeNode* Search_ptr(TreeNode*&node, CharString& x);
	void Remove_ptr(TreeNode *node, CharString& x);
	int height(TreeNode*&node);
	TreeNode* SingleRotateLeft(TreeNode* &node);
	TreeNode* SingleRotateRight(TreeNode* &node);
	TreeNode* DoubleRotateLR(TreeNode* &node);
	TreeNode* DoubleRotateRL(TreeNode* &node);
	int Max(int a, int b);
	TreeNode* Insert(CharString& x, CharString &filename, int rank, string &name);
	TreeNode* Search(CharString& x);
	void Remove(CharString& x);
	void destroy(TreeNode* &root);
	




};
































#endif