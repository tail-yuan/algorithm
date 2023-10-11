#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct Node
{
	int val;
	struct Node* next;
};

//使用数组装填节点,在数组中玩partition更改节点下标位置,按下标依次连接节点

void arrPartition(vector<Node*>& nodeArr, int pivot)
{
	int small = -1;
	int big = nodeArr.size();
	int index = 0;
	while (index != big)
	{
		if (nodeArr[index]->val < pivot)
		{
			swap(nodeArr[++small],nodeArr[index++]);//值交换即节点交换即包装的值交换
		}
		else if (nodeArr[index]->val > pivot)
		{
			swap(nodeArr[--big],nodeArr[index]);
		}
		else
		{
			index++;
		}
	}
}
Node* ListPartition1(Node* head,int pivot)
{
	if (head == nullptr)
		return head;
	//记录多少个节点,方便开数组空间
	Node* cur = head;
	int i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	//
	vector<Node*> nodeArr(i);
	i = 0;
	cur = head;
	for (i = 0; i < nodeArr.size(); i++)
	{
		nodeArr[i] = cur;
		cur = cur->next;
	}
	//
	arrPartition(nodeArr,pivot);
	//根据数组内容,拼接新的链表返回
	for (i = 1; i < nodeArr.size(); i++)
	{
		nodeArr[i - 1]->next = nodeArr[i];
	}
	nodeArr[i - 1]->next = nullptr;
	return nodeArr[0];
}

//使用六个指针变量,记录[small][equal][big]3个区域
//利用链表性质,属于一个区域的直接相连,
//最后,6个指针变量相连(注意判空)
//maybe 不存在三个区间中任何x个即指针可为空
Node* ListPartition2(Node* head, int pivot)
{
	Node* sHead = nullptr;
	Node* sTail = nullptr;
	Node* eHead = nullptr;
	Node* eTail = nullptr;
	Node* bHead = nullptr;
	Node* bTail = nullptr;

	Node* next = nullptr;
	while (head != nullptr)
	{
		next = head->next;
		head->next = nullptr;
		if (head->val < pivot)
		{
			if (sHead == nullptr)//遇到的第一个小的节点
			{
				sHead = head;
				sTail = head;
			}
			else
			{
				sTail->next = head;
				sTail = head;
			}
		}
		else if (head->val > pivot)
		{
			if (bHead == nullptr)
			{
				bHead = head;
				bTail = head;
			}
			else
			{
				bTail->next = head;
				bTail = head;
			}
		}
		else
		{
			if (eHead == nullptr)
			{
				eHead = head;
				eTail = head;
			}
			else
			{
				eTail->next = head;
				eTail = head;
			}
		}
		head = head->next;
	}//end while

	if (sTail != nullptr)
	{
		sTail->next = eHead;
		eTail = eTail == nullptr ? sTail : eTail;//不存在[equal]区间的话直接和小区间合并
	}
	if (eTail != nullptr)
	{
		eTail->next = bHead;
	}

	return sHead != nullptr ? sHead : eHead != nullptr ? eHead : bHead;
}