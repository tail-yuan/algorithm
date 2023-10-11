
//��N������,��ôֵһ����1~15֮��,��������ж���
//��������ȡ�������� sqrt(15)=3
//<= > �ֳ���ô��������,����Ҫ�õľ�������������ֵ,���������ÿ�����,����������ȡ����ֵ
#include<iostream>
using namespace std;
class Solution
{
public:
	int mysqrt(int n)
	{
		if (n == 0)return 0;
		if (n < 3)return 1;
		int ans = 1;
		int L = 1;
		int R = n;
		int mid = 0;
		while (L <= R)
		{
			mid = L + (R - L);
			if (mid * mid <= n)
			{
				ans = mid;
				L = mid + 1;
			}
			else if (mid * mid > n)
				R = mid - 1;
		}
		return ans;
	}
	int mySqrt2(int n)
	{
		if (n == 0)return 0;
		if (n < 3)return 1;
		int l = 1;
		int r = n;
		while (l < r)
		{
			int mid = l + (r - l+1) /2;
			if (mid * mid < n)
				l = mid;
			else if (mid * mid > n)
				r = mid - 1;
			else
				return mid;
		}
		return l;
	}
};

//int main()
//{
//	Solution s;
//	cout << s.mysqrt(15) << endl;
//	cout << s.mysqrt(16) << endl;
//	cout << s.mysqrt(20) << endl;
//	cout << s.mysqrt(34) << endl;
//	cout << s.mySqrt2(15) << endl;
//	cout << s.mySqrt2(16) << endl;
//	cout << s.mySqrt2(20) << endl;
//	cout << s.mySqrt2(34) << endl;
//	return 0;
//}