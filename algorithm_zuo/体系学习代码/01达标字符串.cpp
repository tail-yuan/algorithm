//字符串只由'0'和'1'两种字符构成，
//当字符串长度为1时， 所有可能的字符串为"0"、 "1"；
//当字符串长度为2时， 所有可能的字符串为"00"、 "01"、 "10"、 "11"；
//当字符串长度为3时， 所有可能的字符串为"000"、 "001"、 "010"、 "011"、 "100"、
//"101"、 "110"、 "111"
//...
//如果某一个字符串中， 只要是出现'0'的位置， 左边就靠着'1'， 这样的字符串叫作达
//标字符串。
//给定一个正数N， 返回所有长度为N的字符串中， 达标字符串的数量。
//比如， N = 3， 返回3， 因为只有"101"、 "110"、 "111"达标。

// 1. 暴力尝试 
// 先会出现2^n中字符串,然后每个还需要判断是否达标,最好也是O(N) 整个下来就是O(2^N * N)
// 2. 范围之内推导,然后使用打表法尝试通过
// 
// 3.情景分析为Fib问题,优化之后可为O(logN)级别
//  长度为i的字符串前面一个字符必须是1即 1[长度为i字符串任意拼接]的可能性F,
//  那么想要求得F(8)其实就应该调用F(7),严格潜台词规定打头的必须是1
//	在长度为i的字符串中,第一个位置字符选择有0 1,
//   3.1 如果选择1,那么后续i-1个字符可以任意组合,F(i)=F(i-1)
//   3.2 如果选择0,那么第二个字符必须是1,后续i-2个字符可以任意组合,F(i)=F(i-2)
//  所以F(i)=F(i-1)+F(i-2)=>Fib 数列问题,优化与否决定T(N),最好为log(N)
//

#include<iostream>
#include<vector>
using namespace std;

class ZeroLeftOneStringNumber
{
public:
	int getNum1(int n)
	{
		if (n < 1)
			return 0;
		return process(1, n);
	}
	int process(int i, int n)
	{
		if (i == n - 1)
			return 2;
		if (i == n)
			return 1;
		return process(i+1,n)+process(i+2,n);
	}
	//2. 
	int getNum2(int n)
	{
		if (n < 1)
			return 0;
		if (n == 1)
			return 1;
		int pre = 1;
		int cur = 1;
		int tmp = 0;
		for (int i = 2; i < n - 1; i++)
		{
			tmp = cur;
			cur += pre;
			pre = tmp;
		}
		return cur;
	}
	//3. 
	int getNum3(int n)
	{
		if (n < 1)
			return 0;
		if (n == 1 || n == 2)
			return n;
		vector<vector<int>>base = { {1,1},{1,0} };
		vector<vector<int>>res = matrixPower(base,n-2);
		return 2 * res[0][0] + res[1][0];
	}
	vector<vector<int>>matrixPower(vector<vector<int>>& m, int p)
	{
		vector<vector<int>> res(m.size(),vector<int>(m[0].size()));
		for (int i = 0; i < m.size(); i++)
			res[i][i] = 1;
		
		vector<vector<int>>t = m;
		for (; p != 0; p >>= 1)
		{
			if ((p & 1) !=0)
			{
				res = mulMatrix(res,t);
			}
			t = mulMatrix(t,t);
		}

		return res;
	}
	vector<vector<int>> mulMatrix(vector<vector<int>>& m1, vector<vector<int>>& m2)
	{
		vector<vector<int>>res(m1.size(),vector<int>(m2[0].size()));
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