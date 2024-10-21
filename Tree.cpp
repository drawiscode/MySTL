#include "Tree.h"
template<class T>
int BinaryTree<T>::Height(treeNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return max(Height(root->left), Height(root->right)) + 1;
}
template<class T>
int BinaryTree<T>::size(treeNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + size(root->left) + size(root->right);
}
template<class T>
void BinaryTree<T>::Destroy(treeNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	Destroy(root->left);
	Destroy(root->right);
	delete root;
}
template<class T>
void BinaryTree<T>::PreOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root))
{
	if (root == NULL)
	{
		return;
	}
	visit(root);
	PreOrder(root->left,visit);
	PreOrder(root->right,visit);
}
template<class T>
void BinaryTree<T>::InOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root))
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left,visit);
	visit(root);
	InOrder(root->right,visit);
}
template<class T>
void BinaryTree<T>::PostOrder(treeNode<T>* root, void(*visit)(treeNode<T>* root))
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->left, visit);
	PostOrder(root->right, visit);
	visit(root);
}
template<class T>
bool BinaryTree<T>::IsEmpty()
{
	return (root == NULL)?true:false;
}
template<class T>
treeNode<T>* BinaryTree<T>::GetRoot()
{
	return root;
}
template<class T>
treeNode<T>* BinaryTree<T>::GetLeft(treeNode<T>* root)
{
	return (root == NULL) ? NULL : root->left;
}
template<class T>
treeNode<T>* BinaryTree<T>::GetRight(treeNode<T>* root)
{
	return (root == NULL) ? NULL : root->right;
}
template<class T>
bool BinaryTree<T>::InsertLeft(treeNode<T>* root, const T val1)
{
	if (root != NULL&&root->left==NULL)
	{
		treeNode<T>* newnode = new treeNode<T>(val1);
		root->left = newnode;
		return true;
	}
	return false;
}
template<class T>
bool BinaryTree<T>::InsertLeft(const T target, const T val1,treeNode<T>*root)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->val == target && root->left == NULL)//插入成功
	{
		treeNode<T>* newnode = new treeNode<T>(val1);
		root->left = newnode;
		return true;
	}
	else
	{
		return InsertLeft(target, val1, root->left) || InsertLeft(target, val1, root->right);
	}
}
template<class T>
bool BinaryTree<T>::InsertRight(treeNode<T>* root, const T val1)
{
	if (root != NULL && root->right == NULL)
	{
		treeNode<T>* newnode = new treeNode<T>(val1);
		root->right = newnode;
		return true;
	}
	return false;
}
template<class T>
bool BinaryTree<T>::InsertRight(const T target, const T val1, treeNode<T>* root)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->val == target && root->right == NULL)//插入成功
	{
		treeNode<T>* newnode = new treeNode<T>(val1);
		root->right = newnode;
		return true;
	}
	else
	{
		return InsertRight(target, val1, root->left) || InsertRight(target, val1, root->right);
	}
}
template<class T>
void BinaryTree<T>::Print_Pre(treeNode<T>*root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->val << '\t';
	Print_Pre(root->left);
	Print_Pre(root->right);
}
template<class T>
void BinaryTree<T>::Print_In(treeNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	Print_In(root->left);
	cout << root->val << '\t';
	Print_In(root->right);
}
template<class T>
void BinaryTree<T>::Print_Post(treeNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	Print_Post(root->left);
	Print_Post(root->right);
	cout << root->val << '\t';
}