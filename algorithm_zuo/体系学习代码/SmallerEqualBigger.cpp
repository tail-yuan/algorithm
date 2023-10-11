#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct Node
{
	int val;
	struct Node* next;
};

//ʹ������װ��ڵ�,����������partition���Ľڵ��±�λ��,���±��������ӽڵ�

void arrPartition(vector<Node*>& nodeArr, int pivot)
{
	int small = -1;
	int big = nodeArr.size();
	int index = 0;
	while (index != big)
	{
		if (nodeArr[index]->val < pivot)
		{
			swap(nodeArr[++small],nodeArr[index++]);//ֵ�������ڵ㽻������װ��ֵ����
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
	//��¼���ٸ��ڵ�,���㿪����ռ�
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
	//������������,ƴ���µ�������
	for (i = 1; i < nodeArr.size(); i++)
	{
		nodeArr[i - 1]->next = nodeArr[i];
	}
	nodeArr[i - 1]->next = nullptr;
	return nodeArr[0];
}

//ʹ������ָ�����,��¼[small][equal][big]3������
//������������,����һ�������ֱ������,
//���,6��ָ���������(ע���п�)
//maybe �����������������κ�x����ָ���Ϊ��
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
			if (sHead == nullptr)//�����ĵ�һ��С�Ľڵ�
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
		eTail = eTail == nullptr ? sTail : eTail;//������[equal]����Ļ�ֱ�Ӻ�С����ϲ�
	}
	if (eTail != nullptr)
	{
		eTail->next = bHead;
	}

	return sHead != nullptr ? sHead : eHead != nullptr ? eHead : bHead;
}