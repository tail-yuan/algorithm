#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};

//֮ǰ�������ǽ��ݹ������������ŵ������бȽ��Ƿ�����O(N)�ռ临�Ӷ�
//ʹ��Morris�������,ֻ��Ҫ����ӡ��Ϊֵ�ıȽϼ���
bool isBST_plus(Node* head)
{
	if (head == nullptr)
		return true;
	Node* cur = head;
	Node* mostRight = nullptr;
	int preVal = INT_MIN;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight)
		{
			//1
			mostRight = cur->left;
			if (mostRight)
			{
				while (mostRight->right && mostRight->right != cur)
					mostRight = mostRight->right;
				if (mostRight->right == nullptr)
				{
					mostRight->right = cur;
					cur = cur->left;
					continue;//->1
				}
				else
					mostRight->right = nullptr;//�ڶ��ε���cur�� ->2
			}
		}
		//2
		if (preVal >= cur->data)
			return false;
		preVal = cur->data;
		cur = cur->right;
	}
	return true;
}