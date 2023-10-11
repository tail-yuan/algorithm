#include<iostream>
#include<vector>
using namespace std;
class QuickSort
{
public:
	void quickSort(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		quickSortHelper(arr, 0, arr.size() - 1);
	}
	void quickSortHelper(vector<int>& arr, int l, int r)
	{
		if (l < r)
		{
			swap(arr[l + (int)(rand() * (r - l + 1))], arr[r]);
			pair<int, int>p = partition(arr,l,r);
			quickSortHelper(arr,l,p.first-1);
			quickSortHelper(arr,p.second+1,r);
		}
	}
	pair<int, int>partition(vector<int>& arr, int l, int r)
	{
		int less = l - 1;
		int more = r + 1;
		while (l < more)
		{
			if (arr[l] > arr[r])
			{
				swap(arr[less + 1], arr[l]);
				l++;
				less++;
			}
			else if (arr[l] < arr[r])
			{
				swap(arr[more - 1], arr[l]);
				more--;
			}
			else
				l++;
		}
		swap(arr[r],arr[more]);
		return make_pair(less+1,more-1);
	}
};