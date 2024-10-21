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
	void Destroy(treeNode<T>*root);//������rootΪ���ڵ�Ķ�����
	void PreOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root));
	void InOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root));
	void PostOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root));
	void Print_Pre(treeNode<T>*root);//ǰ����������rootΪ������
	void Print_In(treeNode<T>* root);//������������rootΪ������
	void Print_Post(treeNode<T>* root);//������������rootΪ������
	bool InsertLeft(const T target, const T val1,treeNode<T>*root);//��ֵΪtarget�Ľڵ�������ڵ㣬��������ڵ������ʧ��
	bool InsertRight(const T target, const T val1,treeNode<T>*root);//��ֵΪtarget�Ľڵ�������ڵ㣬��������ڵ������ʧ��
public:
	BinaryTree():root(NULL){}
	BinaryTree(T val1) {root = new treeNode<T>(val1); }
	~BinaryTree() { Destroy(root); }
	int Height() { return Height(root); }//������rootΪ�������ĸ߶�
	int size() { return size(root); }//������rootΪ�������Ľڵ����
	void Destroy() { Destroy(root); }//���ٶ�����
	void PreOrder(void(*visit)(treeNode<T>* root)) { PreOrder(root, visit); }//ǰ�����
	void InOrder(void(*visit)(treeNode<T>* root)) { InOrder(root, visit); }//�������
	void PostOrder(void(*visit)(treeNode<T>* root)) { PostOrder(root, visit); }//�������
	bool IsEmpty();//�ж����Ƿ�Ϊ��?
	bool InsertLeft(treeNode<T>* root, const T val1);//��root�������ڵ㣬��������ڵ������ʧ��
	bool InsertLeft(const T target, const T val1) { return InsertLeft(target, val1, root); }//��ֵΪtarget�Ľڵ�������ڵ㣬��������ڵ������ʧ��
	bool InsertRight(treeNode<T>* root, const T val1);//��root������ҽڵ㣬�������ҽڵ������ʧ��
	bool InsertRight(const T target, const T val1) { return InsertRight(target, val1, root); }//��ֵΪtarget�Ľڵ�������ڵ㣬��������ڵ������ʧ��
	treeNode<T>* GetRoot();//�������ĸ�
	treeNode<T>* GetLeft(treeNode<T>* root);//��������Ů
	treeNode<T>* GetRight(treeNode<T>* root);//��������Ů
	void Print_Pre() { Print_Pre(root); }//ǰ����������rootΪ������
	void Print_In() { Print_In(root); }//������������rootΪ������
	void Print_Post() { Print_Post(root); }//������������rootΪ������
};
#endif