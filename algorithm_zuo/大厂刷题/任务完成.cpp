#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//题目要求:
//给定一个n * 2的二维数组，表示有n个任务一个信息是任务能够开始做的时间，
//另一个信息是任务的结束期限，后者一定大于前者，且数值上都是正数你作为单线程的人，
//不能并行处理任务但是每个任务都只需要一个单位时间完成你需要将所有任务的执行时间，
//位于开始做的时间和最后期限之间返回你能否做到这一点
//题解:
//https://www.bilibili.com/video/BV1pe4y1m7iK/?spm_id_from=333.999.0.0&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//将开始时间和截止时间混在一起进行排序,标识开始结束标志
//就维护了一个时间线,在同一时间i收到多个任务,那么以结束时间维护一个小根堆,堆顶肯定是截止时间最早,
//最紧迫需要先执行的那个
//只要有时间差就开始做任务,做一个任务只消耗1的时间差
//返回false: 遇到开始标志,就收集对应start的end放入小根堆中,
//			只要有时间差就消耗小根堆中的任务,
//			如果遇到end标志的数据时小根堆中还有数据,
// 并且top().end <= [end]返回false,说明应该在end之前,还有任务没完成.
//返回true:如果到结尾时小根堆为空,说明完成
//优化: 记录lastTime即上一个做任务的时间,当遇到start标识时入堆,直到遇到第一个end时一起做end-lastTime
//这么多个任务,不用一步一步记录lasttime一步步做
class Solution
{
public:
	class TimePoint
	{
	public:
		int time;
		int end;
		bool add;//add=true,任务是start,需要使用伴随数据end添加到小根堆.
		//add=false,任务是end,查看堆顶数据以及往后继续进行.
		TimePoint(int t=0, int e=0, int a=0)
			:time(t)
			, end(e)
			, add(a)
		{}
	};
	struct compare
	{
		bool operator()(TimePoint& t1,TimePoint & t2)
		{
			return t1.time < t2.time;
		}
	};
	bool canDo(vector<vector<int>>& jobs)
	{
		int n = jobs.size();
		vector<TimePoint>arr(2*n);
		for (int i = 0; i < n; i++)
		{
			arr[i] = TimePoint(jobs[i][0],jobs[i][1],true);
			arr[i + n] = TimePoint(jobs[i][1], jobs[i][1], false);
		}
		sort(arr.begin(), arr.end(), compare());
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0,lastTime=arr[0].time; i < arr.size(); i++)
		{
			if (arr[i].add == true)
			{
				pq.push(arr[i].end);
			}
			else
			{
				int curTime = arr[i].time;
				for (int j = lastTime; j < curTime; j++)
				{
					if (pq.empty())//任务做没了
						break;
					pq.pop();
				}
				if (!pq.empty()&&pq.top() <= curTime)
					return false;
			}
		}
		return true;
	}
};
int main()
{
	Solution s;
	vector<vector<int>>arr{{1, 3}, { 3,4 }, { 5,6 }};

	cout<<s.canDo(arr);
	return 0;
}