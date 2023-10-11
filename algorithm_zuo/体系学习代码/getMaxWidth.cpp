#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
class Node
{
public:
	int val;
	Node* left;
	Node* right;
};
//������ȱ���
//1. ͷ������
//2. �����ڵ�,���ӽڵ����
//3. �ܶ���ʼ
void BreadFirstTravel(Node* head)
{
	if (head == nullptr)return;
	queue<Node*>q;
	q.push(head);
	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();
		cout << node->val << " ";
		if (node->left)
			q.push(node);
		if (node->right)
			q.push(node);
	}
}
//��ȡ������Լ�����һ��
//1. ʹ�ù�ϣ���¼<�ڵ�cur,����һ��curLevel>,��ÿ���ڵ�������ʱ.
//2. curLevelNodes++ if ����curLevel��
//3. ͨ����ջʱhashMap[�ڵ�]==curNodeLevelȷ���Ƿ���֮ǰ��curLevel
//ֻ�н�ջ��ʱ��֤�ڵ�֪������һ��,��ջ��ʱ����ܼ�ס
int getMaxWidth1(Node* head)
{
	if (head == nullptr)return 0;
	queue<Node*>q;
	q.push(head);
	unordered_map<Node*, int>hashMap;
	hashMap.insert(make_pair(head,1));
	int curLevel = 1;
	int curLevelNodes = 0;
	int maxWidth = INT_MIN;
	while (!q.empty())
	{
		Node* cur = q.front();
		q.pop();
		int curNodeLevel = hashMap[cur];
		if (curNodeLevel == curLevel)//����ͬһ���
			curLevelNodes++;
		else//�Ѿ���������һ��Ľڵ�,�����ǵ�һ��
		{
			maxWidth = max(maxWidth, curLevelNodes);
			curLevel++;
			curLevelNodes = 1;
		}
		if (cur->left)
		{
			q.push(cur->left);
			hashMap.insert(make_pair(cur->left, curNodeLevel + 1));
		}
		if (cur->right)
		{
			q.push(cur->right);
			hashMap.insert(make_pair(cur->right, curNodeLevel + 1));
		}
	}
}

//�����ù�ϣ��,ֻʹ�ü�������
//1. curEnd ��ǰ�����һ���ڵ�
//	 nextEnd ��һ�����һ���ڵ�,ÿ����һ���ڵ�node,�ͳ�������nextEnd=node
//   curLevelNodes ��ǰ���Ѿ����ֵĽڵ���
//   maxNodes

//2. ��ǰ�ڵ�cur?=curEnd,
//	 ��->����maxNodes,�Ѿ����������һ���ڵ���
//		��ʼ������һ����,��Ҫ��curEnd=nextEnd nextEnd=nullptr curLevelNodes=0
//   ����->curLevelNodes++
//wait for test!
int getMaxWidth2(Node* head)
{
	if (head == nullptr)
		return 0;
	Node* curEnd = head;
	Node* nextEnd = nullptr;
	int maxNodes = INT_MIN;
	int curLevelNodes = 1;
	queue<Node*>q;
	q.push(head);
	while (!q.empty())
	{
		Node* cur = q.front(); q.pop();
		if (cur->left)
		{
			q.push(cur->left);
			nextEnd = cur->left;
		}
		if (cur->right)
		{
			q.push(cur->right);
			nextEnd = cur->right;
		}

		if (cur == curEnd)
		{
			maxNodes = max(maxNodes, curLevelNodes);
			curEnd = nextEnd;
			curLevelNodes = 0;
		}
		else
			curLevelNodes++;
	}
}
