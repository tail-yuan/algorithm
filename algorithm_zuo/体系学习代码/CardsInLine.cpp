#include<iostream>
#include<string>
#include<vector>
using namespace std;

//二人交替拿,我先手拿完一个,那么剩下的部分就是我作为后手拿的
class CardsInLine
{
public:
	int win1(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		return max(f(arr,0,arr.size()-1),s(arr,0,arr.size()-1));
	}
	//先手,选i位置,剩下[i+1,j]区间是作为后手选,选j位置剩下[i,j-1]位置,选出二者最大值
	int f(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return arr[i];
		return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}
	//后手选剩一个的话,可能没得选了,就0
	//剩下的就是先手选完的,肯定是较小值
	int s(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return 0;
		return min(f(arr,i+1,j),f(arr,i,j-1));
	}
};