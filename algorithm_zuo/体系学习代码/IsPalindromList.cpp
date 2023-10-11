#include<iostream>
#include<stack>
using namespace std;
struct Node
{
	int val;
	struct Node* next;
};
//笔试 使用栈结构 空间复杂度O(N)
bool isPalindrome1(Node* head)
{
	stack<Node*> st;
	Node* cur = head;
	while (cur)
	{
		st.push(cur);
		cur = cur->next;
	}
	while (head)
	{
		Node* top = st.top();

		if (head->val != top->val)
		{
			return false;
		}
		head = head->next;
		st.pop();
	}
	return true;
}
//快慢指针,确定中点,记录首尾指针,改变右侧指向,同时next判断,还原指针指向
//空间复杂度O(1)
bool isPalindrome2(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return true;
	Node* n1 = head;
	Node* n2 = head;
	while (n2->next != nullptr && n2->next->next != nullptr)
	{
		n1 = n1->next;
		n2 = n2->next->next;
	}
	//n1 ->mid n2->end
	//changing the directions of the second part
	n2 = n1->next;
	n1->next = nullptr;
	Node* n3 = nullptr;
	while (n2)
	{
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
	n2 = head;
	n3 = n1;
	bool res = true;
	while (n1 && n2)
	{
		if (n1->val != n2->val)
		{
			res = false;
			break;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	//recover list
	n1 = n3->next;
	n3->next = nullptr;
	while (n1)
	{
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
	return res;
}