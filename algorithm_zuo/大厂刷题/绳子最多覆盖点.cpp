#include<iostream>
#include<vector>
using namespace std;

//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=2&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//ʹ��˫ָ��,����������֮��,��leftΪ��߽�,rightһֱ������,ֱ��right-left>L��¼��ʱ
//���ǵĵ�ĸ���.Ȼ��left++,ͬʱright�������++.
//˫ָ�붼��ǰ���󲻻���,������O(N)
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