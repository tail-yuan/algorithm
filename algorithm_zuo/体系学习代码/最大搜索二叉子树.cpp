
//����:��һ����������,�ҳ���������������,������������������ͷ���maxBSTHead
//����һ���ڵ�x,
//1. ��������x�޹�
//	1.1. maxBSTHead��x������������,
//  1.2. maxBSTHead��x������������,
//2. ��������x�й�,��ô��xΪͷ������������������,
// ����:�������� && �������� &&lmax<x<rmin  (������lmax,������rmin,) ��������Ϊ��Ҳ��SB��

//������Ҫ��Ϣ:������, maxBSTHead ,IsBST,leftMaxVal,
//			   ������,maxBSTHead,IsBSR,rightmin,
//����: maxVal,minVal,IsBST,maxBSTHead.
//����Ҫ������maxBSTSize���ܶ�1������и���.

// ע��:�����x�й�,maxBSTHead����x,
// ����޹�,����1,�������������ص���Ϣ��������,������x�������Ϣ���Ϸ���
// ��ô����? maxVal=max(leftMaxVal,rightMaxVal) ,minVal...,maxSize=max(leftMaxSize,rightMaxSize)
//           maxBSTHead= leftMaxSize>rightMaxSize? leftMaxBSTHead:rightMaxBSTHead;
//			 ��Ȼ��x�޹�,˵��x��������BS��,isBST=false
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
	//�൱�ڰ����нڵ����һ��O(N)
	Info* f(Node* x)
	{
		if (x == nullptr)
			return nullptr;
		//�úں�
		Info* leftInfo = f(x->left);
		Info* rightInfo = f(x->right);
		//���ں�ϸ�ڲ�,����x�ڵ�
		//�����������O(1)
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