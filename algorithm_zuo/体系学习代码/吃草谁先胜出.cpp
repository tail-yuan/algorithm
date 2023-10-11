#include<iostream>
#include<vector>
using namespace std;

//每次选择吃4的次方份数的草,谁先吃完谁就获胜
//1. 打表法
// 0~4之间需要自行判断,之后,从第一次吃16份开始尝试,如果存在我赢就是我赢,否则尝试吃的已经>n都没有我赢就是输
//
class Eat
{
public:
	string winner1(int n)
	{
		// 0  1  2  3  4 
		// 后 先 后 先 先
		if (n < 5)
			return (n==0 || n == 2) ? "后手" : "先手";
		int base = 1;
		while (base <= n)
		{
			if (winner1(n - base) == "后手")//递归调用子过程,如果子过程返回后手赢其实就是主过程的先手赢
				return "先手";
			if (base > n/4)//避免base*4 >INT_MAX越界
				break;
			base *= 4;
		}
		return "后手";
	}
	void test()
	{
		//规律是后先后先先
		for (int i = 0; i <= 50; i++)
		{
			//cout << i << " " << winner1(i) << endl;
			cout << i << " " << winner1(i)<<":"<<winner2(i) << endl;
		}
	}
	string winner2(int n)
	{
		if (n % 5 == 0 || n % 5 == 2)
			return "后手";
		else
			return "先手";
	}
};
//int main()
//{
//	Eat e;
//	e.test();
//}