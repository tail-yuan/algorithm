#include<iostream>
#include<vector>
using namespace std;

// �޷�ʵ�����ÿ������,Ȼ����ˮ�ۼ�.�������С���ȿ�������һ����Ĳ�����,��ô������ľ���ȫʧȥ����
// ֻ��עindexλ�������ܴ洢����ˮ->�������������ֵleftMax rightMax�Ľ�Сֵ��ȥarr[index]
// �������������ֵ,����0,�����޷����λ�ô洢ˮ
//=> max(min(leftMax,rightMax)-arr[i],0)
// ��һ:���ø�������,һ����¼tmp[i]����[0,i-1]λ�����ֵ
//					,һ����¼tmp[i]����[i+1,arr.size()-1]�������ֵ
// <O(N),O(N)>
// ����: ʹ�����޼������� <O(N),O(1)>
//	����ָ��
//	�������ֵ�ı�С,lr�ĸ�λ�õĴ���ֵ�ͱ�ȷ��
// 0λ�� n-1λ�ÿ϶��治סˮ,����
//	
class GetSumWater
{
public:
	//<O(N^2),O(1)>
	int getWater1_1(vector<int>& arr)
	{
		if (arr.size()<3)//ֻ������ֵҲ�治סˮ
			return 0;
		int ret = 0;
		for (int i = 0; i < arr.size() - 1; i++)
		{
			int leftMax = 0;
			int rightMax = 0;
			for (int l = 0; l < i; l++)
				leftMax = max(arr[l],leftMax);
			for (int r = i + 1; i < arr.size(); i++)
				rightMax = max(arr[r],rightMax);
			ret += max(0,min(leftMax,rightMax)-arr[i]);
		}
	}
	//<O(N), O(N)>
	int getWater1_2(vector<int>& arr)
	{
		if (arr.size() < 3)//ֻ������ֵҲ�治סˮ
			return 0;
		int n = arr.size() - 2;
		vector<int>leftMax(n);
		vector<int>rightMax(n);
		// leftMax[i]��¼����ǰi��ֵ�����ֵ
		for (int i = 1; i < n; i++)
			leftMax[i] = max(leftMax[i-1],arr[i]);
		//rightMax[i]����[i+1,arr.size()-2]�������ֵ
		rightMax[n - 1] = arr[n + 1];
		for (int i = n - 2; i >= 0; i--)
			rightMax[i] = max(rightMax[i+1],rightMax[i+2]);

		int ret = 0;
		for (int i = 1; i <= n; i++)
			ret += max(0, min(leftMax[i - 1], rightMax[i-1] - arr[i]));
		return ret;
	}
	int getWater2(vector<int>& arr)
	{
		if (arr.size() < 3)//ֻ������ֵҲ�治סˮ
			return 0;
		int ret = 0;
		int leftMax = arr[0];
		int rightMax = arr[arr.size()-1];
		//�±����˫ָ��
		int l = 1;
		int r = arr.size() - 2;
		while (l <= r)
		{
			if (leftMax <= rightMax)//ֻרע��lλ�����ٴ����ˮ���ż��Ѿ��޶�,����leftMax
			{
				ret += max(0,leftMax-arr[l]);
				leftMax = max(leftMax,arr[l]);//if need ����leftMax
				l++;
			}
			else//ֻרע��rλ�����ٴ����ˮ���ż��Ѿ��޶�,����rightMax
			{
				ret += max(0,rightMax-arr[r]);
				rightMax = max(rightMax,arr[r]);
				r--;
			}
		}
		return ret;
	}
};