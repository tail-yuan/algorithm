//4399����
//һ����,��ŷֱ���1~31
//����ץһ��,Ϊ�����������ַ����ִ�������һ��,�����ٷŻض��ٸ���

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int>Func(string& str)
{
	char* tmp = new char[str.size() + 1];
	strcpy(tmp, str.c_str());
	char* cur = strtok(tmp, ",");
	vector<int>ans;
	while (cur != NULL)
	{
		ans.push_back(atoi(cur));
		cur = strtok(NULL, ",");
	}
	delete[]tmp;
	return ans;
}
int return_nums(vector<int>& arr)
{
	//1. �ȶ����ֽ��д�Ƶͳ��
	vector<int>cnts(31,0);
	for (int i = 0; i < arr.size(); i++)
		cnts[arr[i]]++;
	//����else����ʽ�����������,����ֻ����һ��ʱ,nums�ж���1,��Ҫ����,����Ҫ�Ż�
	bool flag = true;
	for (int i = 0; i < cnts.size(); i++)
	{
		if (cnts[i] != 0 && cnts[i] != 1)
			flag = false;
	}
	if (flag)
		return 0;
	else
	{
		//2. ������ͬ�Ļ�Ϊһ��,ͳ������
		vector<int>nums;
		for (int i = 0; i < cnts.size(); i++)
		{
			if (cnts[i] != 0)
				nums.push_back(cnts[i]);
		}
		//3. ���ֻ��Ҫʵ��nums�е�ȥ�ز���,����ȥ��.nums�����ֶ���һ��,����ÿ���ַ����ִ�����ͬ
		unordered_set<int>hashSet;
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			while (hashSet.count(nums[i]) != 0)
			{
				--nums[i];
				count++;
			}
			//��-��0,����û�����������,�Ͳ��ŵ�hashSet����
			if (nums[i] != 0)
				hashSet.insert(nums[i]);
		}
		return count;
	}
}
//int main()
//{
//	string str;
//	cin >> str;
//	vector<int>arr = Func(str);
//	int ret = return_nums(arr);
//	cout << ret << endl;
//	return 0;
//}