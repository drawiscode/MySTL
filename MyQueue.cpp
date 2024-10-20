#include "MyQueue.h"
template<class T>
void MyQueue<T>::MakeEmpty()
{
	Node<T>*del = head;
	while (del!=NULL)
	{
		Node<T>* temp = del;
		del = del->next;
		delete temp;
	}
	head = NULL;
	tail = NULL;
	return;
}
template<class T>
void MyQueue<T>::Pop()
{
	if (head == NULL)
	{
		cout << "����Ϊ�գ��޷��˳�Ԫ�أ�" << endl;
		return;
	}
	Node<T>* del = head;
	head = head->next;
	delete del;
	return;
}
template<class T>
void MyQueue<T>::Push(T val)
{
	Node<T>* newnode = new Node<T>;
	if (newnode == NULL)
	{
		cout << "�ڴ����ʧ�ܣ�" << endl;
		exit(-1);
	}
	newnode->next = NULL;
	newnode->val = val;
	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
	return;
}
template<class T>
int MyQueue<T>::size()
{
	Node<T>* temp = head;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}
template<class T>
void MyQueue<T>::Print()
{
	Node<T>* cur = head;
	int cnt = 0;
	while (cur != NULL)
	{
		cout << cur->val << '\t';
		cur = cur->next;
		cnt++;
		if (cnt % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	return;
}
template<class T>
T MyQueue<T>::GetHead()
{
	if (head == NULL)
	{
		cout << "����Ϊ�գ�" << endl;
		exit(-1);
	}
	return head->val;
}
template<class T>
T MyQueue<T>::GetTail()
{
	if (tail == NULL)
	{
		cout << "����Ϊ�գ�" << endl;
		exit(-1);
	}
	return tail->val;
}
template<class T>
bool MyQueue<T>::IsEmpty()
{
	return head == NULL;
}