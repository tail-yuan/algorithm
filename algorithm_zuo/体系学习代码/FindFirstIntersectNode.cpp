#include<iostream>
#include<unordered_map>
using namespace std;
class Node
{
public:
	int val;
	Node* next;
	Node(int v = 0)
		:val(v)
		, next(nullptr)
	{}
};
Node* noLoop(Node* head1, Node* head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	Node* cur1 = head1;
	Node* cur2 = head2;
	int n = 0;
	while (cur1->next)
	{
		n++;
		cur1 = cur1->next;
	}
	while (cur2->next)
	{
		n--;
		cur2 = cur2->next;
	}
	//���β�Ͳ�ͬ,˵��û�н���
	if (cur1 != cur2)
		return nullptr;

	//cur1ָ�򳤵�,cur2ָ��̵�
	cur1 = n < 0 ? head2 : head1;
	cur2 = cur1 == head1 ? head2 : head1;
	n = abs(n);
	while (n--)
		cur1 = cur1->next;
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}
Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2)
{
	Node* cur1 =nullptr;
	Node* cur2 = nullptr;
	if (loop1 == loop2)
	{
		cur1 = head1;
		cur2 = head2;
		int n = 0;
		while (cur1!=loop1)
		{
			n++;
			cur1 = cur1->next;
		}
		while (cur2!=loop2)
		{
			n--;
			cur2 = cur2->next;
		}
		//cur1ָ�򳤵�,cur2ָ��̵�
		cur1 = n < 0 ? head2 : head1;
		cur2 = cur1 == head1 ? head2 : head1;
		n = abs(n);
		while (n--)
			cur1 = cur1->next;
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}//end if(loop1==loop2)
	else
	{
		cur1 = loop1->next;
		while (cur1 != loop1)
		{
			if (cur1 == loop2)//��������������ͬ�뻷�ڵ�,�����ĸ�����
				return loop1;
			cur1 = cur1->next;
		}
		//�������������������õĻ�,Ҳ���ཻ
		return nullptr;
	}
}
Node* getLoopNode(Node* head)
{
	//�����ɻ�
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return nullptr;
	Node* n1 = head->next;//slow ptr
	Node* n2 = head->next->next;//fast ptr
	while (n1 != n2)
	{
		//������ʱʱ��ע���Ƿ�Ϊ��
		if (n2->next->next == nullptr || n2->next == nullptr)
			return nullptr;

		n1 = n1->next;
		n2 = n2->next->next;
	}
	n2 = head;
	while (n1 != n2)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n1;
}
Node* getIntersectNode(Node* head1, Node* head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	Node* loop1 = getLoopNode(head1);
	Node* loop2 = getLoopNode(head2);
	if (loop1 == nullptr && loop2 == nullptr)
		return noLoop(head1,head2);
	if (loop1 != nullptr && loop2 != nullptr)
		return bothLoop(head1,loop1,head2,loop2);
	return nullptr;
}