#pragma once
#ifndef MYQUEUE
#define MYQUEUE
#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T val;
	Node* next;
};
template<class T>
class MyQueue
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	MyQueue():head(NULL),tail(NULL){}
	~MyQueue() { MakeEmpty(); }
	void MakeEmpty();//�����������������
	void Pop();//ɾ������Ԫ��
	void Push(T val);//���з���ֵΪval��Ԫ��
	int size();//����Ŀǰ������Ԫ�ظ���
	void Print();//�Ӷ��׿�ʼ��ӡ������Ŀǰ���е�Ԫ��
	T GetHead();//�õ�����Ԫ��
	T GetTail();//�õ���βԪ��
	bool IsEmpty();
};


#endif
