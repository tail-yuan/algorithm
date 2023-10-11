//�����Ϊstep sum ?����680��680 + 68 +6 = 754��
//680��step sum��754����һ������num��
//�ж����ǲ���ĳ������step sum

//y>x,��ôy�Ĳ����һ������x��,���Ҳ����һ����������
//���Դ��ڵ�����,��������
//���ֲ���,1~sum֮��,���û�ҵ�˵��sum�����κεĲ����.
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	//O(log2(x)*log10(x))����+��x�����
	bool isStepNum(int stepNum)
	{
		int l = 0;
		int r = stepNum;
		while (l <= r)
		{
			int mid = l + (l - r) / 2;
			int cur = f(mid);
			if (cur < stepNum)
				l = mid + 1;
			else if (cur > stepNum)
				r = mid - 1;
			else
				return true;
		}
		return false;
	}
	int f(int n)
	{
		int sum = 0;
		while (n != 0)
		{
			sum += n;
			n /= 10;
		}
		return sum;
	}
};