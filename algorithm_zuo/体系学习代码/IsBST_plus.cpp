#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};

//之前的做法是将递归中序遍历结果放到容器中比较是否升序O(N)空间复杂度
//使用Morris中序遍历,只需要将打印改为值的比较即可
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
					mostRight->right = nullptr;//第二次到达cur的 ->2
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