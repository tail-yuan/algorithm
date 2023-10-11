
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//��ÿһ��λ������Ϊβ��,���γɵ�������Ӵ�,���Բ�������������,����dp[i]=0
//dp[i]����� ) �鿴ǰһ��λ�õ�ֵdp[i-1]������i-1Ϊ��β,���γɵ����Ч�Ӵ�,�鿴dp[i-dp[i-1]]λ���Ƿ���(
// �����)dp[i]=0
// �����(,dp[i]������2+dp[i-1]
// ( ֮ǰ���ܻ���һ����Ч�Ӵ�P,����P�ĳ���,��dp[i-dp[i-1]-1-1]
//P֮ǰ���޿��ܻ���Ҫ������������Q��?����,��Ϊ��һ����P��ͳ��֮����
class maxLen
{
public:
	int maxLength(string& str)
	{
		if (str.size() == 0)
			return 0;
		vector<int>dp(str.size(),0);
		int pre = 0;
		int ans = 0;
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] == ')')
			{
				pre = i - dp[i - 1] - 1;
				if (pre >= 0 && str[pre] == '(')
					dp[i] = dp[i - 1] + 2 + (pre>0 ?dp[pre-1]:0);
			}
			ans = max(ans,dp[i]);
		}
		return ans;
	}
};