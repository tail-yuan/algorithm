#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//数组中任选两个数字,判断乘积是否只有一个非零数字
//返回可以选择的数字组合的对数
class Solution
{
public:
	//判断一个数是否只有一个非零数字
	bool isTrue(int num)
	{
		string tmp = to_string(num);
		int count = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] != '0')
				count++;
		}
		return count == 1 ? true : false;
	}
	int perfectPair1(vector<int>& arr)
	{
		int n = arr.size();
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int x = arr[i], y = arr[j];
				if (isTrue(x * y))
				{
					count++;
				}
			}
		}
		return count;
	}
};
