#ifndef AVL_H
#define AVL_H
#include"fileLink.h"
#include"CharString.h"
class TreeNode
{
public:
	CharString data;  //�ڵ�洢���ַ���
	int height;      //�ڵ�ĸ߶�
	unsigned int frequent; //�ʵ�Ƶ��
	TreeNode *left; //����
	TreeNode *right; //�Һ���
	fileLink fileSet; //�ڵ�ĵ����ĵ�

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
	TreeNode *root;  //���ڵ�
	int num;
public:
	TreeNode* Insert_ptr(TreeNode*&node, CharString& x, CharString &filename, int rank); //����ڵ�
	TreeNode* Search_ptr(TreeNode*&node, CharString& x); //���ҽڵ�
	void Remove_ptr(TreeNode *node, CharString& x); //ɾ���ڵ�
	int height(TreeNode*&node); //��ڵ�߶�
	TreeNode* SingleRotateLeft(TreeNode* &node); //������
	TreeNode* SingleRotateRight(TreeNode* &node); //������
	TreeNode* DoubleRotateLR(TreeNode* &node); //˫��ת������
	TreeNode* DoubleRotateRL(TreeNode* &node);//˫��ת���ҵ���
	int Max(int a, int b); //�����ֵ
	TreeNode* Insert(CharString& x, CharString &filename, int rank); //����Ĳ���ڵ�
	TreeNode* Search(CharString& x); //����������ڵ�
	void Remove(CharString& x); //�����ɾ���ڵ�
	void destroy(TreeNode* &root); //��������ƽ����
	




};
































#endif