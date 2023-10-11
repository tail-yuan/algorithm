#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
//��������С,����������,����϶��������,����û���ظ�ֵ.
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
	//����������Ĵ�ӡʱ����Ϊ�Ƚ�ʱ��
	if (head->val < preVal)
		return false;
	else
		preVal = head->val;
	return checkBST(head->right);
}

//����������Ĵ�ӡʱ����Ϊ�Ƚ�ʱ��
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
	//����Ƿ�����(lt֧�ֵ�����)
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

//�������ݹ���·
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
	//��Ҫ��������Ϣ,���л�ȡ�����
	//����������Ҫ��Ϣ
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
	bool isBST_ = true;//Υ�������ж�
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