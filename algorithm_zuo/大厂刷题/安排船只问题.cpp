
//https://leetcode.cn/problems/boats-to-save-people/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
//�������� people ��people[i]��ʾ�� i ���˵����� �������������ޣ�
//ÿ�Ҵ����Գ��ص��������Ϊ limit��ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit��
//���� �����������������С���� ��

//���:
//1. ���� �����һ���˵���������Ѿ�����limit�϶��߲���
//2. ���ҵ�limit/2��λ�ü�Ϊleft,��һ��λ�ü�Ϊright
//3. if [left]+[right]>limit,flag[left]=false,left--,
//	 else if [left]+[right]<limit,y=right,right++,ֱ������������,
// ̰�ĵ��� left��ǰright-y��,ȥ�ֱ�ƥ��[y,right]���˷ֱ���һ�Ҵ�,���������ø�С����Щȥƥ������
// �Ӷ����������ٵĴ�ֻ.flag[...]=true
// ��������,
// 1. ��������Ⱥľ�����ѭ��,��ʱ
//		��ֻ���������� flag[]=true�ĸ���/2
//			+ flag[]=false�ĸ���/2(����������,��������ȡ��,������һ�Ҵ�)�����ش���㲻��,���Ǻ�С�Ŀ���
//			+ n-right(��Щ����̫��ֻ���Լ���һ�Ҵ�)
// 2. �����Ҳ��Ⱥľ�,��ʱ:
//		��ֻ���������� flag[] = true�ĸ��� / 2
//			+ flag[]=false�ĸ���/2(����������,��������ȡ��,������һ�Ҵ�)�����ش���㲻��,���Ǻ�С�Ŀ���
//��ʽ����flag[]=true�ĸ���/2
//			+ flag[]=false�ĸ���/2
//			+ n-right(2ʱΪ0)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int numRescueBoats(vector<int>& arr, int limit)
	{
		if (arr.size() == 0)
			return 0;
		int n = arr.size();
		sort(arr.begin(), arr.end());
		if (arr[n - 1] > limit) return -1;
		//1. �����ҵ�leftλ�� <=limit/2
		int left = -1;
		//left=FindHalfLimitIndex(arr, limit);// 77/78,��һ����ļ������
		for (int i = n - 1; i >= 0; i--)
			if (arr[i] <= limit / 2)
			{
				left = i; 
				break;
			}

		if (left == -1) return n;//˵�����Ǵ���limit/2ֻ���Լ�һ�Ҵ�

		int tmp = left;
		int right = left + 1;
		int noUse = 0;
		while (left >= 0)
		{
			int solved = 0;
			while (right < n && arr[left] + arr[right] <= limit)
				right++, solved++;
			if (solved == 0)
				noUse++, left--;
			else
				left = max(-1, left - solved);
		}
		//ֻ�����������м���used
		//noUse�϶������������,etc���Ϊ0,�������ұ��Ⱥľ�,���ش�Ķ��õ�����԰���.
		int all = tmp + 1;
		int use_boat = all - noUse;
		int etc = (n - all-use_boat);
		return use_boat + ((noUse + 1) >> 1) + etc;
	}
	int FindHalfLimitIndex(vector<int>& arr, int limit)
	{
		int target = limit / 2;
		int l = 0, r = arr.size() - 1;
		while (l < r)
		{
			int mid = l + (r - l + 1) / 2;
			if (arr[mid] == target)
				return mid;
			else if (arr[mid] < target)
				l = mid;
			else
				r = mid - 1;
		}
		return l;
	}
};