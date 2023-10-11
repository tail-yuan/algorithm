//在一个矩阵中,只存在01两种数字,1代表的是人
//想要求解的是将所有的人汇聚到一点开会时付出的最小代价是多少
//每个人只能横着或者竖着走,并且每走一个格子付出的代价是1


//题解:
//因为只能上下左右走,确认到某一位置转化为确认到某一行,某一列,交汇出一个点就是所求最小代价点
//先考虑行,找到所有行中1汇聚到某一行时的最小代价时的行,
//再考虑列,找到将所有列汇聚到某一列时的最小代价的列,交点即所求
//过程中统计移动的1的个数
// 
//那么如何查找是哪行哪一列呢? 查找的过程其实就是排除的过程,
//我们可以假设全移动到x行代价是sumx,全移动到另外一行代价是sumy,如果sumx>sumy,既可以
//排除x行肯定不是所求.
// 
//思想了解,那么怎么将其余行上的1,全部移动到x行计算代价呢?
//x行将矩阵分为了上下两个部分,上部分所有的累加的1的个数up,下部分所有的累加1的个数是down
//看做整体移动到x只需要,up+down和每层移动时都要加上的值
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?t=578.4&p=66

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int BestMeetingPoint(vector<vector<int>>& arr)
	{
		int n = arr.size();
		int m = arr[0].size();
		vector<int>iOnes(n);
		vector<int>jOnes(m);
		//统计i行,j列分别多少个1
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					iOnes[i]++;
					jOnes[j]++;
				}
			}
		}
		int total = 0;
		int i = 0;
		int j = n - 1;
		int iRest = 0, jRest = 0;
		while (i < j)
		{
			if (iOnes[i] + iRest <= iOnes[j] + jRest)
			{
				total += iOnes[i] + iRest;
				iRest += iOnes[i++];
			}
			else
			{
				total += iOnes[j] + jRest;
				jRest += iOnes[j--];
			}
		}
		i = 0; j = m - 1;
		iRest = 0, jRest = 0;
		while (i < j)
		{
			if (jOnes[i] + iRest <= jOnes[j] + jRest)
			{
				total += jOnes[i] + iRest;
				iRest += jOnes[i++];
			}
			else
			{
				total += jOnes[j] + jRest;
				jRest+=jOnes[j--];
			}
		}
		return total;
	}
};