#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//�������п��ٻ�ȡ��λ��
//����һ�����maxHeap,һ��С��minHeap
//1. if num <=maxHeap.top(),->maxHeap,or ->minHeap
//2. �����������һ���ѵ�size>��һ��=2,��sizeС�ĶѶ�Ԫ��->��һ����
class MadianQuick
{
public:
	void modifyTwoHeapsSize()
	{
		if (maxHeap.size() - minHeap.size() == 2)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		if (minHeap.size() - maxHeap.size() == 2)
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}
	void addNum(int x)
	{
		if (x < maxHeap.top() || maxHeap.empty())
			maxHeap.push(x);
		else
			minHeap.push(x);
		modifyTwoHeapsSize();
	}
	int getMidNum()
	{
		int maxSize = maxHeap.size();
		int minSize = minHeap.size();
		if (maxSize + minSize == 0)
			return 0;

		int maxOfMaxHeap = maxHeap.top();
		int minOfMinHeap = minHeap.top();
		if ((maxSize + minSize) % 2 == 0)
			return (maxOfMaxHeap + minOfMinHeap) / 2;
		return maxSize > minSize ? maxSize : minSize;
	}
private:
	priority_queue<int, vector<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
};