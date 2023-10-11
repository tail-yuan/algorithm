#include<iostream>
#include<vector>
using namespace std;

class MergeSort
{
public:
	//���Ϊ����,��b=2 a=2 log(b,a)==d==1 
	// d:���������ǽ�N������->tmp��,tmp->arrԭ����������2*T(N)��O(N)
	//T(N)=N^1*logN
	//O(N^2)��ѡ��ð��,�����Ƚ��˽���N�β����һ����λ�õ�ȷ��
	//�鲢:���������俪ʼ���ұ������������αȽ�,û���˷ѱȽϴ���
	void mergeSort(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		merageSortHelper(arr,0,arr.size()-1);
	}
	void merageSortHelper(vector<int>& arr, int l, int r)
	{
		if (l == r)return;
		int mid = l + ((r - l) >> 1);
		merageSortHelper(arr,l,mid);
		merageSortHelper(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
	void merge(vector<int>& arr, int l, int mid, int r)
	{
		vector<int>tmp(r-l+1);
		int i = 0;
		int p1 = l;
		int p2 = mid + 1;
		while (p1 <= mid && p2 <= r)
		{
			tmp[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
		}
		while (p1 <= mid)
			tmp[i++] = arr[p1++];
		while (p2 <= r)
			tmp[i++] = arr[p2++];
		for (i = 0; i < tmp.size(); i++)
			arr[l + i] = tmp[i];
	}
};