#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//Ϊ���ҵ��Լ�����Ĺ����� ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣ ţţѡ�����ı�׼�����ѶȲ�������������
//ֵ������£� ţţѡ�񱨳���ߵĹ����� ��ţţѡ�����Լ��Ĺ����� ţţ��С���������ţţ��æѡ������
//ţţ��Ȼʹ���Լ��ı�׼������С����ǡ� ţţ��С���̫���ˣ� ������ֻ�ð�������񽻸����㡣

//�ⷨ: ÿһ�ݹ���,�����Ѷȴ�С��������,�Ѷ���ͬ�İ��ձ���Ӵ�С����
//		1. ֮��,�Ѷ���ͬ��Ҳ����ͬһ���,�����鳤֮��,����ȫ��ɾ��.(�Ѷ���ͬʱû��Ҫѡ�񱨳��ٵ�,��λ�ֲ�ֹһ��)
//		2. ��֤������,���Ѷȵ���ʱ����Ҳ�ǵ�����,�������Ѷ�����ı��в�����Ĺ���ɾ��
// ֮��,ÿ���˰�����������ѡ�����С�ڵ����Լ����ѶȵĹ���,�������ı���.
// ʹ�������map
class Job
{
public:
	int money;
	int hard;
	Job(int m, int h)
		:money(m)
		, hard(h)
	{}
};

class ChooseWork
{
public:
	struct compare
	{
		int operator()(const Job& j1, const Job& j2)
		{
			return j1.hard != j2.hard ? j1.hard - j2.hard : j1.money - j2.money;
		}
	};
	vector<int> getMaxMoney(vector<Job>& job, vector<int>& ability)
	{
		//�������:�Ѷȵ���,�Ѷ���ͬʱ����ݼ�
		sort(job.begin(),job.end(),compare());

		//��1.2.���������Ĺ������뵽map��
		map<int, int>my_map;
		my_map.insert(make_pair(job[0].hard, job[0].money));
		Job pre = job[0];
		for (int i = 1; i < job.size(); i++)
		{
			//�Ѷȵ���ʱ�����������ĵ�����
			//!=��֤��ֻ���Ѷ���ͬʱ�������Ĺ�������
			if (job[i].hard != pre.hard && job[i].money > pre.money)
			{
				pre = job[i];
				my_map.insert({pre.hard,pre.money});
			}
		}
		vector<int>res(ability.size());
		for (int i = 0; i < ability.size(); i++)
		{
			auto it= my_map.lower_bound(ability[0]);//���ش��ڵ�������С��
			if (it != my_map.begin())
				--it;
			//return it->first; С�ڵ��������ļ�floorKey�Ĺ���
			if (it == my_map.end())
				res[i] = 0;
			else
				res[i] = it->second;
		}
		return res;
	}
};