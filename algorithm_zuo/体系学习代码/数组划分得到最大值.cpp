#include<iostream>
#include<vector>
using namespace std;

//����һ������arr����ΪN�� ����԰����ⳤ�ȴ���0��С��N��ǰ׺��Ϊ�󲿷֣� ʣ�µ�
//��Ϊ�Ҳ��֡� ����ÿ�ֻ����¶����󲿷ֵ����ֵ���Ҳ��ֵ����ֵ�� �뷵�����ģ�
//�󲿷����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ
// ��ȷ���������ֵmax,���۱����ֵ��ĸ�����,һ����max��������
//	1. ��������ֵ��󲿷�,��λ�ȡ�Ҳ����������ֵx ,��abs(max-x)���?
//	�Ҳ�������ֻҪarr[n-1]һ��,->ֻҪarr[n-1]ֵ
//		����Ҳ�������num >  arr[n-1]=> abs(max-num)<abs(max-arr[n-1])
//		����Ҳ�������num< arr[n-1],����������,��Ϊ����Ҫ�ľ����Ҳ������ֵ
// ͬ��,�󲿷�ֻҪarr[0]һ��

class MaxABSBetweenLeftAndRight
{
public:
	int getMax1(vector<int>& arr)
	{
		int maxVal = INT_MIN;
		for (int i = 0; i < arr.size(); i++)
			maxVal = max(maxVal,arr[i]);
		return maxVal - min(arr[0],arr[arr.size() - 1]);
	}
	//���������absֵ
	int getMax2(vector<int>& arr)
	{
		int res = INT_MIN;
		int maxLeft = 0;
		int maxRight = 0;
		for (int i = 0; i != arr.size() - 1; i++)
		{
			maxLeft = INT_MIN;
			for (int j = 0; j <= i; j++)
				maxLeft = max(arr[j],maxLeft);
			maxRight = INT_MIN;
			for (int j = 0; j <= i; j++)
				maxRight = max(arr[j], maxRight);
			res = max(abs(maxLeft-maxRight),res);
		}
		return res;
	}
	//���������¼ǰ[i]�����������ֵ,��x�������ֵ
	int getMax(vector<int>& arr) 
	{
		int n = arr.size();
		vector<int>lArr(n);
		vector<int>rArr(n);
		lArr[0] = arr[0];
		rArr[n - 1] = arr[n - 1];
		for (int i = 1; i < n; i++)
			lArr[i] = max(lArr[i-1],arr[i]);
		for (int i = n - 2; i >= 0; i--)
			rArr[i] = max(rArr[i+1],arr[i]);
		int maxVal = 0;
		for (int i = 0; i < n - 1; i++)
			maxVal = max(maxVal,abs(lArr[i]-rArr[i]));
		return maxVal;
	}
};