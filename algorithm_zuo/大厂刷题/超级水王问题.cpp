//水王问题:
//存在一个数字,出现的次数超过了数组的一半.
//时间复杂度O(n),空间复杂度O(1).所以什么排序啦,哈希表统计词频啦都不行.

//题解:https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=33&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//删掉两个不同的数字,水王肯定会留下来.如果到最后剩下的不是水王数,数组就没有水王数
//1. 没有数字剩下,无水王数
//2. 有数字剩下,就拿着x再去遍历一遍,统计他的次数.看看是否是水王数.
//问题是: 如何删除两个不同的数字
//两个变量: 候选candidate以及count
//当count=0时,候选candidate=0
//从前往后遍历,如果无候选, candidate = cur
//如果有候选,if cur==candidate count++ else -- //实现不同数字抵消的操作
//最后如果count==0,代表无数字剩下,count!=0,candidate就是剩下的数字

//拓展: 如何找到出现次数>N/k次的数字,可能有多个.k==2时就是基础水王问题
//>n/k的数字至多有k-1个数字,那么就搞一张表记录候选数字,表的大小就是k-1
//候选表: <key,count> map,当map.size()<k-1时,map[key]++. map.size()==k时,表中数据集体map[key]--
//当count=0的数字还需要从表中移除,这样表中剩下的数字就是候选数字,再去统计候选数字的词频.必须验证真实性.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	int FindKMajority(vector<int>&arr)
	{
		int n = arr.size();
		if (n == 0)return -1;
		int cand = 0,count = 0;
		for (int i = 0; i < n; i++)
		{
			if (cand == 0)
			{
				cand = arr[i];
				count++;
			}
			else
			{
				if (cand == arr[i])
					count++;
				else
					count--;
			}
		}
		if (count == 0)
			return -1;
		count = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == cand)
				count++;
		}
		if (count > n / 2)
			return cand;
		else
			return -1;
	}
public:
	//拓展
	vector<int> printKMajor(vector<int>& arr,int k)
	{
		if (k < 2)
			return {};
		unordered_map<int, int>hashMap;
		for (int i = 0; i < arr.size(); i++)
		{
			if (hashMap.size() < k)
				hashMap[arr[i]]++;
			else
			{
				allCandsSubOne(hashMap);
			}
		}
		//所有的候选都在表中,必须验证一遍真实性
		vector<int>ans;
		for (auto e : hashMap)
			e.second = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			int num = arr[i];
			if (hashMap.find(num) != hashMap.end())
				hashMap[num]++;
		}
		for (auto e : hashMap)
			if (e.second > arr.size() / k)
				ans.push_back(e.first);
		return ans;
	}
	void allCandsSubOne(unordered_map<int, int>& hashMap)
	{
		vector<int>deleteIt;
		for (auto e : hashMap)
		{
			e.second--;
			if (e.second == 0)
				deleteIt.push_back(e.first);
		}
		//统一删除词频已经为0的数字
		for (int i = 0; i < deleteIt.size(); i++)
			hashMap.erase(deleteIt[i]);
	}
};