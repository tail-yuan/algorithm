//https://leetcode.cn/problems/longest-increasing-subsequence/submissions/
//dp˼��
//��iλ��Ϊ��β,dp[i]������iλ��Ϊ��β�������������г�������Ǹ��ĳ���
//[0,i-1]�������ҵ�һ��jλ��,[j]<[i],��ʱ��[i]λ��������[j]�ĺ��漴��
//dp[i]=dp[j]+1,����j��ֵ���ܴ��ڶ��,��������Ҫ��������Ǹ���¼����,
//dp[i]=max(dp[i],dp[j]+1)
//����ֵ: dp[i]��¼������iΪ��β��,�������ֵ������������Ϊ��β��,����Ҫdp�������ֵ
//��ʼ��: ��n���ռ�,ÿ��ֵ����ÿ�������еĳ���������1
//���˳��,����
//dfs˼��+memo�Ż�
// ��indexλ��Ϊ��ͷ
//������: ÿ����indexλ��,����Ҫ��index֮���������ѡ����Լ�������path�ַ���,������ȥ
//��Ϊֻ��Ҫ���㳤��,����ƴ��path,ֱ��+1����
//ÿ����indexΪ��ͷ�����кܶ�������в���,����Ҫ�������ֵ.
//����: index����n����,˵��ö������,����path�Ĵ�С
//����: �ָ��ֳ�,path��Ҫ�ָ�,��ֵ��������ջ֡���Զ��㶨
//������indexΪ��ͷ�������д��ڴ����ظ�����,���Կ����Ż�Ϊ���仯����memo
//�ڽ����ʱ���ж��Ƿ�����,�ڷ���ֵ��ʱ���ȼ�¼һ���ٷ���
#include<iostream>
#include<vector>
#include<string>
using namespace std; 
class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		int n = nums.size();
		vector<int>dp(n, 1);
		int ret = 1;//����������ʵ��ʼ��Ϊ1
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			ret = max(ret, dp[i]);
		}
		return ret;
	}
private:
	vector<int>memo;
	int n;
public:
	//dfs˼��
	int lengthOfLIS2(vector<int>& nums)
	{
		n = nums.size();
		int ret = 1;
		memo = vector<int>(n, 0);
		for (int i = 0; i < n; i++)
		{
			ret = max(ret, dfs(nums, i));
		}
		return ret;
	}
	int dfs(vector<int>& nums, int index)
	{
		if (memo[index] != 0) return memo[index];
		int ret = 1;
		for (int i = index+1; i < n; i++)
		{
			if (nums[i] > nums[index])
				ret=max(ret,dfs(nums, i)+1);
		}
		memo[index] = ret;
		return memo[index];
	}
public:
	//��dfs-memo�Ķ�����dp
	//����j�ĸ���,������i,��i��j�����,����Ӧ�ôӺ���ǰ��д��
	int lengthOfLIS3(vector<int>& nums)
	{
		int m = nums.size();
		vector<int>dp(m, 1);
		int ret = 1;
		for (int j = m-1; j>=0; j--)
		{
			for (int i = j + 1; i < m; i++)
			{
				if (nums[i] > nums[j])
					dp[j] = max(dp[j], dp[i] + 1);
			}
			ret = max(ret, dp[j]);
		}
		return ret;
	}
};
int main()
{
	return 0;
}