#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//һ��ʯͷ,��ɫ,��ɫ,��ɫ,
//���ֻ�к�ɫʯͷ����ɫʯͷ��Ŀ��ͬʱ,��������ʯͷ������ɫ,���ܹ���
//ֻ�ܽ���ɫȾΪ����������ɫ,����С�����Ƕ���
//��������[0,x,y],0�������ʯͷ��ɫ,xΪȾɫΪ��ɫ�Ĵ����Ƕ���,yΪȾΪ��ɫ�Ĵ���
//[1,.,.]1�����Ǻ�ɫ,2��������ɫ,���Ҳ��ܸ���ɫ�����Ժ�������X������

//̰�ĵ�˼��
//����������ɫʯͷ��ת��Ϊ��ɫ,�ܴ�����cost,
//����һ�������֪��Ӧ�÷���K����ɫʯͷ��Ⱦ����ɫ
//��ô����ɫʯͷ��ѡ��K��,�Ļ�����֮��ʹ��cost�½����ļ���,ȾΪ��ɫ����
class Solution
{
public:
	struct comp
	{
		bool operator()(const vector<int>& x, const vector<int>& y)
		{
			if (x[0] == 0 && y[0] == 0)
			{
				if ((x[1] - x[2]) < (y[1] - y[2]))//��ת������С������ǰ��,�����ȫ��A֮����ܴ��ۼ���ת��֮��Ĵ��ۼ���
					return true;
				else
					return false;
			}
			//������һ��Ϊ����ɫʱ,��ô������������ν
			return false;
		}
	};
	int magicStones(vector<vector<int>>& arr)
	{
		int n = arr.size();
		if (n % 2 != 0)return -1;
		sort(arr.begin(), arr.end(), comp());
		int zero = 0, red = 0, blue = 0;
		int cost = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] == 0)
			{
				zero++;
				cost += arr[i][1];
			}
			else if (arr[i][0] == 1)red++;
			else if (arr[i][0] == 2)blue++;
		}
		//������һ��ʯͷ��Ŀ����һ��,�����ø�����ɫ,�϶��治��
		if (red > (n / 2) || blue > (n / 2))
			return -1;
		blue = zero - ((n / 2) - red);
		for (int i = 0; i < blue; i++)
			cost += arr[i][2] - arr[i][1];//�Ӻ쵽���Ĵ��۱仯����
		return cost;
	}
};

//������˾�����ط�����������������˵��С����
//[0,x,y]0��˾�����䵽A��������x,���䵽B��������y
//�ʽ�����˾�����ֵ����ص���������Ƕ���?
// A��������,ʣ�µĶ�ȥB��Ҳ�ͷֺ�����?����ֻרע��һ��Ŀ�ĵؼ���
// dfs����A�ػ�ʣ��rest��λ��ʱ,index��˾��ѡ��֮���õ��������.
//dfs:����index�±�˾��ʱ,������ѡ��,ȥAȥB�ֱ����Ӱ��,
//dfs����ֵ����indexȥA����B֮������õ�����,ѡ��������ļ���
// 
//	//index: [1~n],rest[1~m],�࿪һ�ж࿪һ�� dp[n+1][m+1],����ԭʼ����ʱע���±�-1
	//����dfs��ʼ�����һ��,��һ��:dp[n][j]=0,dp[i][0]=arr[i-1][1]+dp[i+1][0]
	//dp[i][j]=min(arr[i-1][0]+ dp[i+1][j-1],arr[i-1][1]+ dp[i+1][j])
	//���˳��: ������i+1,���Դ���������д,��������
	//����ֵ: dp[0][m]
//ʹ��̰�ĵķ�ʽ:
class Solution
{
	int n1;
public:

	int twoCitySchedCost(vector<vector<int>>& arr)
	{
		int N = arr.size();
		vector<int>nums(N);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			nums[i] = arr[i][1] - arr[i][0];//��¼i��˾����Aת��ΪBʹ���ܴ��۱仯[1]-[0]��ô��
			sum += arr[i][0];//��ȫȥA��
		}
		sort(nums.begin(), nums.end());//ѡ��ǰM��,���ܴ��ۼ���
		int M = N / 2;
		for (int i = 0;i<M;i++)
		{
			sum += nums[i];
		}
		return sum;
	}
public:

	int twoCitySchedCost2(vector<vector<int>>& arr)
	{
		int n = arr.size(), m = n / 2;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
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
public:

	int twoCitySchedCost1(vector<vector<int>>& costs)
	{
		n1 = costs.size();
		int _n = n1 / 2;
		return dfs(costs, 0, _n);
	}
	int dfs(vector<vector<int>>& arr, int index, int rest)
	{
		if (index == n1)
			return 0;
		//A ��ʣ��λ��,��ȥB��
		if (rest == 0)
			return arr[index][1] + dfs(arr, index + 1, rest);
		//Aʣ��λ������,����A��
		if (n1 - index == rest)
			return arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p1 = arr[index][0] + dfs(arr, index + 1, rest - 1);
		int p2 = arr[index][1] + dfs(arr, index + 1, rest);
		return min(p1, p2);
	}
};