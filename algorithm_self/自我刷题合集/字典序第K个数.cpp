#include<iostream>
#include<vector>
#include<list>
using namespace std;
//best
class Solution
{
public:
	int getPrefixCount(int n, long long cur, long long next)
	{
		int ret = 0;
		while (cur <= n)
		{
			long long p1 = next - cur;//���±ƽ�nʱ,������curΪǰ׺��һ������С��n,������ȡ����[cur,next)��next-cur��;
			long long p2 = n + 1 - cur;   //���±ƽ�nʱ,������curΪǰ׺��һ�����д���n,��cur<n<next,С��n�ĸ���,��һ�㼴[cur,n]�ĸ�������n+1-cur;
			ret += min(p1, p2); //��ÿһ����curΪǰ׺����С��n��ֵ�ĸ���������
			//���±ƽ�,��������油0����
			cur *= 10;
			next *= 10;
		}
		return ret;
	}
	int findKthNumber(int n, int k)
	{
		long long  cur = 1;
		k--;
		while (k>0)
		{
			int num = getPrefixCount(n, cur, cur + 1);//��ȡ��curΪǰ׺,��������С��n�ĸ���
			if (num < k)
			{
				cur++;
				k -= num;
			}
			else
			{
				cur *= 10;
				k--;
			}
		}
		return cur;
	}
};
//chatgpt
class Solution
{
public:
	/*`countSteps` �����������Ǽ����ڵ�ǰǰ׺��Χ�ڣ��� `first` �� `last - 1`������ҿ����䣩���ж��ٸ�������

	���ֵ�������Ĺ����У�������Ҫ���㵱ǰǰ׺��Χ�ڵ�����������
	�Ա��ж��Ƿ���Ҫ�����ڵ�ǰǰ׺��Χ�ڲ�����һ���ֵ���������������Ҫ�ƶ�����һ��ǰ׺��
	ͨ�����㵱ǰǰ׺��Χ�ڵ��������������ǿ����ж��Ƿ��ܹ������ڵ�ǰǰ׺�ڲ��ң�������Ҫ������һ��ǰ׺��
	`countSteps` ������������������
	- `n`�����������ޣ�������Ҫ�ҵ�����С�ڵ��� `n` ��������
	- `first`����ǰǰ׺����ʼ����������ǰǰ׺����Сֵ��
	- `last`����ǰǰ׺����һ��ǰ׺����ʼ����������һ��ǰ׺����Сֵ��
	�����ķ���ֵ�ǵ�ǰǰ׺��Χ�ڵ�����������
	�ں����ڲ�������ʹ��ѭ�������Ͻ�ǰ׺����ʮ����ֱ���������� `n` ���ߵ�����һ��ǰ׺����ʼ���� `last`��
	ͬʱͳ��ǰ׺��Χ�ڵ��������������������Ǿ��ܵõ���ǰǰ׺��Χ�ڵ�����������*/
	int getStep(int n, long long  first, long long last)
	{
		int ret = 0;
		while (first <= n)
		{
			ret += min(static_cast<long long>(n + 1), last) - first;
			first *= 10;
			last *= 10;
		}
		return ret;
	}
	int findKthNumber(int n, int k)
	{
		int step = 0;
		int cur = 1;
		k--;
		while (k > 0)
		{
			step = getStep(n, cur, cur + 1);//�������curΪǰ׺���ж��ٸ�����
			if (step <= k) //�������ǰ׺��
			{
				k -= step;
				cur += 1;	//������һ��ǰ׺
			}
			else //�����ǰ׺��,������0����������k==0ʱ����
			{
				k--;		//cur������ҵ�һ��,k--
				cur *= 10;	//��curǰ׺���ٲ�0
			}
		}
		return cur;
	}
};
//mine ����,û�������ʶ���ֵ���Ĵ�С
class Solution1
{
public:
	//100 �ֵ�����ҪС��11��.��ʮ���ٳ��ֵ�ʱ��,�ֵ����tmp��ͬ,ͷ��
	//131 �ֵ�����Ҫ����1111��,����ֻ������1��һ�����б�131�Ϻ��λ��
	//ǰ������!!�������ֻ��ʵ���˼򵥵İ�����Ԫ���ֵ�����з�
	int findKthNumber(int n, int k)
	{
		if (k > n) return -1;

		vector<vector<int>> tables(10);
		//��ϣ�ķ�ʽ,����ͷ�ֵ�����ͬ�ķŵ�һ������
		//1. ����N����,hashFunc()= x/ 10=>retβ����뵽��Ӧ���������
		//%10 ֻ���1~100����,�ֵ����ͷ����1~9,���� while x/10 if x<=9
		for (int i = 1; i <= n; i++)//��˳�����,����β�岻�ÿ�����ͬ��ʼ���ֵ����ּ���������
		{
			int tmp = i;// /10֮��õ�����index����ԭֵ
			while (tmp >= 10)
			{
				tmp /= 10;
			}
			//i<=9
			tables[tmp].push_back(i);
		}
		//2. ��k����,���Ǵ�index=1��������ʼ����
		vector<int>ans(n);
		int index = 0;
		for (int i = 1; i < tables.size(); i++)
		{
			for (int j = 0; j < tables[i].size(); j++)
			{
				ans[index++] = tables[i][j];
			}
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		return ans[k - 1];
	}
};

int main()
{
	Solution s;
	cout << s.findKthNumber(100, 10);
	return 0;
}