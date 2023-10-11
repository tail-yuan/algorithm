#include"head.hpp"
//����Ļ���
//һ:��ʹ��ħ������,ȫ������,ֱ���ۼ�
//��:ʹ��һ��ħ�����Ტ���Ǳ���ʹ��
		//1. ��i��λ�õ����ֲ��ھ���������,dp[i]=dp[i-1]+arr[i]
		//2. ��i��λ�õ������ھ���������,[...,i]��i����������,֪���ҵ����ǰ׺��ʱֹͣ.
				//����һֱ��ǰ��������,���Ǹ���,���� maxSum=max(sum,0);���ǰ׺����С��0
//��:ʹ������
//[0,i-1]���ǰ׺�ۼӺ�,[i,n-1]Ҳ�������׺��,�����������,5-5,right[4]:��4-5����,dp[3,5]��3��5����...
//[0,i-1][i,n-1]�ֱ���һ��,Ȼ����������ۼӺ����
//[0,1] [2,n-1]
//[0,2] [3,n-1]
class Solution
{
public:
	int zuo(vector<int>& arr)
	{
		int n = arr.size();
		//���һ
		int p1 = 0;
		for (int num : arr)
		{
			p1 += num;
		}
		//�����
		vector<int> dp(n);
		//dp[0]=0 ǰһ�����������þ���֮�����0
		int sum = arr[0];
		//int maxSum = sum;
		int maxSum = max(sum,0);
		for (int i = 1; i < n; i++)
		{
			//������
			int z1 = dp[i - 1] + arr[i];
			//����
			int z2 = maxSum;
			dp[i] = max(z1,z2);

			sum += arr[i];
			maxSum = max(maxSum,sum);
		}
		int p2 = dp[n - 1];
		//ʹ������
	}
	//O(N)�����ı�����
	int MagicScrollProbelm(vector<int>& arr)
	{
		int n = arr.size();
		//1. 
		int p1 = 0;
		for (auto num : arr)
		{
			p1 += num;
		}
		//2. 
		vector<int>left(n);
		int sum = arr[0];
		int maxSum = max(sum,0);
		for (int i = 1; i < n; i++)
		{
			//1. 
			int z1= left[i - 1] + arr[i];
			//2. 
			int z2 = maxSum;
			left[i] = max(z1, z2);

			sum += arr[i];
			maxSum = max(maxSum,sum);
		}
		int p2 = left[n - 1];
		//3. 
		vector<int>right(n);
		sum = arr[n - 1];
		maxSum = max(sum, 0);
		for (int i = n-2; i>=0; i--)
		{
			int z1 = right[i + 1] + arr[i];
			int z2 = maxSum;
			right[i] = max(z1, z2);

			sum += arr[i];
			maxSum = max(maxSum, sum);
		}
		int p3 = INT_MIN;
		for (int i = 1; i < n; i++)
		{
			p3 = max(p3,left[i-1]+right[i]);
		}

		return max(p1,max(p2,p3));
	}
};