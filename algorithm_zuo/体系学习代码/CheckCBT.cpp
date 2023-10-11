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
//层序遍历,
//1. 如果其中一个节点有右孩子但是没有左孩子, 那么就不是
//2. 如果其中一个节点有右孩子但是没有左孩子, 那么就不是&& 遇到第一个左右孩子不全(01状态使用一个变量bool, 只要发生一次就一直管用), 那么之后的所有节点必须都没孩子都是叶子结点.

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