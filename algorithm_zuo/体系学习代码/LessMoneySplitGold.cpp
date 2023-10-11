#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int lessMoneySplitGold(vector<int>&arr)
{
	priority_queue<int, vector<int>, greater<int>> heap;//Ð¡¸ù¶Ñ
	for (int e : arr)
		heap.push(e);
	int sum = 0;
	int cur = 0;
	while (heap.size() > 1)
	{
		int n1 = heap.top(); heap.pop();
		int n2 = heap.top(); heap.pop();
		cur = n1 + n2;
		sum += cur;
		heap.push(cur);
	}
	return sum;
}
int main()
{
}