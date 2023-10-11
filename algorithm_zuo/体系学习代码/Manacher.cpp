#include<iostream>
#include<vector>
using namespace std;
class Manacher
{
public:
	string manacherString(string& str)
	{
		string res;
		int index = 0;
		char gap ='#';
		for (int i = 0; i!=2*str.size()+1; i++)
		{
			res[i] = (i & 1) == 0 ? gap : str[index++];//res������λ���gap
		}
		return res;
	}
	int maxLcpsLength(string& str)
	{
		if (str.size() == 0)
			return;
		string res = manacherString(str);
		vector<int>pArr(res.size());
		int C = -1;
		int R = -1;		//������������ұ߽����һ��λ��(���㳤�����ֱ��-����)
		int maxLen = INT_MIN;
		for (int i = 0; i != res.size(); i++)
		{
			//��iλ�����ٲ�����Ļ��ĳ���
			// R>i:˵��i�����ұ߽�����,ֱ��������,������1(����)
			// PArr[2*C-i]:i��R����,�ԳƵ�i'��Χ����[L,R]��,pArr[i]=pArr[i'],������ѹ��,���ٲ�����ĳ���Ҳ����
			// R-i:˵��i�ķ�Χ����[L,R]��߽������,pArr[i]=R-i�������Χ.
			// ���ۺϵó���Сֵ����
			pArr[i] = R > i ? min(pArr[2*C-i],R-i):1;
			while (i + pArr[i]<res.size() && i - pArr[i]>-1)//��Χ������������
			{
				if (res[i + pArr[i]] == res[i - pArr[i]])
					pArr[i]++;
				else
					break;
			}
			if (i + pArr[i] > R)
			{
				R = i + pArr[i];
				C = i;
			}
			maxLen = max(maxLen, pArr[i]);
		}
		return maxLen - 1;
	}
};