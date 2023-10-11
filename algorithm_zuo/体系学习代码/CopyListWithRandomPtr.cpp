#include<iostream>
#include<unordered_map>
using namespace std;

//ʹ�ù�ϣ���¼<�Ͻڵ�,�½ڵ�>,���������нڵ��ָ���ϵ,�����µĽڵ�
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

//����copyNode������ÿһ��Node ����,ȡ��ʱ��Ϳ���һ��һ��ȡ,����һ�Եĵ�һ����ָ��,���Ի�ȡ��copyNodeӦ�õ�ָ��
//�ռ临�Ӷ�O(1)ֻ�õ��˼�������
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

