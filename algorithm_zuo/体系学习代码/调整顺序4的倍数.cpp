#include<iostream>
#include<vector>
using namespace std;
//����һ������arr�����ͨ��������������arr�������������ڵ����������4�ı�����
//����true��������ܷ���false

//ͳ�Ƹ��� 1. ��������a 2.ֻ����2���ӵĸ���b 3. ֻ����4���ӵı���c
// ���b==0, ˳��Ӧ���� �� 4 �� 4 �� 4 , a==1ʱ,c>=1 a>1ʱ,c>=a-1 ���� ��4�����ٰ���һ��
// ���b!=0, ˳��Ӧ����22222224��4��4�� ,��Ϊb���ܲ���ż����,���һ��Ӧ�ú�һ��4���
// a=0,c>=0 a=1,c>=1 a>1,c>=a
// c>=a
class nearMultiple4Times
{
public:
	bool isTrue(vector<int>&arr)
	{
		int fourTimes = 0, onlyTwoTimes = 0, odds = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 2 != 0)
				odds++;
			else
			{
				if (arr[i] % 4 == 0)
					fourTimes++;
				else
					onlyTwoTimes++;
			}
		}
		//return evenExpFourTimes == 0 ? (fourTimes + 1 >= odd) : (evenExpFourTimes >= odd);
		return onlyTwoTimes == 0 ? (fourTimes + 1 >= odds) : (fourTimes>=odds);
	}
};