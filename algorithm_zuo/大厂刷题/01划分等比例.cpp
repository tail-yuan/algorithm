//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=59&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//�ȱ�������,���������[0,x]��01�ı�����a:b
//�������һ�ֻ�����ÿ��С���䶼�ȱ���,��ôÿ��С�����ڵı���Ҳ��a:b
//������Ŀ������[0,i]Ϊǰ׺����������ܹ����ֳ����ٸ��ȱ�����������Ŀ,
//�ؼ�: ������ı���Ϊa:b,��ô���֮ǰ��С�����б�����Ϊa:b��,������ĸ�������,
//����ǰ׺���ֵ������к��Լ���ʱ������ͬ��������Ŀ+�Լ�����
// 
//������֪[0,99]����ʽ3:7,������֪[0,66]��3:7,��ô����[67,99]�еı���Ҳ��3:7
//dp[99]=2+1
//�����֪����[0,56]Ҳ��3:7,��ô[57,66]��ȻҲ��3:7,dp[99]=3+1
// 
//������������,����iλ��ʱ,ʹ�ù�ϣ���¼֮ǰ���仮�ֵõ��ı���,�Լ����Գ��ֵĴ���
//С��������Ƶ����ڽϴ��������,����������key��¼,����ھ�����ʧ,
//����ʹ�����ű�: map<����,map<��ĸ,����/��ĸ�������ִ���>>
//��¼���Ǳ������ִ���,������Ҫ�����ӷ�ĸ�����Լ��,��¼����
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
	vector<int> Ratio01Split(vector<int>&arr)
	{
		unordered_map<int, unordered_map<int, int>>hashMap;
		int n = arr.size();
		vector<int>ans(n);
		int zero = 0;
		int one = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
				zero++;
			if (arr[i] == 1)
				one++;
			//�������һ�����䶼��0����1,��󻮷�ʹ������ȱ�������һ��һ��һ��,��������i+1
			if (zero == 0 || one == 0)
				ans[i] = i + 1;
			else
			{
				int gcd_ret = gcd(zero, one);
				int a = zero / gcd_ret;
				int b = one / gcd_ret;
				if (hashMap.count(a) == 0)
					hashMap.insert({a,unordered_map<int,int>()});
				if (hashMap[a].count(b) == 0)
					hashMap[a].insert({b,1});
				else
				{
					hashMap[a][b]++;
				}
				ans[i] = hashMap[a][b];
			}
		}
		return ans;
	}
	//ŷ������㷨�Ļ���˼����: �������������� a ��6������ a > b��
	// gcd(a,b) (���Լ��) ����gcd(b,a mod b)
	//����� a mod b��a ����6������
	//�����Ĺ���ԭ������
	//1. ���6 = 0����ôa �������Լ�������ǵݹ�Ļ������
	//2.���򣬵ݹ���� gcd(b, a mod 6)��
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);      
	}
};