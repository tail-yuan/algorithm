//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=57&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//����һ������Len����ʾһ���м�λ�����ַ�����Сд(a~z)��
// �������ɳ���Ϊ1������Ϊ2����Ϊ3...����Ϊlen�������ַ���
// ����������ַ��������ֵ�������
// ÿ���ַ����������ڵ�λ�ø���һ���ַ���str������len��
// �뷵��str���������еĵڼ���
// ����len = 4���ֵ����ǰ�����ַ���Ϊ:
// a aa aaa ... aaaz .... azzz 
// b ba baa baaaa aa aaa aaaa aaab ... aaaz ..... bzzz ...c...
// a����������еĵ�1����bzzz����������еĵ�36558��
//��������ַ���str=cdb,�������ǳ���len=7�����п����ַ����еڼ���(���ֵ�������)
//��a,bΪ��ͷ,ʣ�³���Ϊ0~6�����п�����sum(a,b)+��c��ͷ,ʣ�³���Ϊ0�Ŀ�����c=1
//��Щ�������cdb�ֵ���֮ǰ,ʣ��db��δ�õ�����,����...
// ��ͷΪcaʣ�³���Ϊ0~5�����п����Լ׸�,��cb��ͷ���Ҹ�,��cc��ͷ�ı���,��cd��ͷ��1��
//����,��cdaΪ��ͷ,ʣ�³���Ϊ0~4�������п����Զ���,��λ�˴�ʱ.
//����: �������ַ�ch��ͷʣ�³���Ϊ0~n�����п����Ժ�Ϊ 1+26^2+26^3+26^4+...+26^n
//�ṩ�������f(n)


#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int f(int n)
	{
		int ans = 1;
		for (int i = 1, base = 26; i <= n; i++, base *= 26)
			ans += base;
		return ans;
	}
	int stringKth(int len, string& str)
	{
		if (str.size() == 0 || str.size() > len)
			return 0;
		int ans = 0;
		for (int i = 0, rest = len - i; i < str.size(); i++, rest--)
		{
			//�м���0~rest��Щ���,f������˭��ͷ
			ans += (str[i] - 'a') * f(rest) + 1;
		}
		return ans;
	}
};
