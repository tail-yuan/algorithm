
//����������: dp[i]���������iλ��Ϊ��β,�γɵ�����ۼӺ�
//�������һ�β���,
//����ѡ��,һ�����Լ�����,һ���Ǻ�i-1λ���ۼ���һ��,
//dp[i]=max(nums[i],dp[i-1]+nums[i])
//i-1�漰��Խ��,�࿪һ���ռ�,1. ����ԭ����ʱ�±�任,2. ��ͳ�ʼ���࿪�Ŀռ�ʹ�ò�Ӱ���������
//����dp[0],dp[0]=0ʱ��Ӱ��dp[1]=nums[0]
//���˳��:  ������

//�ռ��Ż�:��Ϊiλ����dp��ʱֻ��Ҫ����ǰһ��λ��,��ô���Բ��ÿ�dp����ռ�,����ֻ��һ�������洢����
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int maxmaxSubArray(vector<int >& arr)
	{
		int n = arr.size();
		vector<int>dp(n + 1);
		int ret = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = max(arr[i - 1], dp[i - 1] + arr[i - 1]);
			ret = max(ret, dp[i]);
		}
		return ret;
	}
	int maxmaxSubArray2(vector<int >& arr)
	{
		int n = arr.size();
		int prev = 0;
		int ret = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int num = max(arr[i], arr[i] + prev);
			ret = max(ret, num);
			prev = num;
		}
		return ret;
	}
};