#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//��ĿҪ��:
//����һ������arr�������������и�����0������ֻ����ѡ�������֣�
//�뾡�����������ּ������ľ���ֵ����С���ؿ��ܵ���С��ֵ
//���:
//���������ȫ������,��ôѡ����С������ֵ���
//���������ȫ�Ǹ���,��ôѡ����������ֵ���
//��������и���0,��ô��С��������֮��,���������ҵ��͸�����ӽ����������,ʱ�̼�¼��Сֵ
class Solution
{
public:
	int getMinAbs(vector<int>& arr)
	{
		int n = arr.size();
		int ret = 0;
		if (n < 2)
		{
			for (auto e : arr)
				ret += e;
			return ret;
		}
		sort(arr.begin(), arr.end());
		int target = 0;
		//1. ���ֲ��ҵķ�ʽȷ��0��λ��,��Ϊ0���ܲ�����,<= > ������.���ܴ��ڶ��Ǹ���,���߶�������
		int pos0 = FindXPos(arr,0);
		if (pos0 < 0)
			return min(arr[0] + arr[1],arr[n-1]+arr[n-2]);
		
		//1.5 Ϊ���������������Ч��,ʹ�ö��ֲ��ҵķ�ʽ
		//2. ����������С��0�Ĳ���,���ұ�>0�Ĳ����������[i]��
		int ans = INT_MAX;
		for (int i = 0; i < pos0; i++)
		{
			int aim = -arr[i];
			int close= findClosestValue(arr,aim);
			ans = min(ans, close);
		}
		return ans;
	}
	int FindXPos(vector<int>&arr,int aim)
	{
		int n = arr.size();
		int left = 0, right = n - 1;
		int pos0 = -1;
		while (left < right)
		{
			int mid = left + (right - left + 1) / 2;
			if (arr[mid] > aim) right = mid - 1;
			else if (arr[mid] == aim)return mid;
			else left = mid;
		}
		//����˵��û�ҵ�
		return pos0;
	}
	int findClosestValue(const std::vector<int>& arr, int x) {
		int left = 0;
		int right = arr.size() - 1;
		while (left <= right) 
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == x) 
				return arr[mid];
			else if (arr[mid] < x) 
				left = mid + 1;
			else 
				right = mid - 1;
		}
		if (right < 0) 
			return arr[left];
		else if (left >= arr.size()) 
			return arr[right];
		else 
		{
			if (x - arr[right] < arr[left] - x) 
				return arr[right];
			else 
				return arr[left];
		}
	}
};