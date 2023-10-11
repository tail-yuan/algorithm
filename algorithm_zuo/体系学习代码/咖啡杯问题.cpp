#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//1. index标号的咖啡机冲好一杯咖啡的时间
//2. n个人要喝
//3. 洗杯子的机器洗完一个杯子所需时间
//4. 杯子不洗,自然挥发的时长
// 得到咖啡,立马喝完
//返回这些人喝完+杯子干净,至少需要多长时间?

// 先考虑人怎么选哪台机器?安排会议问题,哪个会议先结束-----贪心
// 同理,小根堆维护time+cost <time/*time时刻机器可用*/,cost/*泡咖啡消耗时间*/> 即哪个先泡完一杯咖啡
// 数组tmp记录每个人可获取到咖啡的时间
// 弹出堆顶即最早的可获得机器的时间,->tmp[i]
// 你用完之后,将<time+cost,cost>更新->小堆中
// 轮到下一个人获取...

// 因为喝咖啡时间忽略,得到咖啡的时间就是开始洗的时间------暴力递归->动归
// 也就是在tmp中如何顺序选择洗的最快?
// 1. 洗咖啡机器 2. 挥发
// 从左到右暴力递归 index下标杯开始洗, washline 在哪个时间点有空
// zuo()返回如果要洗完[index...N-1]返回最少的时间,最早完成所有事情的时间

class CoffeCup
{
public:
	class Machine
	{
	public:
		int timePoint;
		int workTime;
		Machine(int t, int w)
			:timePoint(t)
			, workTime(w)
		{}
	};
	struct Greater
	{
		bool operator()(Machine& m1, Machine& m2)
		{
			return (m1.timePoint + m1.workTime) - (m2.timePoint + m2.workTime);
		}
	};
	int getMin(vector<int>&arr,int n,int a,int b)
	{
		priority_queue<Machine, vector<Machine>, Greater()>heap;//小堆
		for (int i = 0; i < arr.size(); i++)
			heap.push(Machine(0,arr[i]));
		vector<int>drink(n);
		for (int i = 0; i < n; i++)
		{
			Machine cur = heap.top();
			heap.pop();
			cur.timePoint += cur.workTime;
			drink[i] = cur.timePoint;//获取到咖啡的时间(可以开始洗的时间)
			heap.push(cur);
		}
		return zuo(drink,a,b,0,0);
	}
	int zuo(vector<int>& drink, int a, int b, int index, int washLine)
	{
		//还剩最后一杯时两种选择
		if(index==drink.size()-1)
			return min(max(washLine, drink[index]) + a, drink[index] + b);
		//				  机器空闲时间点,某人要洗的时间点 取大值的意思是两个条件都具备
		//                选洗还是选挥发时间小的那个
		//还剩不止一杯咖啡
		//1. 我选机器洗
		int wash = max(drink[index], washLine) + a;
		//   洗完后面所有咖啡的时间点,既然我选了机器洗,那么后面的就得受我的影响,也就是在我洗完之后机器才有空洗别人,在wash时可用
		int next1 = zuo(drink,a,b,index+1,wash);
		//我洗完时间点     后面全洗完时间点  max就是使得这两种都成立,也就是这种选择下都洗完的时间点p1
		int p1 = max(wash,next1);

		//2. 我选挥发
		int dry = drink[index] + b;
		//   洗完后面所有咖啡的时间点,既然我没选了机器洗,
		//那么后面的就不受我的影响,也就是在现在就可用,在washLine时可用
		int next2 = zuo(drink,a,b,index+1,washLine);
		int p2 = max(dry,next2);

		return  min(p1,p2);
	}
	// 1. index [0,n-1] washLine [0,sum]sum是所有杯子都用机器洗的总时间
	//	  [3,    19,                   33,37,100] 
	//    轮到19那个人时3+a时间点获取到洗机器,洗完的时间点b=max(19+a/*我得先喝完+洗完时间点*/,3+a+a/*洗机器空闲时间点*/)
	//    轮到33时,在b时间点获取到洗机器,c = max(b+a,33+a)
	//	  ...得到washLine 最大值   
	//    drink[n-1]+n*a加了n个a 时间,只要空间开的足够即可 -> drink[index] + (index + 1) * a;
	// 2. dp[n][ drink[n-1]+n*a]  
	// 3. return dp[0][0]从下往上找


	int getMinDP(vector<int>& arr, int n, int a, int b)
	{
		priority_queue<Machine, vector<Machine>, Greater()>heap;//小堆
		for (int i = 0; i < arr.size(); i++)
			heap.push(Machine(0, arr[i]));
		vector<int>drink(n);
		for (int i = 0; i < n; i++)
		{
			Machine cur = heap.top();
			heap.pop();
			cur.timePoint += cur.workTime;
			drink[i] = cur.timePoint;//获取到咖啡的时间(可以开始洗的时间)
			heap.push(cur);
		}
		vector<vector<int>> dp(n, vector<int>(drink[n - 1] + n * a));
		for(int i=0;i<dp[0].size();i++)
			dp[n-1][i]= min(max(i, drink[n-1]) + a, drink[n-1] + b);
		for (int index = n - 2; index >= 0; index--)
		{
			int washLine = drink[index] + (index + 1) * a;
			for (int col = 0; col <washLine; col++)
			{
				int wash = max(drink[index], washLine) + a;//使用机器洗应该跳转的位置
				dp[index][col] = min(max(wash, dp[index + 1][wash]), max(drink[index] + b, dp[index][col]));
			}
		}
		return dp[0][0];
	}
};