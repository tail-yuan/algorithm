//有一个正整数数组,求解让累加和<=0的最小代价是多少
//opt1: 什么都不做,代价是0
//opt2: 让数字直接变为0,代价是x
//opt3: 让数字编程相反数,代价是y

//从左到右的尝试模型,arr[i....]之后的累加和为rest时的最小代价是多少
//如果sum很大,这个方式就废了

//贪心:
//1. 目的是让累加和<=0,让某一个数字=0是x代价,变成负数代价是y,如果x>y,完全没必要使用x操作,直接y操作
//目的是让<=0,都是正数,x让sum减小程度小,但是代价高,所以完全没必要.
//2. 肯定是优先使用y,再使用x,再什么都不做 
// 如果x<y,在遇到index位置时就决定不用y操作了,那么之后的所有操作都不应该再使用y了,
//	反证: 既然之后仍然可以使用y操作,那为什么不在累加和更大的时候使用呢?
// 同理,当到达某个位置不再使用x操作时,后面的都不应该再使用x操作了
//现在就到了查找两个index的断点? 暴力找
//这两个断点其实都可以为0,因为可以存在只使用x操作或者只使用y操作
//最后,[1]使用y操作变为负数,[2]使用x操作都变为0,[3]什么都不做,如果[1]的负数和>[3],代价就是[1]*y+[2]*x
//暴力两层循环,包含所有断点尝试情况,一定能找到[1]>[3]的两个断点中最小的代价

//优化:需要满足降序排序,贪心
//起始就是在找[1]>[3]时,[3]的最左节点在哪里,为的就是让[1]产生的负数平掉[3]剩下的正数,
//所以只需要一次遍历,尝试[1]的区间大小,然后查找[3]的后缀和的最左节点,小于等于sum1的[3]区间
//在所有[1]断点的情况中,找到最小的代价即可.
//所以使用后缀和进行优化,二分查找
//[9,6,3,2,2,2,1,1,1]
//case 1: 9采用y操作->-9,2 2 2 1 1 1 累加和为9,那么6 3 直接x操作变为0即可
//case 2: 9 6使用y操作,后面什么都不用干了,
//...
//min_case()
//这样就和数据大小没关系了
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution2
{
public:
	int getMin(vector<int>& arr, int x, int y)
	{
		sort(arr.begin(), arr.end(), greater<int>());//从大到小排序
		int n = arr.size();
		if (x >= y)
		{
			int sum = 0;
			for (auto e : arr)
				sum += e;
			int ret = 0;
			for (int i = 0; i < n && sum>0; i++)
			{
				sum -= 2 * arr[i];
				ret += y;
			}
			return ret;
		}
		else
		{
			//将arr直接改值为后缀和数组
			for (int i = n - 2; i >= 0; i--)
			{
				arr[i] += arr[i + 1];
			}
			int benefit = 0;
			int left = mostLeft(arr,0,benefit);//执行Y操作的数字为0个时
			int cost = left * x;
			for (int i = 0; i < n - 1; i++)
			{
				benefit += arr[i] - arr[i + 1];//因为现在的arr数组时后缀和,获取i位置原值就是相减
				left = mostLeft(arr, i + 1, benefit);
				cost = min(cost, (i + 1) * y + (left - i - 1) * x);//记录所有情况的最小值		
			}
			return cost;
		}
	}
	//在[l,n-1]区间中找到<=val的位置,进行返回
	int mostLeft(vector<int>& arr, int l, int val)
	{
		int n = arr.size();
		int r = n - 1;
		int ans = n;//如果都不满足情况,也就不会被设置,就返回n
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (arr[mid] > val)
				l = mid + 1;
			else
			{
				ans = mid;
				r = mid - 1;
			}
		}
		return ans;
	}
	int mostLeft1(vector<int>& arr, int l, int val)
	{
		int n = arr.size();
		int r = arr.size() - 1;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (arr[mid] > val)
				l = mid + 1;
			else
				r = mid;
		}
		//如果整个范围都是不达标的,返回n
		if (l == n - 1)
			l = n;
		return l;
	}
};
class Solution
{
	int x, y;
	int n;
public:
	int getMin(vector<int>& arr, int _x, int _y)
	{
		x = _x;
		y = _y;
		n = arr.size();
		int sum = 0;
		for (auto e : arr)
		{
			sum += e;
		}
		return zuo(arr, 0, sum);
	}
	int zuo(vector<int>&arr,int index,int rest)
	{
		if (rest <= 0)
			return 0;
		if (index == n)
			return INT_MAX;
		int p1 = zuo(arr, index + 1, rest);
		int p2 = INT_MAX;
		int ret2 = zuo(arr, index + 1, rest - arr[index]);
		if (ret2 != INT_MAX)
			p2 = ret2+x;
		int p3 = INT_MAX;
		int ret3 = zuo(arr, index + 1, rest - 2 * arr[index]);
		if (ret3 != INT_MAX)
			p3 = ret3 + y;
		return min(p1, min(p2, p3));
	}
};
/*
int main()
{
	vector<int>arr{1,4,5,6,0,7,3,2};
	sort(arr.begin(), arr.end(), greater<int>());

	return 0;
}
*/