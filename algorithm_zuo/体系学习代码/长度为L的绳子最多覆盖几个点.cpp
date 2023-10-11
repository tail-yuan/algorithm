#include<iostream>
#include<vector>
using namespace std;
// 贪心:没有必要让绳子起点和终点不在点上,选择一边作为边界
//法1. 以某一个点为绳子右侧终点向前,找到left的右边的最近的arr[i]中的位置,下标相减即为ret.
// O(N*logN)
//法2: 窗口不回退思想,选择index作为左边界,找到以index左边界开始向右能拓展到哪个点,确定窗口内节点数即可.
// O(N)
class CordCoverMaxPoint
{
public:
	//在arr[0..R]范围上，找满足>=value的最左位置
	//二分查找 O(logN)
	int nearestIndex(vector<int>& arr, int R, int val)
	{
		int L = 0;
		int index = R;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (arr[mid] >= val)
			{
				index = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		return index;
	}
	int maxPoint(vector<int>& arr, int L)
	{
		int res = 1;
		//O(N)
		for (int i = 0; i < arr.size(); i++)
		{
			int nearest = nearestIndex(arr,i,arr[i]-L);
			res = max(res,i-nearest+1);
		}
		return res;
	}

};