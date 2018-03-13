#ifndef AVL_H
#define AVL_H
#include"fileLink.h"
#include"CharString.h"
class TreeNode
{
public:
	CharString data;  //节点存储的字符串
	int height;      //节点的高度
	unsigned int frequent; //词的频率
	TreeNode *left; //左孩子
	TreeNode *right; //右孩子
	fileLink fileSet; //节点的倒排文档

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
	TreeNode *root;  //根节点
	int num;
public:
	TreeNode* Insert_ptr(TreeNode*&node, CharString& x, CharString &filename, int rank); //插入节点
	TreeNode* Search_ptr(TreeNode*&node, CharString& x); //查找节点
	void Remove_ptr(TreeNode *node, CharString& x); //删除节点
	int height(TreeNode*&node); //求节点高度
	TreeNode* SingleRotateLeft(TreeNode* &node); //单左旋
	TreeNode* SingleRotateRight(TreeNode* &node); //单右旋
	TreeNode* DoubleRotateLR(TreeNode* &node); //双旋转从左到右
	TreeNode* DoubleRotateRL(TreeNode* &node);//双旋转从右到左
	int Max(int a, int b); //求最大值
	TreeNode* Insert(CharString& x, CharString &filename, int rank); //总体的插入节点
	TreeNode* Search(CharString& x); //总体的搜索节点
	void Remove(CharString& x); //总体的删除节点
	void destroy(TreeNode* &root); //析构整个平衡树
	




};
































#endif