#include<iostream>
#include<vector>
using namespace std;

class RobotWalk
{
public:
	int robotWalk(int N, int S, int E, int K)
	{
		return f(N, S, K, E);
	}
	int f(int N, int cur, int rest, int E)
	{
		if (rest == 0)//base case �������ߵ�ʱ�򿴿���û���յ�,���˾���һ�ַ���
			return cur == E ? 1 : 0;
		//�����ұ߽�ʱֻ����һ��������
		if (cur == 1)
			return f(N, cur + 1, rest - 1, E);
		if (cur == N)
			return f(N,cur-1,rest-1,E);
		//����λ��,��������+�ҷ���ķ���
		return f(N, cur + 1, rest - 1, E) + f(N,cur-1,rest-1,E);
	}
	//�ɱ����ֻ�� rest cur, ��ʼ��״̬��f(K,S),ֻҪrest curȷ��,��ô���ķ���ֵһ��ȷ��
	// f(k,s)=f(k-1,s+1) or f(k-1,s-1) 
	// ���� k=4,s=2 f(4,2)=f(3,1)+f(3,3)
	// f(3,1)=f(2,2) f(3,3)=f(2,2)+f(2,4)
	// f(2,2)=f(2,1) ,���Զ������ṹ���f(4,2)ʱ,����f(2,2)���ظ����,
	//�����ݹ�Ĺ����л�����ظ�����һ��ֵ�����,�����ĳһ��װ̬��ֵ��¼,�´���Ҫ����ʱ��ֱ�Ӳ����
	//�ռ任ʱ��,
	//rest K...1 cur 1...N
	//���ռ�ֻҪ��������
public:
	int robotWalk2(int N, int S, int E, int K)
	{
		vector<vector<int>>dp(K+1,vector<int>(N+1,-1));//-1�������λ��û�м����

		return f2(N, S, K, E,dp);
	}
	int f2(int N, int cur, int rest, int E, vector<vector<int>>&dp)
	{
		//�����������ֵ��ֱ�ӷ���
		if (dp[rest][cur] != -1)
			return dp[rest][cur];

		if (rest == 0)//base case �������ߵ�ʱ�򿴿���û���յ�,���˾���һ�ַ���
		{
			dp[rest][cur]= cur == E ? 1 : 0;//1
			return dp[rest][cur];
		}
		if (cur == 1)
			dp[rest][cur] = f(N, cur + 1, rest - 1, E);
		else if (cur == N)
			dp[rest][cur] = f(N, cur - 1, rest - 1, E);
		else
			dp[rest][cur] = f(N, cur + 1, rest - 1, E) + f(N, cur - 1, rest - 1, E);
		return dp[rest][cur];
	}
	//�����ݹ���K��Ķ�����,O(2^K)
	//���仯����O(K*N)
	//ÿһ������ֻ����һ��,��һ��ֱ�Ӳ�ѯÿ��λ�õ���O(1),��Ĺ�ģ��K*N
	//������ṹ,����λ������->�ϸ��ṹ
	//��:cur(1~N) ��:rest(0~K) return dp[S][K] �����ĸ�λ�ó���rest=0ʱ
	int dpWay(int N, int K, int S, int E)
	{
		vector<vector<int>> dp(K+1,vector<int>(N+1));
		//from 1
		dp[0][E] = 1;
		for (int rest = 1; rest <= K; rest++)
		{
			for (int cur = 1; cur <= N; cur++)
			{
				if (cur == 1)
					dp[rest][cur] = dp[rest - 1][cur + 1];
				else if (cur == N)
					dp[rest][cur] = dp[rest - 1][cur - 1];
				else
					dp[rest][cur] = dp[rest - 1][cur + 1] + dp[rest - 1][cur - 1];
			}
		}
		return dp[S][K];
	}
};