#include<iostream>
#include<vector>
using namespace std;

//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=2&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//使用双指针,将数组排序之后,以left为左边界,right一直往右走,直到right-left>L记录此时
//覆盖的点的个数.然后left++,同时right根据情况++.
//双指针都从前往后不回退,所以是O(N)
class Solution
{
public:
	int maxPoints(vector<int>& arr, int L)
	{
		int left = 0, right = 0;
		int n = arr.size();
		int ret = INT_MIN;
		while (left < n)
		{
			while (right < n && arr[right] - arr[left] <= L)
				right++;
			ret = max(ret, right - left);
			left++;
		}
		return ret;
	}
};
int main()
{
	return 0;
}