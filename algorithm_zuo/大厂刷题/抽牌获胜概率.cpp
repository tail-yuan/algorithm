//�ȸ���������չ����ֵΪ1-N�������һ��ÿ���������ȸ��ʵĳ��1~N�е�һ��,�´γ�ỻһ���µ��飬
//�������鵱�ۼӺ�<aʱ���㽫һֱ���Ƶ��ۼӺ�>=a��<bʱ���㽫��ʤ���ۼӺ�>=bʱ���㽫ʧ��
//���ػ�ʤ�ĸ��ʣ������Ĳ���ΪN��a��b


//���:
//ÿ�ζ���1/N�ĸ��ʴ�[1,N-1]����ѡ��x,ʹ���ۼӺ͵���cur,��ʤ�ĸ�����p,����
//��1/n�ĸ��ʵ���cur,��ʤ�ĸ�����y,��ô����y/N
// N=4,��ô��ʱ�ۼӺ�cur=5Ӯ�ĸ��ʾ���,(p(6)+p(7)+p(8)+p(9))/4=p(5)
//		��ô��ʱ�ۼӺ�cur=4Ӯ�ĸ��ʾ���,(p(6)+p(7)+p(8)+p(5))/4=p(4)
// ��ʱҪ��֪��p(4)ֻ��Ҫ֪��p(5)��p(9)�Ϳ������,�Ͳ���Ҫ��ȥö��һ��p(6.7.8)�ĸ����Ƕ���Ȼ�󷵻�
// p(4)*N=p(5)+p(5)*4-p(9)
// p(i)*N=p(i+1)+4*p(i+1)-p(i+N+1)
// �����Ǿ���a�Ƚ�Զ������,�������������Ե�
// ������a��ǰһ��λ��ʱ,��������������ʽ,p(a-1) = (b-a)/N
// ������a��ǰ2��λ��ʱ,��������������ʽ,...
// ������b-N-1λ��,�Լ�֮ǰ��λ��ʱ������֮ǰ��ʽ��. 
// [b-N,a]�ķ�Χ�����ⷶΧ����Ҫ���е�,�������Ƿ�-�����β��,-p(i+N+1)
//��εȸ���? ��ö����Ϊ�Ż�
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	int n;
	int a;
	int b;
public:
	double func(int N, int a, int b)
	{
		if (a >= b || n == 0 || a < 0 || b < 0)//��Ϸû��������ȥ
			return 0.0;
		if (b - a >= n)//��Ӯ������ǳ���,���һ��ʲô�ƶ�Ӯ
			return 1.0;
		vector<double>dp(n);
		for (int i = a; i < b; i++)
			dp[i] = 1.0;
		for (int i = b; i < n; i++)
			dp[i] = 0.0;
		for (int cur = a - 2; cur >= 0; cur--)
		{
			double w = dp[cur + 1] + dp[cur + 1] * N;
			if (cur + 1 + N < b)
				w -= dp[cur + 1 + N];
			dp[cur] = w/N;
		}
		return dp[0];
	}
public:
	//��ö����Ϊ�Ż�
	double getP_plus(int cur)
	{
		if (cur >= a && cur < b)
			return 1.0;
		if (cur > b)
			return 0.0;
		if (cur = a - 1)
			return (b - a) / n;
		double w = getP_plus(cur + 1) + getP_plus(cur + 1) * n;
		if (cur + 1 + n < b)
			w -= getP_plus(cur + 1 + n);
		return w / n;
	}
public:
	double func(int N, int _a, int _b)
	{
		n = N;
		a = _a;
		b = _b;
		if (a >= b || n == 0||a<0||b<0)//��Ϸû��������ȥ
			return 0.0;
		if (b - a >= n)//��Ӯ������ǳ���,���һ��ʲô�ƶ�Ӯ
			return 1.0;
		return getP(0);
	}
	double getP(int cur)
	{
		if (cur >= a && cur < b)
			return 1.0;
		if (cur >= b)
			return 0.0;
		double w = 0.0;
		for (int i = 1; i <= n; i++)
			w += getP(cur+i);
		return w / n;
	}
public:
	//�������汾n=10 a=17 b=21
	double f()
	{
		return p(0);
	}
	//�����ۼӺ�����curʱ,������Ļ�ʤ����
	double p(int cur)
	{
		if (cur >= 17 && cur < 21)
			return 1.0;
		if (cur >= 21)
			return 0.0;
		double w = 0.0;
		for (int i = 1; i <= 10; i++)
			w += p(cur + i);
		return w / 10;
	}
};