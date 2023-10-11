#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
//左子树都小,右子树都打,中序肯定是有序的,并且没有重复值.
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
int preVal = INT_MIN;
bool checkBST(Node* head)
{
	if (head == nullptr)return true;
	bool isLeftBST = checkBST(head->left);
	if (!isLeftBST)
		return false;
	//在中序遍历的打印时机改为比较时机
	if (head->val < preVal)
		return false;
	else
		preVal = head->val;
	return checkBST(head->right);
}

//在中序遍历的打印时机改为比较时机
void process_2(Node* head, list<Node*>& inorder_lt)
{
	if (head == nullptr)return;
	process_2(head->left, inorder_lt);
	inorder_lt.push_back(head);
	process_2(head->right, inorder_lt);
}
bool checkBST_2(Node* head)
{
	list<Node*> inorder_lt;
	process_2(head, inorder_lt);
	//检查是否升序(lt支持迭代器)
	for (auto e:inorder_lt)
	{
		if (preVal > e->val)
			return false;
		preVal = e->val;
	}
	return true;
}


bool cheakBSTUnRecur(Node* head)
{
	if (head == nullptr) return true;
	stack<Node*>st;
	while (!st.empty()||head!=nullptr)
	{
		if (head)
		{
			st.push(head);
			head->left;
		}
		else
		{
			head = st.top(); st.pop();
			//do ...
			if (preVal > head->val)
				return false;
			else
				preVal = head->val;
			head = head->right;
		}
	}
	return true;
}

//二叉树递归套路
class ReturnData
{
public:
	bool isBST;
	int maxVal;
	int minVal;
public:
	ReturnData(bool is=true, int max_=INT_MIN, int min_=INT_MAX)
		:isBST(is)
		, maxVal(max_)
		, minVal(min_)
	{}
};
ReturnData* process3(Node* head)
{
	if (head == nullptr)
		return nullptr;
	
	ReturnData* leftData = process3(head->left);
	ReturnData* rightData = process3(head->right);
	//需要的三个信息,进行获取与更新
	//向左右子树要信息
	int min_val = head->val;
	int max_val = head->val;
	if (leftData)
	{
		min_val = min(min_val, head->val);
		max_val = max(max_val, head->val);
	}
	if (rightData)
	{
		min_val = min(min_val, head->val);
		max_val = max(max_val, head->val);
	}
	bool isBST_ = true;//违规条件判断
	if (leftData && (leftData->isBST == false || leftData->maxVal >= head->val))
		isBST_ = false;
	if (rightData && (rightData->isBST == false || rightData->minVal <= head->val))
		isBST_ = false;

	return new ReturnData(isBST_,max_val,min_val);
}
bool checkBST2(Node* head)
{
	return process3(head)->isBST;
}