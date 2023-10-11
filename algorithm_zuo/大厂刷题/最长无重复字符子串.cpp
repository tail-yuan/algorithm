#include<iostream>
#include<vector>
using namespace std;

//��iΪ��β,dp[i]������iλ��Ϊ��βʱ������ظ��Ӵ��ĳ���.
// �����������iΪ��β��ǰ������ƶ�Զ,��֤�����Ļ���֮��
//dpϣ����iλ��ʱ�ܹ�����֮ǰ�Ľ��dp[i-1]���м������
//Ӱ������: 1. [i]λ��Ԫ���ϴγ��ֵ�λ�� x,��map���¼
//		   2. dp[i-1]��¼����[i-1]λ���ܹ���ǰ��չ�ĳ���,i-dp[i-1]����[i-1]�ظ��ַ���λ��y
//if x < y,dp[i]=dp[i-1]+1
//if x > y,dp[i]=i-x
//�Ż�: ��Ϊֻ��Ҫ����dp[i-1]��ֵ,�����ҿ�����һ�������洢,����ʹ������dp����ռ�.
//	   �ϴγ��ֵ�λ��Ҳ�����ñ����洢,������Ҫ�ٿ�һ�ű�

class Solution
{
public:
	int longestSubStrWithoutRepeatChar(string& str)
	{
		if (str.size() == 0) return 0;
		vector<int>my_map(256,-1);//�����ַ�����һ��λ��ȫ����ʼ��Ϊ-1
		int n = str.size();
		int ans = 1;//������1
		int pre = 1;//dp[i-1],��һ��������¼
		my_map[str[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			int p1 = i - my_map[str[i]];
			int p2 = pre + 1;
			int cur = min(p1, p2);//��������ĸ���ø�Զ
			ans = max(ans, cur);
			pre = cur;
			my_map[str[i]] = i;
		}
		return ans;
	}
};