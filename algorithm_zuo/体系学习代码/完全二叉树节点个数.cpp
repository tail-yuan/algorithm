// 求完全二叉树节点个数
// 1. 递归往左子树,求出深度
// 2. 如果x节点右子树最左节点到达了最后一层,说明x左子树都是满的,2^h-1 +1(x) + x->right的节点总数
// 3. 如果x节点右子树最左节点没有到达了最后一层,说明x右子树都是满的,2^(h-1)-1 +1(x) + x->left的节点总数
//T(N)估计:选左还是选右,都需要从x遍历到最左节点,随着层数下降次数减1,所以是等差数列,O(h^2)=O((logN)^2)
//如果只是遍历就是O(N)
#include<iostream>
using namespace std;
class CompleteTreeNodeNumber
{
private:
	class Node
	{
	public:
		Node* left;
		Node* right;
		int data;
		Node(int d)
			:data(d)
			, left(nullptr)
			, right(nullptr)
		{}
	};
private:
	int mostLeftLevel(Node* x,int level)//从那层开始的向下统计深度
	{
		while (x)
		{
			level++;
			x = x->left;
		}
		return level - 1;
	}
	//curlevel代表的是node所在层数
	int bs(Node* node, int curlevel,int h)
	{
		if (curlevel == h)
		{
			return 1;
		}
		if (mostLeftLevel(node->right, curlevel + 1) == h)
			//return pow(2,h-curlevel) -1 + 1 + bs(node->right,curlevel+1,h);
			return (1 << (h - curlevel)) + bs(node->right, curlevel + 1, h);
		else
			//return pow(2, h - curlevel -1 ) - 1 + 1 + bs(node->left, curlevel + 1, h);
			return (1 << (h - curlevel - 1)) + bs(node->left,curlevel+1,h);
	}
public:
	int getNodeNum(Node* head)
	{
		if (head == nullptr)
			return 0;
		return bs(head,1,mostLeftLevel(head,1));
	}
};