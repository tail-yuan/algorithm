#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//��ĿҪ��:
//����һ��n * 2�Ķ�ά���飬��ʾ��n������һ����Ϣ�������ܹ���ʼ����ʱ�䣬
//��һ����Ϣ������Ľ������ޣ�����һ������ǰ�ߣ�����ֵ�϶�����������Ϊ���̵߳��ˣ�
//���ܲ��д���������ÿ������ֻ��Ҫһ����λʱ���������Ҫ�����������ִ��ʱ�䣬
//λ�ڿ�ʼ����ʱ����������֮�䷵�����ܷ�������һ��
//���:
//https://www.bilibili.com/video/BV1pe4y1m7iK/?spm_id_from=333.999.0.0&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//����ʼʱ��ͽ�ֹʱ�����һ���������,��ʶ��ʼ������־
//��ά����һ��ʱ����,��ͬһʱ��i�յ��������,��ô�Խ���ʱ��ά��һ��С����,�Ѷ��϶��ǽ�ֹʱ������,
//�������Ҫ��ִ�е��Ǹ�
//ֻҪ��ʱ���Ϳ�ʼ������,��һ������ֻ����1��ʱ���
//����false: ������ʼ��־,���ռ���Ӧstart��end����С������,
//			ֻҪ��ʱ��������С�����е�����,
//			�������end��־������ʱС�����л�������,
// ����top().end <= [end]����false,˵��Ӧ����end֮ǰ,��������û���.
//����true:�������βʱС����Ϊ��,˵�����
//�Ż�: ��¼lastTime����һ���������ʱ��,������start��ʶʱ���,ֱ��������һ��endʱһ����end-lastTime
//��ô�������,����һ��һ����¼lasttimeһ������
class Solution
{
public:
	class TimePoint
	{
	public:
		int time;
		int end;
		bool add;//add=true,������start,��Ҫʹ�ð�������end��ӵ�С����.
		//add=false,������end,�鿴�Ѷ������Լ������������.
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
					if (pq.empty())//������û��
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