// 小明手中有n块积木，并且小明知道每块积木的重量。现在小明希望将这些积木堆起来
// 要求是任意一块积木如果想堆在另一块积木上面，那么要求：
// 1) 上面的积木重量不能小于下面的积木重量
// 2) 上面积木的重量减去下面积木的重量不能超过x
// 3) 每堆中最下面的积木没有重量要求
// 现在小明有一个机会，除了这n块积木，还可以获得k块任意重量的积木。
// 小明希望将积木堆在一起，同时希望积木堆的数量越少越好，你能帮他找到最好的方案么？

//题解:
//既然搭积木的时候从下往上的规定是从小到大,并且之间差值不能超过x
//那么就可以直接排序原数组,从小到大去拿取原数组中的值,
//贪心1: 
//既然要的是最少的搭建的积木总数,那么就没有必要在还满足差值不超过x时,不将index位置积木
//紧挨着前面的放,而是去新起一个头去搭积木.
//	因为首先你这样做虽然合法,但是新建了一个头,导致总的积木累积块增加,后序你还得去合并,没必要
//	另外,因为数组是排过序的,你新起来一个头,就可能导致第二个到你这的积木和你的差值变大,导致违法的可能性增加
//这样做之后,我们可以得到从一个头开始,最好能分成几堆,并且每一堆都是合法的
//然后就需要合并,
//贪心2:
//我们选择能连在一起差值相差最小的两堆,优先进行使用k个随意数字合并操作
//1. 因为任意两个堆之间的合并带来的收益是一样的,都减少了一个堆.题目所求是最小堆数
//2. 用最少的随机积木解决了同样的问题,何乐而不为.
//那么如何求解两个积木堆之间合并所需要的最少的随机积木数量?差值是s
// a/b向上取整 == (a+b-1)/b向下取整的结果
// 求解两块区域相连时至少需要几块可变积木时,差值 (s-x)/x向上取整即为至少所需块数,
// -> (s-x)/x = ((s-x)+x-1)/x = (s-1)/x

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int minSplit(vector<int>& arr,int k,int x)
	{
		sort(arr.begin(), arr.end());
		//寻找出有几堆,然后堆之前的差值是多少
		int n = arr.size();
		vector<int>needs(n,0);
		int sz = 0;
		int split = 1;//至少是一堆
		for (int i = 1; i < n; i++)
		{
			if (arr[i] - arr[i - 1] > x)//一堆放不下,新起一堆
			{
				needs[sz++] = arr[i] - arr[i - 1];
				split++;
			}
		}
		//走完循环也合法;差值是0,两堆之间无法合并;没有魔法积木可以使用
		if (split == 1 || x == 0 || k == 0)
			return split;
		//优先选择差值较小的合并
		sort(needs.begin(), needs.begin() + sz);
		for (int i = 0; i < sz; i++)
		{
			int need = (needs[i] - 1) / x;
			if (k >= need)
			{
				split--;
				k -= need;
			}
			else
				break;
		}
		return split;
	}
};
//不需要考虑之前的积木分到了哪堆,因为对我这次选择不影响
//从左到右尝试模型
//到达i位置时,如果个i+1位置差值<x,那么一定粘合在一堆
//如果差值>x,要么我就直接新起一堆,要么使用魔法积木把他合并到一堆
//zuo()返回的就是最小堆数
class Solution2
{
public:
	//rest: k
	int minSplit(vector<int>& arr, int k, int x)
	{
		return zuo(arr, k, x, 0);
	}
	int zuo(vector<int>&arr,int rest,int x,int index)
	{
		if (index == arr.size())
			return 1;
		if (arr[index + 1] - arr[index] <= x)
			return zuo(arr, rest, x, index + 1);
		else
		{
			int p1 = 1 + zuo(arr, rest, x, index + 1);
			int p2 = INT_MAX;
			int need = (arr[index + 1] - arr[index] - 1) / x;
			if (rest > need)
				p2 = zuo(arr, rest - need, x, index + 1);
			return min(p1, p2);
		}
	}

};