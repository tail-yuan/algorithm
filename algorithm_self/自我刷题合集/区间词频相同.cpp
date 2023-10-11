#include"head.hpp"
// 来自华为OD
// 完美走位问题
// 给定一个由'W'、'A'、'S'、'D'四种字符组成的字符串，长度一定是4的倍数
// 你可以把任意连续的一段子串，变成'W'、'A'、'S'、'D'组成的随意状态
// 目的是让4种字符词频一样
// 返回需要修改的最短子串长度
// 找到了出处，是leetcode原题
// 测试链接 : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

// 给定字符串中,将一段连续的区间的字母替换为缺失的字母使得整体字符串中各种字母词频相同
// 求出这个存在的最小区间的最短子串长度
// 
// 设计一个函数,在[l,r)区间中自由支配,能否让区间中字母词频相同
	//如果可以,返回true,不可以返回false
// 如果较大区间返回false,那么更小的区间肯定也false
// 从左到右依次遍历字母,使用窗口,得到每一个字母能够做到的区间
// 将每一个字母得到的区间大小求出最小值
class Solution
{
public:
	int balancedString(string s) 
	{
		int n = s.size();
		int* arr = new int[n];
		//cnts记录的是区间之外的字母的频次
		int* cnts = new int[4] {0};
		//将字符转化为数字存储
		for (int i = 0; i < n; i++)
		{
			char c = s[i];
			arr[i] = c == 'W' ? 1 : (c == 'E' ? 2 : (c == 'R' ? 3 : 0));
			cnts[arr[i]]++;
		}
		int ans = n;
		for (int l = 0, r = 0; l < n; l++)
		{
			//!ok(cnts,l,r),当前窗口[l,r)如果不能让四种字符一样多
			//并且右边界还能扩容,就扩容
			while (!ok(cnts, l, r) && r < n)
				cnts[arr[r++]]--;
			// 1) ok 不管是扩没扩容,反正是ok了
			// 2) !ok,而且还没有空间向右扩展了
			if (ok(cnts, l, r))
			{
				ans = min(ans,r-l);
			}
			else//[l,r)都没能实现,你再从更小区间[l+1,r)就更没机会了
			{
				break;
			}
			cnts[arr[l]]++;
		}
		return ans;
	}
	// 窗口，str[l.....r)，你可以自由变化，但是窗口外的不能变化
	// l = 3, r = 10
	// [3,10) <=> [3....9]
	// 窗口长度 = r - l= 10 - 3 = 7
	// cnts，窗口之外每一种字符的词频统计，不能算窗口内的统计的！
	// w : cnts[0]
	// a : cnts[1]
	// s : cnts[2]
	// d : cnts[3]
	// cnts只有4长度
	// 每个字母频次追上区间外的最大词频的求和sum,区间中减去sum
	// 剩下的空间能否实现4字母的均分,能实现就ok
	bool ok(int *& cnts,int l,int r)
	{
		int maxCnt = max(max(cnts[0], cnts[1]), max(cnts[2], cnts[3]));
		int changes = maxCnt * 4 - cnts[0] - cnts[1] - cnts[2] - cnts[3];
		int rest = r - l - changes;
		return rest >= 0 && rest % 4 == 0;
	}
};
