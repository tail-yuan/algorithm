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
//1. ��·:��x�ڵ�Ϊͷ����������,���·��max(left,right)��������Ҫ�ۼӺ�,��������Ҫ�ۼӺ�
//2. ��Ҷ�ӽ�㿪ʼ����
class maxPath
{
public:
	//��·
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