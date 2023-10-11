#include<iostream>
using namespace std;
//���ݷ�Χ��������Լ��,���������·����Ҫ
// -183~182 �ж��Ƿ����ת�� minq=-18 minr=-3
class Convert
{
public:
	//��������������дϰ�ߵĲ�����Ч��
	//1. ���ܵ�дһ�� - ;- �����һ��������0; ���־��������м䲻�ܳ�����ĸ
	//2. д���ִ�ͷ�Ĳ�����0
	// 
	//ʹ�ø�������,��Ϊ������������һ��
	//-2147483648 2147483647
	// 
	bool isValid(string& str)
	{
		if (str[0] != '-' && (str[0] < '0' || str[0]>'9'))
			return false;
		if (str[0] == '-' && (str.size() == 1 || str[1] == '0'))
			return false;
		if (str[0] == '0' && str.size() > 1)
			return false;
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i]>'9')
				return false;
		}
		return true;
	}
	int convert(string& str)
	{
		if (str.size() == 0)
			return 0;
		if (!isValid(str))
			return 0;
		bool flag = str[0] == '-' ? true : false;
		
		//ƴ�ӹ������ж�Խ���õ�
		int minq = INT_MIN / 10;
		int minr = INT_MIN % 10;

		int res = 0;
		int cur = 0;
		for (int i = flag ? 1 : 0; i < str.size(); i++)
		{
			cur = '0' - str[i];
			//res��*10�ͻ�Խ�� || res*10���õ���,����������С+��Ҳ��Խ��
			if (res < minq || (res == minq && cur < minr))
				return 0;
			res = res * 10 + cur;
		}
		if (flag && res == INT_MIN)//-2147483648�޷�ת��Ϊ����
			return 0;

		return flag ? res : -res;
	}
};