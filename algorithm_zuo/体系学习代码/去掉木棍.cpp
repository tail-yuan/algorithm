#include<iostream>
#include<vector>
using namespace std;
// ҵ����
// ����֮��,��i��λ��ǰ����ľ��������>[i]�������������,��ô���������ɹ�,����sum<=i
// ����֤��:ȷ������=iʱ�ܹ�ȥ�����ٵ�ľ��,��Fib������N��Χ������Щ,������Ҫȡ����ľ�� 
// ʣ�µĶ����γ�������

class DeleteWood
{
public:
	int minDelete(int m)
	{
		if (m < 4)
			return 0;
		int k2 = 2;
		int k1 = 3;
		int num = 3;
		while (k2 + k1 <= m)
		{
			num++;
			k1 += k2;    // k1�����һλ
			k2 = k1 - k2;//k2=k1 k2������
		}
		return m - num;
	}
};
// 1 2 3 5 8 13 21 ... ���m=17,ֻ��Ҫȥ��1 2 3 5 8