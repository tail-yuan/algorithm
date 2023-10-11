#include<unordered_map>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
//<height,bool>需要的信息
pair<int, bool>process(Node* head)
{
	if (head == nullptr) return make_pair(0, true);
	pair<int, bool> leftData= process(head->left);
	pair<int, bool> rightData = process(head->right);
	int height = max(leftData.first, rightData.first) + 1;
	bool isBalanced = leftData.second && rightData.second && (abs(leftData.first - rightData.first) <= 1);
	return make_pair(height,isBalanced);
}
bool isBalancedTree(Node* head)
{
	return process(head).second;
}
