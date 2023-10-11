#include<iostream>
#include<vector>
using namespace std;
class NetherlandsFlag
{
public:
	//1. [i]<num [i]和less区间右边的数字交换,less区间右扩,i++
	//2. [i]>num [i]和more区间左边的数字交换,more区间左扩,i不变,因为此时i位置值是刚交换过来的,还不知道是啥值
	//3. [i]==num[i],i++即可,不做交换处理
	//动态观察就是less区间推着==区间向右挤压待定区域接近more区间,反之亦然.
	//如何推?相等区间最左(右)边值和[i](<num)交换,然后i++,实现的,反之亦然.
	pair<int,int> partition(vector<int>& arr,int l,int r,int p)
	{
		int less = l-1;
		int more = r + 1;
		while (l<more)
		{
			if (arr[l] < p)
			{
				swap(arr[l], arr[less + 1]);
				less++;
				l++;
			}
			else if (arr[l] > p)
			{
				swap(arr[l], arr[more - 1]);
				more--;
			}
			else
			{
				l++;
			}
		}
		return std::make_pair(less+1,more-1);//返回中间=区域的左边界和右边界
	}
};