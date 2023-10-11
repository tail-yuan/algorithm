#include<unordered_map>
#include<iostream>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
//height Nodes
struct info
{
	int height;
	int nodes;
	info(int h, int n)
		:height(h)
		, nodes(n)
	{}
};
info* process(Node* head)
{
	if (head == nullptr)
		return new info(0, 0);
	//需要的两个信息分别向左右子树要
	info* leftData = process(head->left);
	info* rightData = process(head->right);
	int height = max(leftData->height, rightData->height) + 1;
	int nodes = leftData->nodes + rightData->nodes + 1;
	return new info(height, nodes);
}
bool isFullTree(Node* head)
{
	info* info_ = process(head);
	return 1<<(info_->height) -1 == info_->nodes;
}
