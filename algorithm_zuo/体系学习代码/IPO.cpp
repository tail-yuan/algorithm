#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//k:需要做多少个
//M:本金
//profits:利润
//capital:做每个任务的门槛钱
// 贪心思想
//花费建立小跟堆, 利润建立大根堆
//将能力所及的项目全部解锁, 按照收益利润->大根堆中

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
		return e1->p < e2->p;//以利润建立大堆
	}
};
struct Greater
{
	bool operator()(const Node*& e1, const Node*& e2)
	{
		return e1->c > e2->c;//以门槛建立小堆
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
		if (minCost.empty())//可能存在把能做的做完了,但是还是没满足K 个任务的指标
			return M;
		M += maxProfits.top()->p; maxProfits.pop();
	}
	return M;
}