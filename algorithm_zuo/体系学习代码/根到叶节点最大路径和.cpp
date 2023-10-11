#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node(int v = 0)
		:val(v)
	{}
};
//1. 套路:以x节点为头的整棵树上,最大路径max(left,right)向左子树要累加和,向右子树要累加和
//2. 到叶子结点开始更新
class maxPath
{
public:
	//套路
	int process1(Node* x)
	{
		if (x->left == nullptr && x->right == nullptr)
			return x->val;
		int lNext=0,rNext=0;
		if(x->left)
			lNext = process1(x->left);
		if (x->right)
			rNext = process1(x->right);
		return max(lNext, rNext)+x->val;
	}

	int MaxPath(Node* x)
	{
		return process2(x,x->val);
	}
	int process2(Node* x,int prev)
	{
		if (x->right == nullptr && x->left == nullptr)
		{
			maxNum = max(maxNum, prev + x->val);
			return;
		}
		if (x->left)
			process2(x->left,x->val+prev);
		if (x->right)
			process2(x->right,x->val+prev);
	}
private:
	int maxNum = INT_MIN;
};