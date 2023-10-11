#include<iostream>
#include<vector>
using namespace std;

class CoinsMin
{
public:
	int miCoins(vector<int>& arr, int target)
	{
		return process(arr,target,0);
	}
	//[index....]可选择硬币的数量(所以再选择一个硬币之后要+1)
	//-1代表无效解,两个都有效就选择最小的.
	int process(vector<int>& arr, int rest, int index)
	{
		if (rest < 0)
			return -1;
		if (rest == 0)
			return 0;
		if (index == arr.size())
			return -1;
		//common case
		int p1 = process(arr,rest-arr[index],index+1);
		int p2 = process(arr,rest,index+1);
		if (p1 == -1 && p2 == -1)//要不要这个硬币后续都无法拼出想要的target
			return -1;
		else
		{
			if (p1 == -1)
				return  p2;
			else if (p2 == -1)
				return 1 + p1;
			else
				return min(p1+1,p2);
		}
	}
	//记忆化搜索的方法
	//-1代表了无效解,所以使用-2代表是否计算了这个
	int miCoins1(vector<int>& arr, int target)
	{
		//rest [0,target] index [0,arr.size()]
		vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-2));

		return process1(arr, target, 0,dp);
	}
	//		列	rest
	//行 index
	int process1(vector<int>& arr, int rest, int index, vector<vector<int>>&dp)
	{
		//代表表的整体左侧区域,都是无效的
		if (rest < 0)
			return -1;

		if (dp[index][rest] != -2)
			return dp[index][rest];

		if (rest == 0)//1
			dp[index][rest] = 0;
		else if (index == arr.size())//2
			dp[index][rest] = -1;
		else
		{
			//common case
			int p1 = process1(arr, rest - arr[index], index + 1, dp);
			int p2 = process1(arr, rest, index + 1, dp);
			if (p1 == -1 && p2 == -1)//要不要这个硬币后续都无法拼出想要的target
				dp[index][rest] = -1;
			else
			{
				if (p1 == -1)
					dp[index][rest] = p2;
				else if (p2 == -1)
					dp[index][rest] = 1 + p1;
				else
					dp[index][rest] = min(p1 + 1, p2);
			}
		}
		return dp[index][rest];
	}
	//严格表依赖的方式
	//1. 可变参数个数和变化范围,开辟表
	//2. 指定最终想要位置,确定方向
	//3. 根据base case初始化表
	//4. 确定依赖的位置
	int miCoins2(vector<int>& arr, int target)
	{
		//rest [0,target] index [0,arr.size()]
		int N = arr.size();
		vector<vector<int>>dp(N + 1, vector<int>(target + 1));
		//1->第一列都是0 
		for (int i = 0; i <= N; i ++)
			dp[i][0] = 0;
		//2->最后一行都是-1
		for (int i = 1; i <= target; i++)
			dp[N][i] = -1;
		for (int index = N - 1; index >= 0; index--)
		{
			for (int rest = 1; rest <= target; rest++)
			{
				int p1 = -1;
				if(rest - arr[index]>=0)
					p1= dp[index + 1][rest - arr[index]];
				int p2 = dp[index + 1][rest];

				if (p1 == -1 && p2 == -1)//要不要这个硬币后续都无法拼出想要的target
					dp[index][rest] =- 1;
				else
				{
					if (p1 == -1)
						dp[index][rest] = p2;
					else if (p2 == -1)
						dp[index][rest] = 1 + p1;
					else
						dp[index][rest] = min(p1 + 1, p2);
				}
			}
		}
		return dp[0][N];//目标值在右上方,所以从最后一行向上找
	}
};