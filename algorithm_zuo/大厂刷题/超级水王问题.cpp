//ˮ������:
//����һ������,���ֵĴ��������������һ��.
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1).����ʲô������,��ϣ��ͳ�ƴ�Ƶ��������.

//���:https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=33&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//ɾ��������ͬ������,ˮ���϶���������.��������ʣ�µĲ���ˮ����,�����û��ˮ����
//1. û������ʣ��,��ˮ����
//2. ������ʣ��,������x��ȥ����һ��,ͳ�����Ĵ���.�����Ƿ���ˮ����.
//������: ���ɾ��������ͬ������
//��������: ��ѡcandidate�Լ�count
//��count=0ʱ,��ѡcandidate=0
//��ǰ�������,����޺�ѡ, candidate = cur
//����к�ѡ,if cur==candidate count++ else -- //ʵ�ֲ�ͬ���ֵ����Ĳ���
//������count==0,����������ʣ��,count!=0,candidate����ʣ�µ�����

//��չ: ����ҵ����ִ���>N/k�ε�����,�����ж��.k==2ʱ���ǻ���ˮ������
//>n/k������������k-1������,��ô�͸�һ�ű��¼��ѡ����,��Ĵ�С����k-1
//��ѡ��: <key,count> map,��map.size()<k-1ʱ,map[key]++. map.size()==kʱ,�������ݼ���map[key]--
//��count=0�����ֻ���Ҫ�ӱ����Ƴ�,��������ʣ�µ����־��Ǻ�ѡ����,��ȥͳ�ƺ�ѡ���ֵĴ�Ƶ.������֤��ʵ��.
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
	//��չ
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
		//���еĺ�ѡ���ڱ���,������֤һ����ʵ��
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
		//ͳһɾ����Ƶ�Ѿ�Ϊ0������
		for (int i = 0; i < deleteIt.size(); i++)
			hashMap.erase(deleteIt[i]);
	}
};