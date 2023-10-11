// ������Ѷ
// ����һ��ֻ��0��1��ɵ��ַ���S�������±��1��ʼ��
// �涨iλ�õ��ַ���ֵV[i]���㷽ʽ���� : 
// 1) i == 1ʱ��V[i] = 1
// 2) i > 1ʱ�����S[i] != S[i-1]��V[i] = 1
// 3) i > 1ʱ�����S[i] == S[i-1]��V[i] = V[i-1] + 1
// ���������ɾ��S�е��ַ�����������S������ֵ
// �ַ�������<=5000

//00000000011000000: Ϊ�˻������ֵ,���м�����11ɾ��
//0011111111100: ��������м���һ��1
//������ģ��,����iλ��ʱ�Ǳ�������ɾ��,iλ�ò���֮ǰ���Ӱ��
//���������iλ�õı���ɾ���Ǹ���ǰ������������,
//�ܵ�ǰһ������� ������ �ַ� lastNum �Լ�����ֵval������

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int addVal(string& str)
	{
		if (str.size() == 0)
			return 0;
		return process(str,0,'0', 0);
	}
	//index [0,5000] lastch 2��0 1  val: max=5000
	//5000 *2 *5000 = 5*10^7 <10^8 �ع� 
	int process(string& str, int index, char lastCh, int val)
	{
		if (index == str.size())
			return 0;
		int curVal = str[index] == lastCh ? (val + 1) : 1;
		//1. ����indexλ��
		int next1 = process(str,index+1,str[index],curVal);
		//2. ����indexλ��
		int next2 = process(str, index + 1, lastCh, val);
		return max(curVal+next1, next2);
	}
};