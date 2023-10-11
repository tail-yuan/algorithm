#include<iostream>
#include<vector>
using namespace std;
//给定一个数组arr，如果通过调整可以做到arr中任意两个相邻的数字相乘是4的倍数，
//返回true；如果不能返回false

//统计个数 1. 奇数个数a 2.只含有2因子的个数b 3. 只含有4因子的倍数c
// 如果b==0, 顺序应该是 奇 4 奇 4 奇 4 , a==1时,c>=1 a>1时,c>=a-1 比如 奇4奇至少包括一个
// 如果b!=0, 顺序应该是22222224奇4奇4奇 ,因为b可能不是偶数个,最后一个应该和一个4配合
// a=0,c>=0 a=1,c>=1 a>1,c>=a
// c>=a
class nearMultiple4Times
{
public:
	bool isTrue(vector<int>&arr)
	{
		int fourTimes = 0, onlyTwoTimes = 0, odds = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 2 != 0)
				odds++;
			else
			{
				if (arr[i] % 4 == 0)
					fourTimes++;
				else
					onlyTwoTimes++;
			}
		}
		//return evenExpFourTimes == 0 ? (fourTimes + 1 >= odd) : (evenExpFourTimes >= odd);
		return onlyTwoTimes == 0 ? (fourTimes + 1 >= odds) : (fourTimes>=odds);
	}
};