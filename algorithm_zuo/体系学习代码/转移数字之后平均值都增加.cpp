
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//��A�����ֵ�B��,��������ƽ��ֵ������
//ֻ������ƽ��ֵ���A->B��,
//Ϊ�˸���εĽ���magic����,
//A ƽ��ֵx B ƽ��ֵy,x>y,��A��[y,x]��Χ�ڵ���Сֵ�ŵ�B��,ABƽ��ֵ������
// A���ӷ������,B��С������,ʹ��x-y��ֵ����,�˺���еĲ���Խ��.
//̰�Ĳ���
class MagicOp
{
public:
	double GetAvg(int sum, int size)
	{
		return (double)(sum / size);
	}
	//�������鶼��Ϊ��,���Ҳ������ظ�����
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