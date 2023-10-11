//���:
//һ��������ֻ�������ַ�G�� B���������е�G��������࣬
//���е�B�������Ҳ���߿��������е�G�������Ҳ࣬���е�B���������
//����ֻ���������ַ�֮����н�����������������Ҫ��������
//���:
//�����G��������������,��ôʹ������ָ�����ָ��,left ,index
//�������B,index++,������һ��G,��Ϊֻ�ܺ�����λ�ý���,���Դ�����index-left��
//��ʱһ�����Ѿ�����һ��G���ú���,��һ��G�϶����ڵڶ���λ��,left++;
//̰��: �����Gû��Ҫ�ǵý�����ǰ��G��ǰ��,ʵ�����ٵ�˼��.
// ͬ����B������������,����������Сֵ
//����ָ�붼������,O(N)
#include<iostream>
using namespace std;
class Solution
{
public:
	int minStep(string& str)
	{
		int left = 0, index = 0;
		int step1 = 0, step2=0;
		int n = str.size();
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'G')
				step1 += (index-left),left++;
			if (str[i] == 'B')
				step2 += (index - left),left++;
		}
		return min(step1, step2);
	}
};