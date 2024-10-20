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
	void MakeEmpty();//清空链表内所有内容
	void Pop();//删除队首元素
	void Push(T val);//队列放入值为val的元素
	int size();//返回目前队列中元素个数
	void Print();//从队首开始打印队列中目前所有的元素
	T GetHead();//得到队首元素
	T GetTail();//得到队尾元素
	bool IsEmpty();
};


#endif
