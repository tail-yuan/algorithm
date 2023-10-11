#include<iostream>
#include<vector>
using namespace std;
//��һ��������,�ж��ٸ��������а�������������-------������K��
//����������������forѭ��,ͳ���������������������O(n^2)
//�Ż�Ϊ�������ڵķ�ʽ,��Ϊ��ͳ��������ĸ���,����ڵ�k��ʱ���ظ����ֵĳ���
//Ϊ�˷���ͳ�ƴ�Ƶ,��Ҫʹ������������ά��
//��Ҫ���ű�,һ�ż�¼k-1�����ֵĴ�����<��������,��Ӧ����>�Լ�leftIndex1λ��,��һ�ű���K�ֵ�
//1. ͬʱ����,��rλ�����ַŵ����ű���,
//2. ��k-1���ڳ���k������ʱ,���󴰿�һֱ����k-1��,��ʱ��¼leftIndex1,
//	 ͬ��K���ڳ���k+1������ʱ,���󴰿�һֱ��K��,��¼leftIndex2,
//	��ʱ�����������������������l1-l2
//
//��Ŀ����: �����г��ֵ����ֲ��ᳬ������ĳ���,���Կ���ֱ�ӿ���������д�Ƶͳ��,���ù�ϣ����
// https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=68&vd_source=cc945ef88574fe2db5e814c0c265a4c7
class Solution
{
public:
	int subArrWithKKindsNum(vector<int>& arr,int k)
	{
		int n = arr.size();
		vector<int>lessMap(n,0);
		vector<int>KMap(n,0);
		int kind1 = 0, kind2 = 0;
		int l1 = 0, l2 = 0;
		int ans = 0;
		for (int r = 0; r < n; r++)
		{
			//����rλ���������³��ֵ��ַ�
			if (lessMap[arr[r]] == 0)
				kind1++;
			if (KMap[arr[r]] == 0)
				kind2++;

			lessMap[arr[r]]++;
			KMap[arr[r]]++;

			while (kind1 == k)
			{
				if (lessMap[arr[l1]] == 1)
					kind1--;
				lessMap[arr[l1++]]--;
			}
			while (kind2 > k)
			{
				if (KMap[arr[l2]] == 1)
					kind2--;
				KMap[arr[l2++]]--;
			}
			ans += l1 - l2;
		}
		return ans;
	}
};
//���������ж��������������������<=K��,�ж�����С�ڵ���k-1��,�����������
//�ж��ٸ����������������ǡ��Ϊk��.
//Func�����ṩ���ֹ���,���Ǻܼ򵥵Ĵ���������
//��rλ��Ϊ��β�������������[0,0][0,1][0,2][0,3]...[0,k],һ����k-0+1
//l++�����r-l+1��
#include<unordered_map>
class Solution2
{
public:
	int subArrWithKKindsNum(vector<int>& arr, int k)
	{
		return func(arr, k) - func(arr, k - 1);
	}
	int func(vector<int>& arr, int k)
	{
		int ans = 0;
		int l = 0;
		int n = arr.size();
		unordered_map<int, int>hashMap;
		for (int r = 0; r < n; r++)
		{
			//���������������,k--���������
			if (hashMap.count(arr[r]) == 0 || hashMap[arr[r]] == 0)
				k--;
			hashMap[arr[r]]++;
			while (k < 0)//˵����ʱ��������k+1������
			{
				hashMap[arr[l]]--;
				if (hashMap[arr[l]] == 0)
					k++;
				l++;
			}
			ans += r-l + 1;
		}
		return ans;
	}
};