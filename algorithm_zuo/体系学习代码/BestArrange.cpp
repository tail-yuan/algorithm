#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//按照会议结束时间早的安排会议会得到最优解,返回最多安排多少个会议
//1. 先按照结束时间排序
//2. 找到结束时还没开始的会议(最早的)安排
class Program
{
public:
	int start;
	int end;
	Program(int s=0,int e=0)
	{
		start = s;
		end = e;
	}
};
struct Greater
{
	bool operator()(const Program& p1, const Program& p2)
	{
		return p1.end < p2.end;//排升序
	}
};
int bestArray(vector<Program>& arr, int time)//time是代表从某时刻开始安排
{
	sort(arr.begin(), arr.end(), Greater());
	int res = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (time < arr[i].start)
		{
			res++;
			time = arr[i].end;
		}
	}
	return res;
}