#pragma once
#ifndef TREE
#define TREE
#include<iostream>
using namespace std;
template<class T>
struct treeNode
{
	T val;
	treeNode<T>*left;
	treeNode<T>*right;
	treeNode() :left(NULL), right(NULL) {};
	treeNode(T val1, treeNode<T>*l = NULL, treeNode<T>*r = NULL) :val(val1), left(l), right(r){}
};
template<class T>
class BinaryTree
{
private:
	treeNode<T>* root;
	int Height(treeNode<T>* root);
	int size(treeNode<T>* root);
	void Destroy(treeNode<T>*root);//销毁以root为根节点的二叉树
	void PreOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root));
	void InOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root));
	void PostOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root));
	void Print_Pre(treeNode<T>*root);//前序遍历输出以root为根的树
	void Print_In(treeNode<T>* root);//中序遍历输出以root为根的树
	void Print_Post(treeNode<T>* root);//后序遍历输出以root为根的树
	bool InsertLeft(const T target, const T val1,treeNode<T>*root);//在值为target的节点后插入左节点，若已有左节点则插入失败
	bool InsertRight(const T target, const T val1,treeNode<T>*root);//在值为target的节点后插入左节点，若已有左节点则插入失败
public:
	BinaryTree():root(NULL){}
	BinaryTree(T val1) {root = new treeNode<T>(val1); }
	~BinaryTree() { Destroy(root); }
	int Height() { return Height(root); }//返回以root为根的树的高度
	int size() { return size(root); }//返回以root为根的树的节点个数
	void Destroy() { Destroy(root); }//销毁二叉树
	void PreOrder(void(*visit)(treeNode<T>* root)) { PreOrder(root, visit); }//前序遍历
	void InOrder(void(*visit)(treeNode<T>* root)) { InOrder(root, visit); }//中序遍历
	void PostOrder(void(*visit)(treeNode<T>* root)) { PostOrder(root, visit); }//后序遍历
	bool IsEmpty();//判断树是否为空?
	bool InsertLeft(treeNode<T>* root, const T val1);//在root后插入左节点，若已有左节点则插入失败
	bool InsertLeft(const T target, const T val1) { return InsertLeft(target, val1, root); }//在值为target的节点后插入左节点，若已有左节点则插入失败
	bool InsertRight(treeNode<T>* root, const T val1);//在root后插入右节点，若已有右节点则插入失败
	bool InsertRight(const T target, const T val1) { return InsertRight(target, val1, root); }//在值为target的节点后插入左节点，若已有左节点则插入失败
	treeNode<T>* GetRoot();//返回树的根
	treeNode<T>* GetLeft(treeNode<T>* root);//返回左子女
	treeNode<T>* GetRight(treeNode<T>* root);//返回右子女
	void Print_Pre() { Print_Pre(root); }//前序遍历输出以root为根的树
	void Print_In() { Print_In(root); }//中序遍历输出以root为根的树
	void Print_Post() { Print_Post(root); }//后序遍历输出以root为根的树
};
#endif