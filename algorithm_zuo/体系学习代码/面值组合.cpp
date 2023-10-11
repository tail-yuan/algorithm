#include<iostream>
#include<vector>
using namespace std;
//��������ʱ
//1. ���ɱ����ά��,��þ���һ��int����,0ά����
//2. ��������������
class CoinsWays
{
public:
	//��������ֵǮȷ��,������������ ,���ж�������ϵķ�ʽ�չ�aim
	int ways(vector<int>&arr,int aim)
	{
		return process(arr, 0,aim);
	}
	int process(vector<int>& arr, int index, int rest)
	{
		if (index == arr.size())
			return rest == 0 ? 1 : 0;
		int ways = 0;
		//���ݹ����ö�ٵ����ʱ
		for (int count = 0; count * arr[index] <= rest; count++)
			ways += process(arr,index+1,rest-count*arr[index]);
		return ways;
	}
	//1. index [0,N] rest [0,aim]
	//2. dp[0][aim]
	//3. dp[N][1...]=0 dp[N][0]=1
	//4. dp[index][rest]=dp[index+1/*��һ�е�*/][rest-count*arr[index]],count=0,1,2,3
	//5. �������ݹ��������ϵֱ�ӳ�����,Ȼ��ֱ�Ӱѵݹ��Ϊ����ȡֵ
	int ways(vector<int>& arr, int aim)
	{
		int N = arr.size();
		vector<vector<int>> dp(N+1,vector<int>(aim+1));
		dp[N][0] = 1;
		for (int i = 0; i <= aim; i++)
			dp[N][i] = 0;
		for (int index = N - 1; index >=0; index--)
		{
			//��Ϊͬһ�еĲ�ͬ��֮���ǲ�Ӱ���
			for (int rest = 0; rest <= aim; rest++)
			{
				int ways = 0;
				//���ݹ����ö�ٵ����ʱ
				for (int count = 0; count * arr[index] <= rest; count++)
					ways += dp[index + 1][rest - count * arr[index]];
				dp[index][rest] = ways;
			}
		}
		return dp[0][aim];
	}
	//O(N*aim)�ĸ���,ÿ�����Ӷ���ö�ٵ����,���aim��,������O(N*aim*aim)
	//[rest-count*arr[index]],count=0,1,2,3 ��index��,��dp[index][rest]��Ҫ����һ�е�,
	// a:[index+1][rest+0*x] b:[rest-1*x]  c:[rest-2*x] ...�⼸������������ֵ,��� =a+b+c+...
	// ��indexͬһ��,rest-xλ������ʱ��,�õ���b +c +... �ֱ�����һ��,[index][rest-1*x]=b+c+...
	// ��ô�Ϳ��԰���������Ż�,[index][rest]=[index][rest-1*x](ǰ��λ��) + a
	//ֻҪ��֤�������ҵ�˳��,�����������[index][rest-1*x],���ɱ�֤[index][rest]
	//�������˺ܶ���Ч��,�ظ���ö�����
	int ways(vector<int>& arr, int aim)
	{
		int N = arr.size();
		vector<vector<int>> dp(N + 1, vector<int>(aim + 1));
		dp[N][0] = 1;
		for (int i = 0; i <= aim; i++)
			dp[N][i] = 0;
		for (int index = N - 1; index >= 0; index--)
		{
			//��Ϊͬһ�еĲ�ͬ��֮���ǲ�Ӱ���
			for (int rest = 0; rest <= aim; rest++)
			{
				dp[index][rest] = dp[index+1][rest];
				if (rest - arr[index] >= 0)
					dp[index][rest] += dp[index][rest - arr[index]];
			}
		}
		return dp[0][aim];
	}
	//б���Ż��汾(��ͼ�۲�����Ĺ����Ż�)
	//���ٽ���Ϊ�ܷ��Ż�ö����Ϊ
};