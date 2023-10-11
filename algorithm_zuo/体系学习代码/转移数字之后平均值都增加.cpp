
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//从A拿数字到B中,两个集合平均值都增加
//只可能是平均值大的A->B中,
//为了更多次的进行magic操作,
//A 平均值x B 平均值y,x>y,将A的[y,x]范围内的最小值放到B中,AB平均值都增加
// A增加幅度最大,B更小的增加,使得x-y差值更大,此后进行的操作越多.
//贪心策略
class MagicOp
{
public:
	double GetAvg(int sum, int size)
	{
		return (double)(sum / size);
	}
	//两个数组都不为空,并且不含有重复数字
	int maxOp(vector<int>& arr1, vector<int>& arr2)
	{
		double sum1 = 0;
		for (int i = 0; i < arr1.size(); i++)
			sum1 += arr1[i];
		double sum2 = 0;
		for (int i = 0; i < arr2.size(); i++)
			sum2 += arr2[i];

		double avg1 = sum1 / arr1.size();
		double avg2 = sum2 / arr2.size();
		vector<int> arrMore;
		vector<int>arrLess;
		double sumMore = 0;
		double sumLess = 0;
		if (avg1 > avg2)
		{
			arrMore = arr1;
			sumMore = sum1;
			arrLess = arr2;
			sumLess = sum2;
		}
		else if (avg1 == avg2)
			return 0;
		else
		{
			arrMore = arr2;
			sumMore = sum2;
			arrLess = arr1;
			sumLess = sum1;
		}
		sort(arrMore.begin(),arrMore.end());
		unordered_set<int>hashSet;
		for (auto e : arrLess)
			hashSet.insert(e);
		int ops = 0;
		int moreSize = arrMore.size();
		int lessSize = arrLess.size();
		for (int i = 0; i < arrMore.size(); i++)
		{
			double cur = (double)arrMore[i];
			if (cur< GetAvg(sumMore, moreSize)
				&& cur>GetAvg(sumLess, lessSize)
				&& hashSet.count(cur) == 0)
			{
				sumMore -= cur;
				moreSize--;
				sumLess += cur;
				lessSize++;
				hashSet.insert(cur);
				ops++;
			}
		}
		return ops;
	}
};