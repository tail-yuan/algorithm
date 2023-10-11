//https://leetcode.cn/problems/rabbits-in-forest/submissions/
//题干:
//每个人说的都是正确的,arr[i]代表i说和他衣服颜色相同的人还有arr[i]人
//那么,如果两个人衣服相同,那么必然arr[i]是相同的,假设颜色相同的在一个组里,排除自己其他人的个数应该是一样的
//那么对数组进行排序,假设arr[i]=x,那么这个颜色的组里面至少应该有x+1人,
//如果现在统计到的这个颜色的个数,即x的个数是c,那么应该有c/(x+1) 向上取整这么多组
//不够x+1个的说明没有统计到
//向上取整怎么实现? (a+(b-1))/b
//所以总人数就是((c+x)/(x+1)) * (x+1)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int minPeople(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		sort(arr.begin(), arr.end());
		int ans = 0;
		int count = 1;//数每一组的人数
		int prev = arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] != prev)//新开一组,需要对之前的组进行结算
			{
				ans += ((count + prev) / (prev + 1)) * (prev + 1);
				prev = arr[i];
				count = 1;
			}
			else
			{
				count++;
			}
		}
		//最后一组还没算呢!
		return ans + ((count + prev) / (prev + 1)) * (prev + 1);
	}
};