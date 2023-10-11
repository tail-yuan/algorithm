//���:
//����˾��N*2�ˣ��������ĻὫ����˾��ƽ�ָ�A��B��������
// ��i��˾��ȥA�ɵ�����Ϊincomeil[0]
// ��i��˾��ȥB�ɵ�����Ϊincome[i][1]
//�������е��ȷ�������ʹ����˾����������ߵķ������Ƕ���Ǯ.������������Ƕ���
//���:
//˾������������ż��������ɷ���,
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=5&vd_source=cc945ef88574fe2db5e814c0c265a4c7
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int n;
public:
	int maxVal(vector<vector<int>>& arr)
	{
		n = arr.size();
		if (n <= 1 || n % 2 != 0)
			return 0;
		int m = n / 2;
		return process(arr,0,m);
	}
	//process ,��������һ��index����process�ܹ���index֮�������˾��������ϲ��ұ�֤AB����������ͬ
	//A����ʣ��rest������
	//����ֵ�Ƿ������֮��������������
	int process(vector<vector<int>>& arr,int index,int rest)
	{
		if (index == n)
			return 0;
		//����˾��,1. ֻ��ȥA 2. ֻ��ȥB 3. AB���пռ�,�漰��ѡ��
		if (n - index == rest)
			return arr[index][0] + process(arr,index+1,rest-1);
		if (rest == 0)//A �����Ѿ�û�п�λ����
			return arr[index][1] + process(arr, index + 1, rest);
		int p1= arr[index][0] + process(arr, index + 1, rest - 1);
		int p2= arr[index][1] + process(arr, index + 1, rest);
		return max(p1, p2);
	}
	//1. ���ռ�,index[0,N] rest[0,n/2] dp[N][N/2],��Ϊ����dp[0][n/2],�࿪һ��һ��,���þ���
	//2. ���˳��,��Ϊ������index+1,rest-1���Դ�������,��������
	int maxVal2(vector<vector<int>>& arr)
	{
		n = arr.size();
		int m = n / 2;
		vector<vector<int>>dp(n+1, vector<int>(m+1));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j <= m; j++)
			{
				if (n - i == j)
					dp[i][j] = arr[i][0] + dp[i + 1][j - 1];
				else if (j == 0)
					dp[i][j] = arr[i][1] + dp[i + 1][j];
				else
				{
					int p1 = arr[i][0] + dp[i + 1][j - 1];
					int p2 = arr[i][1] + dp[i + 1][j];
					dp[i][j] = max(p1, p2);
				}
			}
		}
		return dp[0][m];
	}
};

//Ա������AB������С����
//https://leetcode.cn/problems/two-city-scheduling/submissions/
class Solution2
{
	int n;
public:
	//dfs�汾:
	//�ظ�������: ����indexλ�õ�����Ҫ����ȥA����ȥB,ѡ����С�ķ��÷��ظ���һ��,��Ҫ���ǵ���A������ʣ��λ��rest
	int twoCitySchedCost1(vector<vector<int>>& arr)
	{
		n = arr.size();
		int m = n / 2;
		return dfs(arr, 0, m);
	}
	int dfs(vector<vector<int>>& arr, int index, int rest)
	{
		if (index == n)
			return 0;
		//����Ա�������� 1. A �޿�λֻ��ȥB 2. ֻ��ȥA 3. AB֮��ѡ����С����
		if (rest == 0)
			return arr[index][1] + dfs(arr, index + 1, rest);
		if (n - index == rest)
			return arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p1 = arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p2 = arr[index][1] + dfs(arr, index + 1, rest);
		return min(p1, p2);
	}
	//��Ϊdp index[0,n] rest[0,m]
	//���ʱ�ϸ�������index+1,rrest-1�������˳���Ǵ�������,��������
	int twoCitySchedCost(vector<vector<int>>& arr)
	{
		n = arr.size();
		int m = n / 2;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j <= m; j++)
			{
				if (j == 0)
					dp[i][j] = arr[i][1] + dp[i + 1][j];
				else if (n - i == j)
					dp[i][j] = arr[i][0] + dp[i + 1][j - 1];
				else
				{
					int p1 = arr[i][1] + dp[i + 1][j];
					int p2 = arr[i][0] + dp[i + 1][j - 1];
					dp[i][j] = min(p1, p2);
				}
			}
		}
		return dp[0][m];
	}
};