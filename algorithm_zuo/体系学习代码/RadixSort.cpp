#include<iostream>
#include<vector>
using namespace std;
class RadixSort
{
public:
	//基数排序
	void radixSort(vector<int>& arr)
	{
		if (arr.size() == 0)
			return;
		radixSorthelper(arr, 0, arr.size() - 1,maxDigits(arr));
	}
	int maxDigits(vector<int>& arr)
	{
		int max_num = INT_MIN;
		for (int i = 0; i < arr.size(); i++)
		{
			max_num = max(max_num,arr[i]);
		}
		int res = 0;
		while (max_num != 0)
		{
			res++;
			max_num /= 10;
		}
		return res;
	}
	int getDigit(int num, int d)
	{
		return ((num / ((int)pow(10, d - 1))) % 10);
	}
	void radixSorthelper(vector<int>& arr, int begin, int end,int digit)//多少位
	{
		int radix = 10;
		int i = 0, j = 0;
		vector<int>bucket(end-begin+1);//help
		for (int d = 1; d <= digit; d++)//位数决定入桶出桶多少次
										//d=1代表这次循环是个位
		{
			vector<int>count(radix);
			for (i = begin; i <= end; i++)
			{
				j = getDigit(arr[i],d);
				count[j++];
			}
			//10个桶,计算每个桶的前缀和
			for (i = 1; i < radix; i++)
			{
				count[i] = count[i] + count[i - 1];
			}
			for (int i = end; i >= begin; i--)
			{
				j = getDigit(arr[i],d);
				bucket[count[j] - 1] = arr[i];
				count[j]--;
			}
			for (i = begin, j = 0; i <= end; i++, j++)
			{
				arr[i] = bucket[j];
			}
		}
	}
};
//int main()
//{
//	RadixSort rs;
//	cout<<rs.getDigit(123,2)<<endl;
//	cout << pow(10, 1 - 1) << endl;
//	cout << (123 / ((int)pow(10, 2 - 1))) << endl;
//	cout << ((123 / ((int)pow(10, 2 - 1))) % 10) << endl;
//}