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
	//[index....]��ѡ��Ӳ�ҵ�����(������ѡ��һ��Ӳ��֮��Ҫ+1)
	//-1������Ч��,��������Ч��ѡ����С��.
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
		if (p1 == -1 && p2 == -1)//Ҫ��Ҫ���Ӳ�Һ������޷�ƴ����Ҫ��target
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
	//���仯�����ķ���
	//-1��������Ч��,����ʹ��-2�����Ƿ���������
	int miCoins1(vector<int>& arr, int target)
	{
		//rest [0,target] index [0,arr.size()]
		vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-2));

		return process1(arr, target, 0,dp);
	}
	//		��	rest
	//�� index
	int process1(vector<int>& arr, int rest, int index, vector<vector<int>>&dp)
	{
		//�����������������,������Ч��
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
			if (p1 == -1 && p2 == -1)//Ҫ��Ҫ���Ӳ�Һ������޷�ƴ����Ҫ��target
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
	//�ϸ�������ķ�ʽ
	//1. �ɱ���������ͱ仯��Χ,���ٱ�
	//2. ָ��������Ҫλ��,ȷ������
	//3. ����base case��ʼ����
	//4. ȷ��������λ��
	int miCoins2(vector<int>& arr, int target)
	{
		//rest [0,target] index [0,arr.size()]
		int N = arr.size();
		vector<vector<int>>dp(N + 1, vector<int>(target + 1));
		//1->��һ�ж���0 
		for (int i = 0; i <= N; i ++)
			dp[i][0] = 0;
		//2->���һ�ж���-1
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

				if (p1 == -1 && p2 == -1)//Ҫ��Ҫ���Ӳ�Һ������޷�ƴ����Ҫ��target
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
		return dp[0][N];//Ŀ��ֵ�����Ϸ�,���Դ����һ��������
	}
};