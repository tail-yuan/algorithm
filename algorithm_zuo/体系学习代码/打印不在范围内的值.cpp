//����һ����������A������Ϊn���� 1 <= A[i] <= n���Ҷ���[1,n]�����������в����������ظ����ֶ����ֲ�����֡�
//ʵ���㷨�ҵ�[1, n]������δ������A�е�������
//��ʾ������ʵ��O(n)��ʱ�临�ӶȺ�O(1)�Ŀռ临�Ӷȣ�����ֵ������ռ临�Ӷȣ���
//����������
//һ�����֣�ȫ��Ϊ�������ո�ָ�
//A0 A1 A2 A3... ���������
//һ�����֣�ȫ��Ϊ�������ո�ָ�R0 R1 R2 R3... ʾ��1:
//����
//1 3 4 3
//���
//2
// 
//˼·:����ʵ���±�Ϊi��λ��֮�ϱ�����i+1���ֵ,���iλ�ò���i+1,��˵��i+1����ȱʧ���Ǹ�ֵ

#include<iostream>
#include<vector>
using namespace std;


class printNumNoInArray
{
public:
	void printNumberNoInArray(vector<int>& arr)
	{
		if (arr.size() == 0)
			return;
		for (auto e : arr)
		{
			modify(e,arr);//��e�ŵ�e-1��λ����ȥ
		}
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] != i + 1)
				cout << i+1 << endl;
	}
	void modify(int value, vector<int>& arr)
	{
		while (arr[value - 1] != value)
		{
			int tmp = arr[value - 1];
			arr[value - 1] = value;
			value = tmp;
		}
	}

};