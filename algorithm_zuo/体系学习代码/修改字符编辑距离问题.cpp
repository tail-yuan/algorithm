//���������ַ���str1��str2���ٸ�����������ic��dc��rc���ֱ������롢ɾ
//�����滻һ���ַ��Ĵ��ۣ����ؽ�str1�༭��str2����С���ۡ�
//��������
//str1 = "abc"��str2 = "adc"��ic = 5��dc = 3��rc = 2
//��"abc"�༭��"adc"����'b'�滻��'d'�Ǵ�����С�ģ����Է���2
//str1 = "abc"��str2 = "adc"��ic = 5��dc = 3��rc = 100
//��"abc"�༭��"adc"����ɾ��'b'��Ȼ�����'d'�Ǵ�����С�ģ����Է���8
//str1 = "abc"��str2 = "abc"��ic = 5��dc = 3��rc = 2
//���ñ༭�ˣ���������һ�����ַ��������Է���0

// ��str1Ϊ��,str2Ϊ�й���һ�Ŷ�ά��
// dp[i][j]�������str1[0...i-1]����str2[0...j-1]�Ĵ����Ƕ���
// dp[0][0] �մ���ɿմ��Ĵ����� 0
// ��һ��,str1��ǰi���ַ�->str2�Ŀմ��Ĵ���->i*delɾ������,ͬ���һ�о���i*add��������
// �������:
// ���1: [0...i-2,i-1] ��str1[0...i-2]����str2[0...j-1],��str1[i-1]ɾ��=> dp[i-1][j] + del
// ���2: [0...i-2,i-1] ��str1[0...i-1]����str2[0...j-2],��str1[i]λ������һ��str2[j-1]�ַ�=> dp[i][j-1] + add
// ���3: [0...i-2,i-1] ��str1[0...i-2]����str2[0...j-2],��str1[i-1]λ���滻Ϊstr2[j-1]�ַ�=> dp[i-1][j-1] + replace
// ���4: str1[i-1] ==str2[j-1]���һ���ַ����,��str[0...i-2]����str[0...j-2]Ȼ��str1[i-1]����Ϊstr2[j-1]=>dp[i-1][j-1]+copy(0)
// 34�ǻ�����ֵ�
#include<iostream>
#include<vector>
using namespace std;
class EditCost
{
public:
	int minCost(string&str1,string&str2,int delCost,int addCost,int replaceCost)
	{
		int m = str1.size(), n = str2.size();
		vector<vector<int>> dp(m,vector<int>(n));
		dp[0][0] = 0;
		for (int i = 0; i < m; i++)
			dp[i][0] = i * delCost;
		for (int i = 0; i < n; i++)
			dp[0][i] = i * addCost;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + replaceCost;
				dp[i][j] = min(dp[i][j],dp[i-1][j]+delCost);
				dp[i][j] = min(dp[i][j],dp[i][j-1]+addCost);
			}
		}
		return dp[m-1][n-1];
	}
};