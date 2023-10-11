//CC里面有一个土豪很喜欢一位女直播Kiki唱歌，平时就经常给她点赞、送礼、私聊。最近CC直播平台在举行
//中秋之星主播唱歌比赛，假设一开始该女主播的初始人气值为start， 能够晋升下一轮人气需要刚好达到end，
//土豪给主播增加人气的可以采取的方法有：
//a.点赞 花费x C币，人气 + 2
//b.送礼 花费y C币，人气 * 2
//c.私聊 花费z C币，人气 - 2
//其中 end 远大于start且end为偶数， 请写一个程序帮助土豪计算一下，最少花费多少C币就能帮助该主播
//Kiki将人气刚好达到end，从而能够晋级下一轮？
//输入描述：
//第一行输入5个数据，分别为：x y z start end，每项数据以空格分开。
//其中：0＜x, y, z＜＝10000， 0＜start, end＜＝1000000
//输出描述：
//需要花费的最少C币。
//示例1 :
//输入
//3 100 1 2 6
//输出
//6
// 单纯跑递归是可能跑不完的,所以需要1. 添加平凡解去限制递归,让他能够跑完.2. 从业务中发现不再需要递归的条件作为base case
//1. 单纯只用最笨的+2操作,总共需要花费多少钱? ((end-start)/2 )*add,花的钱币数再超过这个就没必要了
//2. 当递归通过三种方式产生的人气值如果已经是end的二倍了,然后再往下减,这个路是没有必要的
//3. 业务:当人气值小于0时就可以返回了
//做出限制之后,递归范围肯定是在一个固定范围,一定能跑完
#include<iostream>
using namespace std;
class Solution
{
public:
	int getCoinsMin(int add, int times, int del, int start, int end)
	{
		if (start > end)return -1;

		return process(0,end,add,times,del,start,end*2,((end-start)/2)*add);
	}
	//preMoney:之前已经使用的总钱数
	int process(int preMoney, int aim,
		int add, int times, int del,
		int cur,//某一条递归当前的人气值
		int limitAim, int limitCoins)
	{
		if (preMoney > limitCoins)
			return INT_MAX;
		if(cur>limitAim )
			return INT_MAX;
		if(cur<0)
			return INT_MAX;
		if (cur == aim)
			return preMoney;
		int ret = INT_MAX;
		int p1 = process(preMoney+add,aim,add,times,del,cur+2,limitAim,limitCoins);
		ret = min(ret, p1);
		int p2 = process(preMoney +times, aim, add, times, del, cur * 2, limitAim, limitCoins);
		ret = min(ret, p2);
		int p3 = process(preMoney +del, aim, add, times, del, cur - 2, limitAim, limitCoins);
		ret = min(ret, p3);
		return ret;
	}
};