#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//为了找到自己满意的工作， 牛牛收集了每种工作的难度和报酬。 牛牛选工作的标准是在难度不超过自身能力
//值的情况下， 牛牛选择报酬最高的工作。 在牛牛选定了自己的工作后， 牛牛的小伙伴们来找牛牛帮忙选工作，
//牛牛依然使用自己的标准来帮助小伙伴们。 牛牛的小伙伴太多了， 于是他只好把这个任务交给了你。

//解法: 每一份工作,按照难度从小到大排序,难度相同的按照报酬从大到小排序
//		1. 之后,难度相同的也就是同一组的,除了组长之外,其余全部删掉.(难度相同时没必要选择报酬少的,岗位又不止一个)
//		2. 保证单调性,即难度递增时报酬也是递增的,将按照难度升序的表中不满足的工作删除
// 之后,每个人按照自身能力选择最靠近小于等于自己的难度的工作,就是最大的报酬.
// 使用有序表map
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
		//排序策略:难度递增,难度相同时报酬递减
		sort(job.begin(),job.end(),compare());

		//将1.2.满足条件的工作加入到map中
		map<int, int>my_map;
		my_map.insert(make_pair(job[0].hard, job[0].money));
		Job pre = job[0];
		for (int i = 1; i < job.size(); i++)
		{
			//难度递增时报酬必须递增的单调性
			//!=保证了只让难度相同时报酬最大的工作进入
			if (job[i].hard != pre.hard && job[i].money > pre.money)
			{
				pre = job[i];
				my_map.insert({pre.hard,pre.money});
			}
		}
		vector<int>res(ability.size());
		for (int i = 0; i < ability.size(); i++)
		{
			auto it= my_map.lower_bound(ability[0]);//返回大于等于它最小的
			if (it != my_map.begin())
				--it;
			//return it->first; 小于等于它最大的即floorKey的功能
			if (it == my_map.end())
				res[i] = 0;
			else
				res[i] = it->second;
		}
		return res;
	}
};