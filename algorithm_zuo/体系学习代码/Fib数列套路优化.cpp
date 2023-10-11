#include<iostream>
#include<vector>
using namespace std;
//推演板书 https://image-1309381344.cos.ap-nanjing.myqcloud.com/img/image-20230709123015746.png
//矩阵相乘板书 https://image-1309381344.cos.ap-nanjing.myqcloud.com/img/image-20230709123055916.png

class Fib
{
public:
	int getFibN(int n)
	{
		if (n < 1)
			return 0;
		//根据Fib数列算出base数组
		vector<vector<int>>base = {
			{1,1},
			{1,0}
			};
		vector<vector<int>>  res = matrixPower(base,n-2);
		return res[0][0]+res[1][0];
	}
	vector<vector<int>> matrixPower(vector<vector<int>>& base, int n)
	{
		vector<vector<int>>res(base.size(),vector<int>(base[0].size()));
		//对角线设置为1 作为相乘的基底
		for (int i = 0; i < base.size(); i++)
			res[i][i] = 1;

		vector<vector<int>> t = base;
		for (; n != 0; n >>= 1) 
		{
			if ((n & 1) != 0)
			{
				res = mulMatrix(res,t);//
			}
			t=mulMatrix(t,t);
		}
		return res;
	}
	//两个正方形矩阵相乘 O(1)
	vector<vector<int>> mulMatrix(vector<vector<int>>& m1, vector<vector<int>>&m2)
	{
		vector<vector<int>>res(m1.size(), vector<int>(m2[0].size()));
		for (int i = 0; i < m1.size(); i++)
		{
			for (int j = 0; j < m2[0].size(); j++)
			{
				for (int k = 0; k < m2.size(); k++)
				{
					res[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
		return res;
	}
};
// 有严格公式+没有递推转移,都可以用Fib套路优化为log(N)
// 
// 初始有一头成熟母牛
// 母牛经过三年时间成熟,在第四年开始生新的母牛
//过程中母牛是不会死的
//问在第n年一共有多少头母牛
// 牛的数量:1 2 3 4 6 9...
// 天数     1 2 3 4 5 6...
// 因为牛是三年时间成熟,第n天的牛的数量等于一直活过来的前一年的牛量+三年之前的牛的数量
// F(N)=F(N-1)+F(N-3)
// 所以可以转化为3阶行列式 3*3的矩阵
// ...
// F(N)F(N-1)F(N-2)= |F(3)F(2)F(1)|* |3*3的矩阵|^(n-3)
// 优化为log(N)水平


//初始有一头成熟兔子
// 母牛经过三年时间成熟,在第四年开始生新的兔子,一回生俩
//过程中兔子是不会死的
//问在第n年一共有多少头兔子
// F(N)=F(N-1)+2*F(N-2) =>pick N-2 , 
// 2*2阶矩阵=>F(N)F(N-1)=|F(2)F(1)|*|2*2阶矩阵|^(n-2)
//如果再添加5年寿命
// F(N)=F(N-1)+2*F(N-2)-F(N-5) =>pick N-5 , 
// 5*5阶矩阵=>F(N)F(N-1)F(N-2)F(N-3)F(N-4)=|F(5)F(4)F(3)F(2)F(1)|*|2*2阶矩阵|^(n-5)