
//问题:从一个二叉树中,找出最大二叉搜索子树,返回最大二叉搜索子树头结点maxBSTHead
//任意一个节点x,
//1. 这个结果与x无关
//	1.1. maxBSTHead在x的左子树当中,
//  1.2. maxBSTHead在x的右子树当中,
//2. 这个结果与x有关,那么以x为头的树就是搜索二叉树,
// 条件:左子树是 && 右子树是 &&lmax<x<rmin  (左子树lmax,右子树rmin,) 左右子树为空也是SB树

//所以需要信息:左子树, maxBSTHead ,IsBST,leftMaxVal,
//			   右子树,maxBSTHead,IsBSR,rightmin,
//并集: maxVal,minVal,IsBST,maxBSTHead.
//还需要子树的maxBSTSize才能对1情况进行更新.

// 注意:如果与x有关,maxBSTHead就是x,
// 如果无关,才是1,将左右子树返回的信息进行整合,构建以x自身的信息向上返回
// 怎么整合? maxVal=max(leftMaxVal,rightMaxVal) ,minVal...,maxSize=max(leftMaxSize,rightMaxSize)
//           maxBSTHead= leftMaxSize>rightMaxSize? leftMaxBSTHead:rightMaxBSTHead;
//			 既然与x无关,说明x子树不是BS树,isBST=false
// 
#include<iostream>
using namespace std;

class BiggestSubBSTInTree
{
private:
	class Node
	{
	public:
		int data;
		Node* left;
		Node* right;
	public:
		Node(int x = 0)
			:data(x)
		{
			left = nullptr;
			right = nullptr;
		}
	};
	struct Info
	{
		bool isBST;
		int maxVal;
		int minVal;
		int maxSize;
		Node* maxBSTHead;
		Info(bool ib, int ma, int mn, int ms,Node* x=nullptr)
			:isBST(ib)
			, maxVal(ma)
			, minVal(mn)
			, maxSize(ms)
			, maxBSTHead(x)
		{}
	};
public:
	//相当于把所有节点遍历一遍O(N)
	Info* f(Node* x)
	{
		if (x == nullptr)
			return nullptr;
		//用黑盒
		Info* leftInfo = f(x->left);
		Info* rightInfo = f(x->right);
		//将黑盒细节拆开,构建x节点
		//后面操作都是O(1)
		int maxVal = x->data;
		int minVal = x->data;
		if (leftInfo)
		{
			maxVal = max(maxVal, leftInfo->maxVal);
			minVal = min(minVal,leftInfo->minVal);
		}
		if (rightInfo)
		{
			maxVal = max(maxVal, rightInfo->maxVal);
			minVal = min(minVal,rightInfo->minVal);
		}
		int maxSize = 0;
		Node* maxBSTHead = nullptr;
		bool isBST = false;
		if (leftInfo)
		{
			maxSize = leftInfo->maxSize;
			maxBSTHead = leftInfo->maxBSTHead;
		}
		if (rightInfo && rightInfo->maxSize > maxSize)
		{
			maxSize = rightInfo->maxSize;
			maxBSTHead = rightInfo->maxBSTHead;
		}
		if ((leftInfo || leftInfo->isBST) && (rightInfo || rightInfo->isBST))
		{
			if ((leftInfo || leftInfo->maxVal < x->data) && (rightInfo || rightInfo->minVal > x->data))
			{
				isBST = true;
				int leftMaxSize = leftInfo == nullptr ? 0 : leftInfo->maxSize;
				int rightMaxSize = rightInfo == nullptr ? 0 : rightInfo->maxSize;
				maxSize = leftMaxSize + rightMaxSize + 1;
				maxBSTHead = x;
			}
		}
		return new Info(isBST,maxVal,minVal,maxSize,maxBSTHead);
	}
	Node* getMaxHead(Node* head)
	{
		return f(head)->maxBSTHead;
	}
};