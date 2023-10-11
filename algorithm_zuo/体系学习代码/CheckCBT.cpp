#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
//completed binary tree
//�������,
//1. �������һ���ڵ����Һ��ӵ���û������, ��ô�Ͳ���
//2. �������һ���ڵ����Һ��ӵ���û������, ��ô�Ͳ���&& ������һ�����Һ��Ӳ�ȫ(01״̬ʹ��һ������bool, ֻҪ����һ�ξ�һֱ����), ��ô֮������нڵ���붼û���Ӷ���Ҷ�ӽ��.

bool CheckCBT(Node* head)
{
	if (head == nullptr) return true;
	queue<Node*>q;
	bool leaf = false;
	q.push(head);
	Node* l = nullptr;
	Node* r = nullptr;
	while (!q.empty())
	{
		head = q.front(); q.pop();
		l = head->left;
		r = head->right;
		if (leaf && (l != nullptr || r != nullptr)
			|| (l == nullptr && r != nullptr))
		{
			return false;
		}
		if (l)
			q.push(l);
		if (r)
			q.push(r);
		if (l == nullptr || r == nullptr)
			leaf = true;
	}
	return true;
}