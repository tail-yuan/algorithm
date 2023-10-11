#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};
class Info
{
public:
	int maxDis;
	int height;
	Info(int md=0, int h=0)
		:maxDis(md)
		, height(h)
	{}
};
class MaxDistanceInTree
{
public:
	Info* process(Node* x)
	{
		if (x == nullptr)return nullptr;
		Info* leftInfo = process(x->left);
		Info* rightInfo = process(x->right);
		int p1 = leftInfo->maxDis;
		int p2 = rightInfo->maxDis;
		int p3 = leftInfo->height + 1 + rightInfo->height;
		int maxDistance = max(p1, max(p2, p3));
		int height = max(leftInfo->height,rightInfo->height);
		return new Info(maxDistance,height);
	}
	int maxDistance(Node* head)
	{
		Info *ret=process(head);
		return ret->maxDis;
	}
};