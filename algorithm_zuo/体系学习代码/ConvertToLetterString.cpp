#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//�涨1��A��Ӧ�� 2��B��Ӧ�� 3��C��Ӧ...
//��ôһ�������ַ�������"111"�� �Ϳ���ת��Ϊ"AAA"�� "KA"��"AK"��
//����һ��ֻ�������ַ���ɵ��ַ���str�� �����ж�����ת�������




//������ʵ������,[1,i-1]λ��,[i]�����ַ����Ϊ...
// [i]+zuo[i+1,...],
// a: i�Լ�ת�� + ����[i+1]�����ڵ�ת������
// a: pairr<i,i+1>ת�� + ����[i+2]�����ڵ�ת������
// 
//���[i]�����ַ�����3��9,��ôֻ���Լ�ת��Ϊ��Ӧ��ĸ,�޷�ʵ�ֺͺ���һ���ַ����->һ����ĸ
//���[i]�����ַ���1,��ôa.����ת��Ϊ������ĸ b. ���Ժͺ�һ�����pair->��ĸ =>�������a+b
//���[i]�����ַ���2,�ж�[i+1]λ����������Ƿ�>26,�پ�����a+b ���ǵ���һ��a

//���iλ���Ѿ��������,˵������֮ǰѡ�������һ��������Ч�Ľ��,return 1
//���[i]==0,˵��֮ǰ��ת�������������λ���޷�ת������ĸ,���⿪ʼ֮���޷�ת��Ϊ,return 0
class ConvertToLetterString
{
public:
	int process(string& str, int i)
	{
		if (i == str.size())
			return 1;
		if (str[i] == '0')
			return 0;
		if (str[i] == '1')
		{
			int res = process(str,i+1);
			if (i + 1 < str.size())
				res += process(str,i+2);
			return res;
		}
		if (str[i] == '2')
		{
			int res = process(str, i + 1);
			if (i + 1 < str.size() && (str[i] >= '0' && str[i] <= '6'))
				res += process(str, i + 2);
			return res;
		}
		//3<=str[i]<=9,ֻ���Լ��μ�ת��
		return process(str,i+1);
	}
};