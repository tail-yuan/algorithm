// ����ȫ�������ڵ����
// 1. �ݹ���������,������
// 2. ���x�ڵ�����������ڵ㵽�������һ��,˵��x��������������,2^h-1 +1(x) + x->right�Ľڵ�����
// 3. ���x�ڵ�����������ڵ�û�е��������һ��,˵��x��������������,2^(h-1)-1 +1(x) + x->left�Ľڵ�����
//T(N)����:ѡ����ѡ��,����Ҫ��x����������ڵ�,���Ų����½�������1,�����ǵȲ�����,O(h^2)=O((logN)^2)
//���ֻ�Ǳ�������O(N)
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
	int mostLeftLevel(Node* x,int level)//���ǲ㿪ʼ������ͳ�����
	{
		while (x)
		{
			level++;
			x = x->left;
		}
		return level - 1;
	}
	//curlevel�������node���ڲ���
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