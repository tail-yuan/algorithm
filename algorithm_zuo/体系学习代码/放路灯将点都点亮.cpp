#include<iostream>
using namespace std;
//���: �ַ�����ֻ��. ��X �����ַ�,X �������ǽ,Ҫ�뽫���еĵ�ȫ������,����Ҫ���ٸ���.ÿ����ֻ��Ӱ������������λ��
//˼·: 1. ���iλ����X,����Ҫ��,index++
//		2. ���iλ����.,�϶�Ҫ�ŵ�,index�ı仯��Χ�����ŵ�������
//			2.1 ���i+1λ����X,��ô��iλ�þͷŵ�,index+=2
//			2.2 ���i+1λ����.����i+1λ�÷ŵ�,̰�ĵ��뷨,i+1λ�þͿ���Ӱ��i i+1 i+2 ����λ��,Ӱ�췶Χ������,index+=3
//������iλ��ʱ,һ����֤֮ǰ�ĵƲ���Ӱ�쵽iλ��(��Ҫ�����Լ����λ���Ƿ��Ѿ�������).index�±귶Χ����
class LightPoints
{
public:
	int getMin(string& str)
	{
		if (str.size() == 0)return 0;
		int ans = 0;
		int index = 0;
		while (index < str.size())
		{
			if (str[index] == 'X') index++;
			else
			{
				ans++;
				if (index + 1 == str.size())break;
				else
				{
					if (str[index + 1] == 'X') index += 2;
					else if (str[index + 1] == '.') index += 3;//̰��,��i+1λ�÷ŵ�,�������ٵ���
				}
			}
		}
		return ans;
	}
};