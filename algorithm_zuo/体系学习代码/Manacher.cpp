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
			res[i] = (i & 1) == 0 ? gap : str[index++];//res的奇数位添加gap
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
		int R = -1;		//代表的是理论右边界的下一个位置(方便长度求解直接-就行)
		int maxLen = INT_MIN;
		for (int i = 0; i != res.size(); i++)
		{
			//求i位置至少不用求的回文长度
			// R>i:说明i不在右边界里面,直接扩就行,至少是1(自身)
			// PArr[2*C-i]:i在R里面,对称点i'范围都在[L,R]内,pArr[i]=pArr[i'],即便是压线,至少不用求的长度也是他
			// R-i:说明i的范围不在[L,R]左边界更靠左,pArr[i]=R-i就这个范围.
			// 以综合得出最小值即可
			pArr[i] = R > i ? min(pArr[2*C-i],R-i):1;
			while (i + pArr[i]<res.size() && i - pArr[i]>-1)//范围允许向两边扩
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