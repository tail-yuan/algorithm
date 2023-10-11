#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
//https://www.bilibili.com/video/BV1kg4y137UU/?spm_id_from=333.337.search-card.all.click&vd_source=cc945ef88574fe2db5e814c0c265a4c7
struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
pair<ListNode*, ListNode*>reverseOneList(ListNode* head, ListNode* end)
{
	ListNode* prev = end->next;
	ListNode* p = head;
	while (end != prev)
	{
		ListNode* next = p->next;
		p->next = prev;
		prev = p;
		p = next;
	}
	return { end,head };
	//缺少head为空时候的判断
	//ListNode* pHead = new ListNode(-1);
	//ListNode* tail = nullptr;
	//while (head!=end->next)
	//{
	//	ListNode* next = head->next;
	//	head->next = pHead->next;
	//	pHead->next = head;
	//	if (head->next == nullptr) tail = head;//记录尾巴
	//	head = next;
	//}
	//return {pHead->next,tail};

}
ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode* dummy = new ListNode(-1);//设置头结点
	dummy->next = head;
	ListNode* pre=dummy, *end=dummy;
	while (head)
	{
		end = pre;
		for (int i = 0; i < k; i++)
		{
			end = end->next;
			if (end == nullptr)
				return dummy->next;
		}
		ListNode* start = end->next;
		//翻转链表函数
		pair<ListNode*,ListNode*>ret=reverseOneList(head,end);
		end = ret.second;
		head = ret.first;

		pre->next = head;
		end->next = start;

		pre = end;
		head = end->next;
	}
	return dummy->next;
}