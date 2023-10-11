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
			if (mostRight->right == nullptr)//��һ�ε������ҽڵ�,�ı�ָ���¼��һ������
			{
				mostRight->right = cur;
				cur = cur->left;
				continue; // ->1λ�ü��������������Һ��ӽڵ�,�ı�ָ��ָ��
			}
			else//�ڶ��ε���,�Ļ�ԭ��ָ��
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
				//�����������ܹ��������ε�,��һ�δ�ӡ
				cout << cur->data << " ";
				mostRight->right = cur;
				cur = cur->left;
				continue;//->1
			}
			else
				mostRight->right = nullptr;
		}
		else//���������ļ�ֻ�ܵ���һ�ε�,ֱ�Ӵ�ӡ
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
				mostRight->right = nullptr;//�ڶ��ε���cur�� ->2
		}
		//else û����������->2
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
		from->right = pre;//��ָ����ͷָ
		//�����ƶ�
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