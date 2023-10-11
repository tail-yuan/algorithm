#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
// ��¼ÿһ���ڵ�ĸ��׽ڵ�->hashMap��,��������׷��
// ��o1 ��ʼ����׷�ݷ��뵽hashSet������һ��o1���ϻ��ݵ�����,
// �ٴ�o2��ʼ������,ֱ��������һ����hashSet�еĽڵ�,���������������
// ע�⴦��head�ڵ�ĸ��׽ڵ�����Ϊ����

void process(Node* head, unordered_map<Node*, Node* >& hashMap)
{
	if (head == nullptr)return;

	hashMap.insert(make_pair(head->left, head));
	hashMap.insert(make_pair(head->right, head));

	process(head->left, hashMap);
	process(head->right, hashMap);
}

Node* lowestCommonFatherNode1(Node* head, Node* o1, Node* o2)
{
	unordered_map<Node*, Node* >hashMap;
	hashMap.insert(make_pair(head,head));
	process(head,hashMap);
	unordered_set<Node*> hashSet;
	Node* cur = o1;
	while (cur != hashMap[cur])
	{
		hashSet.insert(cur);
		cur = hashMap[cur];
	}
	hashSet.insert(head);
	cur = o2;
	while (hashSet.count(cur) == 0)//��o1������û�ҵ�,��˵���˽ڵ㲻��,����������
	{
		cur = hashMap[cur];
	}
	return cur;
}

Node* lowestCommonFatherNode2(Node* head, Node* o1, Node* o2)
{
	if (head == nullptr || head == o1 || head == o2)
		return head;
	Node* left_ret = lowestCommonFatherNode2(head->left, o1, o2);
	Node* right_ret = lowestCommonFatherNode2(head->right, o1, o2);
	if (right_ret != nullptr || left_ret != nullptr)
		return head;
	return left_ret == nullptr ? right_ret : left_ret;
}
