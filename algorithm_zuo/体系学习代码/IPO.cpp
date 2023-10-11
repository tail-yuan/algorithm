#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//k:��Ҫ�����ٸ�
//M:����
//profits:����
//capital:��ÿ��������ż�Ǯ
// ̰��˼��
//���ѽ���С����, �����������
//��������������Ŀȫ������, ������������->�������

class Node
{
public:
	int p;
	int c;
	Node(int p1, int c1)
		:p(p1)
		, c(c1)
	{}
};
struct Less
{
	bool operator()(const Node*& e1, const Node*& e2)
	{
		return e1->p < e2->p;//�����������
	}
};
struct Greater
{
	bool operator()(const Node*& e1, const Node*& e2)
	{
		return e1->c > e2->c;//���ż�����С��
	}
};
int findMaximizedCapital(int k, int M, vector<int>& profits, vector<int>& capital)
{
	vector<Node*>arr;
	for (int i = 0; i < profits.size(); i++)
	{
		arr[i] = new Node(capital[i],profits[i]);
	}
	priority_queue<Node*, vector<Node*>,Less()> maxProfits;
	priority_queue<Node*, vector<Node*>,Greater()> minCost;
	for (int i = 0; i < arr.size(); i++)
		minCost.push(arr[i]);
	for (int i = 0; i < k; i++)
	{
		while (!minCost.empty() && minCost.top()->c <= M)
		{
			maxProfits.push(minCost.top());
			minCost.pop();
		}
		if (minCost.empty())//���ܴ��ڰ�������������,���ǻ���û����K �������ָ��
			return M;
		M += maxProfits.top()->p; maxProfits.pop();
	}
	return M;
}