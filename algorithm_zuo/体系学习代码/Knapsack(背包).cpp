#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//�����i��λ��Ҫ���ǲ�Ҫ�������
//i��֮��Ķ�������ѡ��,�γ�����ֵ����
//���ܳ���,����ѡ�񷽷���Ч
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