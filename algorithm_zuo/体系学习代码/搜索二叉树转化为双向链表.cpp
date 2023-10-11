#include<iostream>
using namespace std;
class BSTreeToDoubleList
{
public:
	//����һ���ڵ�x����������Ҫ����õ������ͷβ���,Ȼ����֮��,���Ϸ���x�����������β
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
	class Info
	{
	public:
		Node* start;
		Node* end;
		Info(Node* s=nullptr,Node* e=nullptr)
			:start(s)
			, end(e)
		{}
	};
	Node* convert(Node* head)
	{
		if (head == nullptr)
			return nullptr;
		return process(head).start;
	}
	Info process(Node* x)
	{
		if (x == nullptr)
			return Info(nullptr, nullptr);
		Info leftList = process(x->left);
		Info rightList = process(x->right);
		if (leftList.end != nullptr)
			leftList.end->right = x;
		x->left = leftList.end;
		x->right = rightList.start;
		if (rightList.start != nullptr)
			rightList.start = x;
		return Info(leftList.start == nullptr ? x : leftList.start,
			rightList.end == nullptr ? x : rightList.end);
	}
};