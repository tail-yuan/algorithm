#include"Header.hpp"
class MySwap
{
public:
	void swap1(int a,int b)
	{
		int c = a;
		a = b;
		b = c;
	}
	void swap2(int a, int b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
};
class Sort
{
public:
	//ѡ����Сֵ���������,���������
	//i=0 ���ܱȽ�n-1��
	//i=1 ���ܱȽ�n-2��
	//...
	//�Ȳ�������� 1/2*n*(a1+an)=1/2 n^2
	void SelectSort(int* a, int n)
	{
		if (a == nullptr || n < 2)
			return;
		for (int i = 0; i < n - 1; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < n; j++)
			{
				minIndex = a[minIndex] > a[j] ? j : minIndex;
			}
			swap(a[minIndex], a[i]);
		}
	}
	void BubbleSort(int* a, int n)
	{
		if (a == nullptr || n < 2)
			return;
		for (int e = n - 1; e > 0; e--)//������߽�,һֱ������С(��Ϊһ�α��������ֵ���������)
		{
			for (int i = 0; i < e; i++)
			{
				if (a[i] > a[i + 1])
					swap(a[i], a[i + 1]);
			}
		}
	}
	//����0~i�ķ�Χ������
	void InsertSort(vector<int>& a, int n)
	{
		if (a.size()==0 || n < 2)
			return;
		for (int i = 1; i < n-1; i++)
		{
			for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
};
class BS
{
public:
	//����
	bool BSExist(int* a, int n, int x)
	{
		if (a == nullptr || n < 2)
			return false;
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + ((r-l) >> 2);
			if (a[mid] > x)
				r = mid - 1;
			else if (a[mid] < x)
				l = mid + 1;
			else
				return true;
		}
		return a[l]==x;
	}
	//����
	//�ҵ��������ڵ���x��λ��ֵ
	int BSNearLeft(int* a, int n,int x)
	{
		if (a == nullptr || n < 2)
			return -1;
		int l = 0, r = n - 1;
		int index = -1;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (a[mid] >= x)
			{
				index = mid;
				r = mid - 1;
			}
			else if (a[mid] < x)
			{
				l = mid + 1;
			}
		}
		return index;
	}
	//����
	//�Ҿֲ���Сֵ
	int FindOneLessValue(int* a, int n)
	{
		if (a == nullptr || n == 0)
			return -1;
		//0λ��
		if (n == 1 || a[0] < a[1])
			return a[0];
		//n-1λ��
		if (a[n - 1] < a[n - 2])
			return a[n - 1];

		//[0,n-1]λ���ϱش��ڹյ�,Ҳ���Ǿֲ���Сֵ,ֱ��ȡmid
		int l = 0, r = n - 1;
		int mid = 0;
		while (l < r)
		{
			mid = l + (r - l) / 2;
			if (a[mid] < a[mid + 1] && a[mid] < a[mid - 1])
				return mid;
			else if (a[mid - 1] < a[mid])
				r = mid - 1;
			else if (a[mid + 1] < a[mid])
				l = mid + 1;
		}
		return l;
	}
};
int process(vector<int>& arr, int l, int r)
{
	if (l == r)
		return arr[l];
	int mid = l + (r - l) >> 1;
	int leftMax = process(arr,l,mid);
	int rightMax = process(arr,mid+1,r);
	return max(leftMax,rightMax);
}
int GetMax(vector<int>&arr)
{
	return process(arr,0,arr.size()-1);
}