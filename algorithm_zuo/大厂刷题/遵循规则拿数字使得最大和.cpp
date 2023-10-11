//������Ѷ
//����һ������arr��������ĳ����a��ʱ���������е����� + a
//�뷵�����������������ߵ�������
//���� : [2, 3, 1]
//������3ʱ�����3�֣�������[5, 4]
//������5ʱ�����5�֣�������[9]
//������9ʱ�����9�֣������ɿ�
//����������ȡ��ʽ�������ܷ�17

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	//������ʽ: 
	int pick(vector<int>&arr)
	{
		if (arr.size() == 1)
			return arr[0];
		//��������iλ������,�õ����������,�����ڴ���������м���...
		//�ܹ���õ����ֵ
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			vector<int>rest = func(arr, i);
			ans = max(ans, arr[i] + pick(rest));
		}
		return ans;
	}
	vector<int>func(vector<int>& arr, int i)
	{
		vector<int>rest(arr.size() - 1);
		int ri = 0;
		for (int j = 0; j < i; j++)
			rest[ri++] = arr[i] + arr[j];
		for (int j = i + 1; j < arr.size(); j++)
			rest[ri++] = arr[i] + arr[j];
		return rest;
	}
public:
	//����������,ȡ��˳������ڴ�ʱ������ѡȡ���ֵ�ۼ�,
	//�������������·����
	int pick2(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = arr.size() - 1; i >= 0; i--)
		{
			ans = ans * 2 + arr[i];
		}
		return ans;
	}
};

int main()
{
	vector<int>arr = {1,3,2,4,5,6,78,8};
	Solution s;
	cout << s.pick(arr) << endl;
	cout << s.pick2(arr) << endl;
	return 0;
}