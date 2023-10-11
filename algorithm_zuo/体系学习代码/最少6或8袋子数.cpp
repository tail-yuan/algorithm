#include<iostream>
#include<vector>
using namespace std;
//1. 贪心的方式,
// 先获取8能使用的最大数量,判断rest是否能用6装,不能的话少用一个8的,再判断
// 直到使用8的袋子为0,或者中间有一个解可以使用6装完成.
// 优化:如果减少8袋子过程中,rest>24只用6搞定时,完全可以用8搞定,此时即可退出,因为肯定不能用6完成 
// O(1) 因为rest用不了几次就会跳出循环
//2. 入int 返回int ->打表法
//根据1结果使用对数器,打印结果,找寻规律,然后总结,直接返回,效率一定是最高的.
class minBags
{
public:
	int minBagBase6(int rest)
	{
		return rest % 6 == 0 ? rest / 6 : -1;
	}
	int minBags1(int apple)
	{
		if (apple < 0)return -1;
		int bag6 = -1;
		int bag8 = apple / 8;
		int rest = apple - bag8 * 8;
		while (bag8 >= 0 && rest<24)
		{
			int resUse6 = minBagBase6(rest);
			if (resUse6!=-1)
			{
				bag6 = resUse6;
				break;
			}
			rest = apple - (--bag8) * 8;
		}
		return bag6 == -1 ? -1 : bag6 + bag8;
	}
	void test()
	{
		for (int i = 0; i < 100; i++)
		{
			cout << i << " " << minBags1(i) << ":" << minBags2(i) << endl;
		}
	}
	int minBags2(int apple)
	{
		if (apple % 2 == 1)
			return -1;
		if (apple < 18)
		{
			return apple == 0 ? 0 : (apple == 6 || apple == 8 ? 1 :
				apple == 12 || apple == 16 ? 2 : -1);
		}
		return (apple - 18) / 8 + 3;
	}
};
//int main()
//{
//	minBags mb;
//	mb.test();
//}