//https://leetcode.cn/problems/rabbits-in-forest/submissions/
//���:
//ÿ����˵�Ķ�����ȷ��,arr[i]����i˵�����·���ɫ��ͬ���˻���arr[i]��
//��ô,����������·���ͬ,��ô��Ȼarr[i]����ͬ��,������ɫ��ͬ����һ������,�ų��Լ������˵ĸ���Ӧ����һ����
//��ô�������������,����arr[i]=x,��ô�����ɫ������������Ӧ����x+1��,
//�������ͳ�Ƶ��������ɫ�ĸ���,��x�ĸ�����c,��ôӦ����c/(x+1) ����ȡ����ô����
//����x+1����˵��û��ͳ�Ƶ�
//����ȡ����ôʵ��? (a+(b-1))/b
//��������������((c+x)/(x+1)) * (x+1)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int minPeople(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		sort(arr.begin(), arr.end());
		int ans = 0;
		int count = 1;//��ÿһ�������
		int prev = arr[0];
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] != prev)//�¿�һ��,��Ҫ��֮ǰ������н���
			{
				ans += ((count + prev) / (prev + 1)) * (prev + 1);
				prev = arr[i];
				count = 1;
			}
			else
			{
				count++;
			}
		}
		//���һ�黹û����!
		return ans + ((count + prev) / (prev + 1)) * (prev + 1);
	}
};