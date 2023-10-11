//题干:
//给定一个数组arr，代表每个人的能力值。
//再给定一个非负数k如果两个人能力差值正好为k，
//那么可以凑在一起比赛一局比赛只有两个人返回最多可以同时有多少场比赛
//题解:
//暴力的方式是找到所有的数字全排列,然后分别验证每一种排列,相邻两个数字能否完成K,ans++.
// 
//贪心:先紧赶着关心小的值,先满足小的值.寻找队手一定在右侧
// 使用同向双指针,也就是滑动窗口.就需要利用单调性,所以需要先排序一下.
//left right;如果[right]-[left]>k,left++;如果[right]-[left]<k,right++
//如果[right]-[left]==0,记录比赛次数,left++,right++.为了避免出现选手重叠,right位置count++之后
//标记一下,代表已经选过了,避免left再来将他选中.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int maxPairNumber(vector<int>& arr, int k)
	{
		if (k < 0 || arr.size() < 2)
			return 0;
		sort(arr.begin(), arr.end());
		int left = 0, right = 0;
		int n = arr.size();
		int ans = 0;
		vector<bool>used(n,false);
		while (right < n)
		{
			if (used[left])//left到达的点已经用过了
				left++;
			else if (left >= right)//当出现left==right代表只有一个人,没法安排比赛.或者窗口不存在
				right++;
			else
			{
				if (arr[right] - arr[left] == k)
				{
					ans++;
					used[right] = true;
					left++, right++;
				}
				else if (arr[right] - arr[left] < k) right++;
				else if (arr[right] - arr[left] > k) left++;
			}
		}
		return ans;
	}

	//全排列显示
	int maxPairNum(vector<int>& arr, int k)
	{
		if (k < 0 || arr.size() < 2)return 0;
		return process(arr,0,k);
	}
	int process(vector<int>& arr, int index, int k)
	{
		int ans = 0;
		if (index == arr.size())
		{
			//排列完成
			for (int i = 1; i < arr.size(); i += 2)
			{
				if (arr[i] - arr[i - 1] == k)
					ans++;
			}
		}
		else
		{
			for (int r = index; r < arr.size(); r++)
			{
				swap(arr[r], arr[index]);
				ans = max(ans, process(arr, index + 1, k));
				swap(arr[r], arr[index]);
			}
		}
		return ans;
	}
};