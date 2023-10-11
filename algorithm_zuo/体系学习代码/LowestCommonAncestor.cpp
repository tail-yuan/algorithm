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
// 记录每一个节点的父亲节点->hashMap中,方便向上追溯
// 从o1 开始向上追溯放入到hashSet中生成一个o1向上回溯的链表,
// 再从o2开始向上找,直到遇到第一个在hashSet中的节点,就是最近公共祖先
// 注意处理head节点的父亲节点设置为本身

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
	while (hashSet.count(cur) == 0)//在o1链表中没找到,就说明此节点不是,继续向上找
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
