//来自腾讯
//给定一个数组arr，当拿走某个数a的时候，其他所有的数都 + a
//请返回最终所有数都拿走的最大分数
//比如 : [2, 3, 1]
//当拿走3时，获得3分，数组变成[5, 4]
//当拿走5时，获得5分，数组变成[9]
//当拿走9时，获得9分，数组变成口
//这是最大的拿取方式，返回总分17

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	//暴力方式: 
	int pick(vector<int>&arr)
	{
		if (arr.size() == 1)
			return arr[0];
		//尝试先拿i位置数字,得到处理后数组,并且在处理后数组中继续...
		//能够获得的最大值
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			vector<int>rest = func(arr, i);
			ans = max(ans, arr[i] + pick(rest));
		}
		return ans;
	}
	vector<int>func(vector<int>& arr, int i)
	{
		vector<int>rest(arr.size() - 1);
		int ri = 0;
		for (int j = 0; j < i; j++)
			rest[ri++] = arr[i] + arr[j];
		for (int j = i + 1; j < arr.size(); j++)
			rest[ri++] = arr[i] + arr[j];
		return rest;
	}
public:
	//对数器发现,取的顺序就是在此时数组中选取最大值累加,
	//决策树就是最大路径和
	int pick2(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = arr.size() - 1; i >= 0; i--)
		{
			ans = ans * 2 + arr[i];
		}
		return ans;
	}
};

int main()
{
	vector<int>arr = {1,3,2,4,5,6,78,8};
	Solution s;
	cout << s.pick(arr) << endl;
	cout << s.pick2(arr) << endl;
	return 0;
}