#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//��������ѡ��������,�жϳ˻��Ƿ�ֻ��һ����������
//���ؿ���ѡ���������ϵĶ���
class Solution
{
public:
	//�ж�һ�����Ƿ�ֻ��һ����������
	bool isTrue(int num)
	{
		string tmp = to_string(num);
		int count = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] != '0')
				count++;
		}
		return count == 1 ? true : false;
	}
	int perfectPair1(vector<int>& arr)
	{
		int n = arr.size();
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int x = arr[i], y = arr[j];
				if (isTrue(x * y))
				{
					count++;
				}
			}
		}
		return count;
	}
};
