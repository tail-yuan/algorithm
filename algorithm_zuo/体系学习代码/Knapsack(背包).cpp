#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//到达第i个位置要还是不要这个东西
//i号之后的东西自由选择,形成最大价值返回
//不能超重,否则选择方法无效
class Knapsack
{
public:
	int process(vector<int>& weights, vector<int>& values, int i, int alreadyWeight, int bag)
	{
		if (alreadyWeight > bag)
			return 0;
		if (i == weights.size())
			return 0;
		return max(values[i]+process(weights,values,i+1,alreadyWeight+weights[i],bag),
					process(weights, values, i + 1, alreadyWeight, bag));
	}
};