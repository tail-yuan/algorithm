#include<iostream>
#include<vector>
#include<list>
using namespace std;
//best
class Solution
{
public:
	int getPrefixCount(int n, long long cur, long long next)
	{
		int ret = 0;
		while (cur <= n)
		{
			long long p1 = next - cur;//往下逼近n时,发现以cur为前缀的一层数都小于n,个数获取就是[cur,next)的next-cur个;
			long long p2 = n + 1 - cur;   //往下逼近n时,发现以cur为前缀的一层数中存在n,即cur<n<next,小于n的个数,这一层即[cur,n]的个数就是n+1-cur;
			ret += min(p1, p2); //把每一层以cur为前缀并且小于n的值的个数加起来
			//往下逼近,就是向后面补0操作
			cur *= 10;
			next *= 10;
		}
		return ret;
	}
	int findKthNumber(int n, int k)
	{
		long long  cur = 1;
		k--;
		while (k>0)
		{
			int num = getPrefixCount(n, cur, cur + 1);//获取以cur为前缀,并且数都小于n的个数
			if (num < k)
			{
				cur++;
				k -= num;
			}
			else
			{
				cur *= 10;
				k--;
			}
		}
		return cur;
	}
};
//chatgpt
class Solution
{
public:
	/*`countSteps` 函数的作用是计算在当前前缀范围内（从 `first` 到 `last - 1`，左闭右开区间），有多少个整数。

	在字典序遍历的过程中，我们需要计算当前前缀范围内的整数个数，
	以便判断是否需要继续在当前前缀范围内查找下一个字典序整数，或者需要移动到下一个前缀。
	通过计算当前前缀范围内的整数个数，我们可以判断是否能够继续在当前前缀内查找，或者需要跳到下一个前缀。
	`countSteps` 函数接受三个参数：
	- `n`：整数的上限，我们需要找到所有小于等于 `n` 的整数。
	- `first`：当前前缀的起始整数，即当前前缀的最小值。
	- `last`：当前前缀的下一个前缀的起始整数，即下一个前缀的最小值。
	函数的返回值是当前前缀范围内的整数个数。
	在函数内部，我们使用循环来不断将前缀扩大十倍，直到超过上限 `n` 或者到达下一个前缀的起始整数 `last`，
	同时统计前缀范围内的整数个数。这样，我们就能得到当前前缀范围内的整数个数。*/
	int getStep(int n, long long  first, long long last)
	{
		int ret = 0;
		while (first <= n)
		{
			ret += min(static_cast<long long>(n + 1), last) - first;
			first *= 10;
			last *= 10;
		}
		return ret;
	}
	int findKthNumber(int n, int k)
	{
		int step = 0;
		int cur = 1;
		k--;
		while (k > 0)
		{
			step = getStep(n, cur, cur + 1);//获得在以cur为前缀下有多少个整数
			if (step <= k) //不在这个前缀下
			{
				k -= step;
				cur += 1;	//跳到下一个前缀
			}
			else //在这个前缀下,继续补0继续往下找k==0时的数
			{
				k--;		//cur这个算找到一个,k--
				cur *= 10;	//在cur前缀后再补0
			}
		}
		return cur;
	}
};
//mine 陪葬,没有深刻意识到字典序的大小
class Solution1
{
public:
	//100 字典序是要小于11的.整十整百出现的时候,字典序和tmp相同,头插
	//131 字典序是要大于1111的,但是只能排在1这一数组中比131较后的位置
	//前功尽弃!!这个函数只是实现了简单的按照首元素字典序的切分
	int findKthNumber(int n, int k)
	{
		if (k > n) return -1;

		vector<vector<int>> tables(10);
		//哈希的方式,将开头字典序相同的放到一个容器
		//1. 产生N个数,hashFunc()= x/ 10=>ret尾插进入到对应编号容器中
		//%10 只针对1~100的数,字典序打头就是1~9,所以 while x/10 if x<=9
		for (int i = 1; i <= n; i++)//按顺序产生,所以尾插不用考虑相同起始数字的数字间排序问题
		{
			int tmp = i;// /10之后得到的是index不是原值
			while (tmp >= 10)
			{
				tmp /= 10;
			}
			//i<=9
			tables[tmp].push_back(i);
		}
		//2. 第k个数,就是从index=1的容器开始遍历
		vector<int>ans(n);
		int index = 0;
		for (int i = 1; i < tables.size(); i++)
		{
			for (int j = 0; j < tables[i].size(); j++)
			{
				ans[index++] = tables[i][j];
			}
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		return ans[k - 1];
	}
};

int main()
{
	Solution s;
	cout << s.findKthNumber(100, 10);
	return 0;
}