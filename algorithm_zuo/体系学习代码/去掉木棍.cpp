#include<iostream>
#include<vector>
using namespace std;
// 业务题
// 排序之后,第i个位置前两根木棍加起来>[i]才能组成三角形,那么不想让他成功,就让sum<=i
// 经过证明:确定条件=i时能够去掉最少的木棍,即Fib数列在N范围内有哪些,就是需要取出的木棍 
// 剩下的都能形成三角形

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
			k1 += k2;    // k1向后走一位
			k2 = k1 - k2;//k2=k1 k2跟上来
		}
		return m - num;
	}
};
// 1 2 3 5 8 13 21 ... 如果m=17,只需要去掉1 2 3 5 8