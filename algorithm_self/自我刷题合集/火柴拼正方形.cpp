#include"head.hpp"
//�Ƚ����һ����,����ɹ��ٽ����һ��,��󶼳ɹ��������true
//https://leetcode.cn/problems/matchsticks-to-square/submissions/
class Solution
{
public:
	//statusʹ��32λ����ʾ��һ�������û��,cur��ʾ��ǰ�Ѿ�����˶���,len�ǹ̶�ÿһ��Ӧ�ö೤
	//edges������Ҫ��������Ҫ�㶨
	//�ɱ����:cur,status,edges
	//ʱ����,ֻҪstatusȷ��,�����ļ�������Ѿ�����,�Ϳ���ȷ����ʣ���ٱ�Ҫ����edges�Լ�ĳһ�����Ѿ���ɶ���
	//ʹ��һά����dp����,status���15��,Ҳ����2^15��״̬ 00...->111...
	bool f(vector<int>& arr, int status, long cur, long len, int edges,vector<int>&dp)
	{
		if (edges == 0)
		{
			//ȷ�����еĻ���Ƿ��ù���
			return status == ((1 << arr.size()) - 1) ? true : false;
		}
		//dp[status]=0 1 -1
		// ans == true	dp[status] = 1
		// ans == false dp[status] = -1
		if (dp[status] != 0) {
			return dp[status] == 1;
		}
		//��û���㶨
		//arr��,��û�г��ԵĻ��,��ǰ�߶���һ��,ֻҪ����ͨtrue
		bool ans = false;
		for (int i = 0; i < arr.size(); i++)
		{
			if ((status & (1 << i)) == 0)
			{
				//�Ѿ������+��ǰ���ӳ���>len,˵��������
				if (cur + arr[i] > len)
				{
					continue;
				}
				else if (cur + arr[i] < len)//����,���пռ����
				{
					ans = f(arr,status|(1<<i),cur+arr[i],len,edges,dp);
				}
				else //����=len,������һ������
				{
					ans = f(arr, status |(1 << i), 0, len, edges - 1,dp);
				}
			}
			if (ans)//�κ�һ����·����ͨ�˼���,֮��Ϳ��Բ�������(����ʱ��)
			{
				break;
			}
		}
		//ͨ��statusλͼ���������ļ�����������һ��·���ɹ�ans(break������)����0000 0000 1111 0011�⼸����ɹ���¼״̬=1
		//ѭ������status=false,
		// ans == true dp[status] = 1
		// ans == false dp[status] = -1
		dp[status] = ans ? 1 : -1;
		return ans;
	}
	bool makesquare(vector<int>& matchsticks) {
		long sum = 0;
		for (auto num : matchsticks)
		{
			sum += num;
		}
		if (sum % 4 != 0)
			return false;

		long len = sum / 4;
		//
		vector<int> dp(1<<matchsticks.size());
		int status = 0;
		return f(matchsticks, status, 0, len, 4,dp);
	}
}; 