#include<iostream>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
};
Node* getLeftestNode(Node* node)
{
	if (node == nullptr)return nullptr;
	while (node->left)
		node = node->left;
	return node;
}
Node* GetSuccessorNode(Node* node)
{
	if (node == nullptr)
		return nullptr;
	if (node->right)
		return getLeftestNode(node->right);
	else
	{
		Node* parent = node->parent;
		while (parent!=nullptr && parent->left != node)
		{
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}
}