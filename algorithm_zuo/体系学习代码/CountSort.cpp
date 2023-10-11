#include<iostream>
#include<vector>
using namespace std;
class CountSort
{
public:
	void countSort(vector<int>& arr)
	{
		if (arr.size() == 0)
			return;
		int max_num = INT_MIN;
		for (int i = 0; i < arr.size(); i++)
			max_num = max(max_num, arr[i]);
		vector<int>bucket(max_num+1);
		for (int i = 0; i < arr.size(); i++)
		{
			bucket[arr[i]]++;
		}
		int i = 0;
		for (int j = 0; j < bucket.size(); i++)
			while (bucket[j]--)
				arr[i++] = j;
	}

};