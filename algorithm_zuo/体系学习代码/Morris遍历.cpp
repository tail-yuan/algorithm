#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};
void Morris(Node* head)
{
	if (head == nullptr)
		return;
	Node* cur = head;
	Node* mostRight = nullptr;
	while (cur != nullptr)
	{
		//1
		mostRight = cur->left;
		if (mostRight)
		{
			while (mostRight->right != nullptr && mostRight->right != cur)
				mostRight = mostRight->right;
			if (mostRight->right == nullptr)//第一次到达最右节点,改变指向记录下一个到哪
			{
				mostRight->right = cur;
				cur = cur->left;
				continue; // ->1位置继续找左子树最右孩子节点,改变指针指向
			}
			else//第二次到来,改回原来指向
				mostRight->right = nullptr;
		}
		cur = cur->right;
	}
}

void MorrisPreOrder(Node* head)
{
	if (head == nullptr)
		return;
	Node* cur = head;
	Node* mostRight = nullptr;
	while (cur != nullptr)
	{
		//1
		mostRight = cur->left;
		if (mostRight)
		{
			while (mostRight->right && mostRight->right != cur)
				mostRight = mostRight->right;
			if (mostRight->right == nullptr)
			{
				//有左子树即能够到达两次的,第一次打印
				cout << cur->data << " ";
				mostRight->right = cur;
				cur = cur->left;
				continue;//->1
			}
			else
				mostRight->right = nullptr;
		}
		else//无左子树的即只能到达一次的,直接打印
			cout << cur->data << " ";
		cur = cur->right;
	}
}
void MorrisInOrder(Node* head)
{
	if (head == nullptr)
		return;
	Node* cur = head;
	Node* mostRight = nullptr;
	while (cur)
	{
		//1
		mostRight = cur->left;
		if (mostRight)
		{
			while (mostRight->right && mostRight->right != cur)
				mostRight = mostRight->right;
			if (mostRight->right == nullptr)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;//->1
			}
			else
				mostRight->right = nullptr;//第二次到达cur的 ->2
		}
		//else 没有左子树的->2
		cout << cur->data << " ";//2
		cur = cur ->right;
	}
}
Node* reverseEdge(Node* from)
{
	Node* pre = nullptr;
	Node* next = nullptr;
	while (from)
	{
		next = from->right;
		from->right = pre;//右指针往头指
		//向下移动
		pre = from;
		from = next;
	}
	return pre;
}
void printRightEdge(Node* head) 
{
	Node* tail = reverseEdge(head);
	Node* cur = tail;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->right;
	}
	reverseEdge(tail);
}
void MorriPostOrder(Node* head)
{
	if (head == nullptr)
		return;
	Node* cur = head;
	Node* mostRight = nullptr;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight)
		{
			while (mostRight->right && mostRight->right != cur)
				mostRight = mostRight->right;
			if (mostRight->right == nullptr)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else
			{
				mostRight->right = nullptr;
				printRightEdge(cur->left);
			}
		}
		cur = cur->right;
	}
	printRightEdge(head);
}