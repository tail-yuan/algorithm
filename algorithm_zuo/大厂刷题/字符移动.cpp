//题干:
//一个数组中只有两种字符G和 B可以让所有的G都放在左侧，
//所有的B都放在右侧或者可以让所有的G都放在右侧，所有的B都放在左侧
//但是只能在相邻字符之间进行交换操作返回至少需要交换几次
//题解:
//如果让G都放在区间的左边,那么使用两个指针变量指向,left ,index
//如果遇到B,index++,遇到第一个G,因为只能和相邻位置交换,所以次数是index-left次
//此时一定是已经将第一个G安置好了,下一个G肯定放在第二个位置,left++;
//贪心: 后面的G没必要非得交换到前面G的前面,实现至少的思想.
// 同理让B放在区间的左边,两种情况求较小值
//两个指针都不回退,O(N)
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