#include<iostream>
#include<vector>
using namespace std;

class SmallSum
{
public:
	int smallSum(vector<int>& arr)
	{
		if (arr.size() < 2)return 0;
		return mergeSort(arr,0,arr.size()-1);
	}
	int mergeSort(vector<int>& arr, int l, int r)
	{
		if (l == r)return 0;
		int mid = l + ((r - l)) >> 1;
		return mergeSort(arr,l,mid)+
				mergeSort(arr,mid+1,r)+
				merge(arr,l,mid,r);
	}
	int merge(vector<int>& arr, int l, int mid, int r)
	{
		vector<int>tmp(r-l+1);
		int i = 0;
		int p1 = l, p2 = mid + 1;
		int res = 0;
		while (p1 <= mid && p2 <= r)
		{
			res += arr[p1] < arr[p2] ? arr[p1] * (r - p2 + 1) : 0;
			tmp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];//相等时一定是p2++,保证后续最小和正确性
		}
		while (p1 <= mid)
			tmp[i++] = arr[p1++];
		while (p2<=r)
			tmp[i++] = arr[p2++];
		for (i = 0; i < tmp.size(); i++)
			arr[l + i] = tmp[i];
		return res;
	}
};