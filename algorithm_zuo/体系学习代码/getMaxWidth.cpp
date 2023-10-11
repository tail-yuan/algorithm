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
//宽度优先遍历
//1. 头结点进队
//2. 弹出节点,孩子节点进队
//3. 周而复始
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
//获取最大宽度以及是哪一层
//1. 使用哈希表记录<节点cur,在哪一层curLevel>,在每个节点进入队列时.
//2. curLevelNodes++ if 还在curLevel上
//3. 通过弹栈时hashMap[节点]==curNodeLevel确定是否还是之前的curLevel
//只有进栈的时候保证节点知道在哪一层,出栈的时候才能记住
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
		if (curNodeLevel == curLevel)//还是同一层的
			curLevelNodes++;
		else//已经遍历到下一层的节点,并且是第一个
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

//不适用哈希表,只使用几个变量
//1. curEnd 当前层最后一个节点
//	 nextEnd 下一层最后一个节点,每进队一个节点node,就持续更新nextEnd=node
//   curLevelNodes 当前层已经发现的节点数
//   maxNodes

//2. 当前节点cur?=curEnd,
//	 是->更新maxNodes,已经是这层的最后一个节点了
//		开始遍历下一层了,需要将curEnd=nextEnd nextEnd=nullptr curLevelNodes=0
//   不是->curLevelNodes++
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
