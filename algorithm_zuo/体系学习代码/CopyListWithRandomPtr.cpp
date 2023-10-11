#include<iostream>
#include<unordered_map>
using namespace std;

//使用哈希表记录<老节点,新节点>,根据链表中节点的指向关系,连接新的节点
class Node
{

public:
	int val;
	Node* next;
	Node* rand;
	Node(int v = 0)
		:val(v)
		, next(nullptr)
		, rand(nullptr)
	{}
};
Node* copyListWithRandPtr1(Node* head)
{
	if (head == nullptr)
		return head;
	unordered_map<Node*, Node*> hashMap;
	Node* cur = head;
	while (cur)
	{
		Node* newNode = new Node(cur->val);
		hashMap.insert(cur, newNode);
		cur = cur->next;
	}
	cur = head;
	while (cur)
	{
		hashMap[cur]->next = cur->next;
		hashMap[cur]->rand = cur->rand;
		cur = cur->next;
	}
	return hashMap[head];
}

//产生copyNode链接在每一个Node 后面,取的时候就可以一对一对取,根据一对的第一个的指向,可以获取到copyNode应该的指向
//空间复杂度O(1)只用到了几个变量
Node* copyListWithRandPtr2(Node* head)
{
	if (head == nullptr)
		return;
	Node* cur = head;
	//copy node and link its behind
	while (cur)
	{
		Node* next = cur->next;
		Node* copyNode = new Node(cur->val);
		cur->next = copyNode;
		copyNode->next = next;

		cur = next;
	}
	cur = head;
	Node* copyNode = nullptr;
	//set copyNode rand ptr
	while (cur)
	{
		copyNode = cur->next;
		Node* next = cur->next->next;
		copyNode->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
		cur = next;
	}
	Node* res = head->next;
	cur = head;
	//split list 
	while (cur)
	{
		Node* next = cur->next->next;
		copyNode = cur->next;
		cur->next = next;
		copyNode->next = next==nullptr?nullptr:next->next;
		cur = next;
	}
	return res;
}

