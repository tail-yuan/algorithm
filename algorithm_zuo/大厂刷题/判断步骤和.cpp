//定义何为step sum ?比如680，680 + 68 +6 = 754，
//680的step sum叫754给定一个正数num，
//判断它是不是某个数的step sum

//y>x,那么y的步骤和一定大于x的,并且步骤和一定大于自身
//所以存在单调性,单调递增
//二分查找,1~sum之间,如果没找到说明sum不是任何的步骤和.
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	//O(log2(x)*log10(x))二分+求x步骤和
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