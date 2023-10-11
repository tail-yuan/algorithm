#include<iostream>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};

void f(Node* head)
{
	//1th reach the node
	if (head == nullptr)
		return;
	// ...can do other thing !
	//1th return the node

	f(head->left);
	//2th 
	// ...can do other thing !
	//2th return the node

	f(head->right);
	//3th 
	// ...can do other thing !
	//3th return the node
}
//��һ�ε�������ڵ�do��ӡ
void preOrder(Node* head)
{
	if (head == nullptr)
		return;
	cout << head->val << " ";
	preOrder(head->left);
	preOrder(head->right);
}
//�ڶ��ε�������ڵ�do��ӡ
void inOrder(Node* head)
{
	if (head == nullptr)
		return;
	preOrder(head->left);
	//2
	cout << head->val << " ";
	//2
	preOrder(head->right);
}
//�����ε�������ڵ�do��ӡ
void postOrder(Node* head)
{
	if (head == nullptr)
		return;
	preOrder(head->left);
	preOrder(head->right);
	//3
	cout << head->val << " ";
	//3
}
