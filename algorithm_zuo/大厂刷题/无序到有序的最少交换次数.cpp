//题干:
//无序数组长度为n,数字都在范围[0,n-1]上出现,返回这个无序数组变为有序数组的最小交换次数
//下标循环怼: 
//val:  [4,2,3,1,0]
//index: 0 1 2 3 4
//[0]=4,cur=4, cur应该到达[4]位置,将[4]=0弹出,cur=0应该到0位置,形成闭环,结束
//[1]=2,cur=2应该到达[2]位置,将[2]=3弹出,cur=3,应该到达[3]位置,将[3]=1弹出
//cur=1,应该到达[1]位置,形成闭环,结束
//那么如果这一条环路上有k个节点,那么应该交换k-1次
//所有的环之间一定是没有交集的,如果有a个环,那么最少交换次数就是n-a
//如果[i]位置不是i,就在这个位置开始下标循环怼
//为了将上述方式方便实现,在i位置和[i]位置直接交换,重复进行,直到[i]==i.
//将一个环上的移动操作拆分为都从i位置操作.
//val:  [4,2,3,1,0]
//index: 0 1 2 3 4
//[0]=4,直接swap(arr[0],arr[4]),让4到[4]位置,发现[0]==0,结束,下一个位置
//[1]=2,直接swap(arr[1],arr[2]),让2到[2]位置,发现[1]==3,
//直接swap(arr[1],arr[3]),让3到[3]位置,发现[1]==1,结束,下一个位置,
//发现[i]==i,end;直接统计交换次数即可

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	int minSwap(vector<int>& arr)
	{
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			while (i != arr[i])
			{
				swap(arr[i], arr[arr[i]]);
				ans++;
			}
		}
		return ans;
	}
public:
	int minSwap_1(vector<int>& arr)
	{
		return process(arr, 0);
	}
	int process(vector<int>& arr, int times)
	{
		int n = arr.size();
		//如果已经有序,说明交换成功,返回times
		bool isSorted = true;
		for(int i=0;i<n-1;i++)
		{
			if (arr[i] > arr[i - 1])
			{
				isSorted = false;
				break;
			}
		}
		if (isSorted)
			return times;
		//此时数组时无序的
		if (times >= n - 1)
			return INT_MAX;
		int ans = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				swap(arr[i], arr[j]);
				ans = min(ans, process(arr, times + 1));
				swap(arr[i], arr[j]);//恢复现场,尝试下一个分支
			}
		}
		return ans;
	}
public:
	//将数据做离散化: 
	//[45,81,6] -> [1,2,0],转化成有序数组对应位置下标
	void func(vector<int>& arr)
	{
		vector<int>copy(arr);
		sort(copy.begin(), copy.end());
		unordered_map<int, int> hashMap;//<key,newIndex>
		for (int i = 0; i < arr.size(); i++)
			hashMap[copy[i]] = i;
		//改arr
		for (int i = 0; i < arr.size(); i++)
			arr[i] = hashMap[arr[i]];
	}

};
//尝试对数器,不要求时间复杂度,只要保证完全正确,那么就暴力交换两个数,开一个分支,
//暴力尝试所有分支,肯定有一个是最小交换次数,找到并返回
//所有位置回到自己位置,不做任何优化的交换,n-1次交换必然能够拿下
//所以尝试暴力方式进行交换时,如果这个分支已经交换次数>n-1了,说明这个分支时错的

