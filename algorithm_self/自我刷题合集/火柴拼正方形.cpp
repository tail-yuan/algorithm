#include"head.hpp"
//先解决第一条边,如果成功再解决下一条,最后都成功解决就是true
//https://leetcode.cn/problems/matchsticks-to-square/submissions/
class Solution
{
public:
	//status使用32位来表示哪一根火柴用没用,cur表示当前已经解决了多少,len是固定每一根应该多长
	//edges代表还需要几条边需要搞定
	//可变参数:cur,status,edges
	//时间上,只要status确定,代表哪几个火柴已经用了,就可以确定还剩多少边要处理edges以及某一边上已经完成多少
	//使用一维数组dp动归,status最多15根,也就是2^15个状态 00...->111...
	bool f(vector<int>& arr, int status, long cur, long len, int edges,vector<int>&dp)
	{
		if (edges == 0)
		{
			//确定所有的火柴是否用光了
			return status == ((1 << arr.size()) - 1) ? true : false;
		}
		//dp[status]=0 1 -1
		// ans == true	dp[status] = 1
		// ans == false dp[status] = -1
		if (dp[status] != 0) {
			return dp[status] == 1;
		}
		//还没都搞定
		//arr中,还没有尝试的火柴,当前边都试一遍,只要能走通true
		bool ans = false;
		for (int i = 0; i < arr.size(); i++)
		{
			if ((status & (1 << i)) == 0)
			{
				//已经解决的+当前筷子长度>len,说明不可用
				if (cur + arr[i] > len)
				{
					continue;
				}
				else if (cur + arr[i] < len)//可用,还有空间继续
				{
					ans = f(arr,status|(1<<i),cur+arr[i],len,edges,dp);
				}
				else //正好=len,该找下一条边了
				{
					ans = f(arr, status |(1 << i), 0, len, edges - 1,dp);
				}
			}
			if (ans)//任何一条总路径走通了即可,之后就可以不用找了(降低时间)
			{
				break;
			}
		}
		//通过status位图代表用了哪几根火柴代表哪一种路径成功ans(break出来的)比如0000 0000 1111 0011这几个火成功记录状态=1
		//循环结束status=false,
		// ans == true dp[status] = 1
		// ans == false dp[status] = -1
		dp[status] = ans ? 1 : -1;
		return ans;
	}
	bool makesquare(vector<int>& matchsticks) {
		long sum = 0;
		for (auto num : matchsticks)
		{
			sum += num;
		}
		if (sum % 4 != 0)
			return false;

		long len = sum / 4;
		//
		vector<int> dp(1<<matchsticks.size());
		int status = 0;
		return f(matchsticks, status, 0, len, 4,dp);
	}
}; 