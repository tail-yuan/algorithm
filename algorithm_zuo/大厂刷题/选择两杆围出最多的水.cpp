#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.cn/problems/container-with-most-water/submissions/
//暴力方式:O(N^2)
//定义两个指针left,right,枚举left为左边界,right为右边界.
//枚举完一圈后,left++,right回退到left+1继续往后枚举.
//能否让right 不回退,left++,
// if [left]>[right],那么高度是由right来承担的.
// 区间长度减小,因为木桶效应,无论[left+1]>[right]
//还是[left+1]<[right],都会导致乘积减小,即得到的水量减小.
// 就说明高的那一方left就完全没有必要往前走.
// if[left]<[right],那么高度是由left来承担的.
// [left+1]<r: 1. [left+1]<[left],h减小,V减小 2. [left+1]>[left]有可能更新V
// [left+1]>r: 此时h由right承担,是有可能进行更新V较大值的.
//以上阐述说明,两个边界,哪个值较小,在区间缩短时就它移动.才可能更新最大值
//就可优化为首尾指针的算法,哪个值更小,就往前移动寻求较大V的更新.
class Solution
{
public:
	int maxArea(vector<int>& arr)
	{
		int left = 0, right = arr.size() - 1;
		int ret = INT_MIN;
		while (left < right)
		{
			int tmp_v = (right - left) * min(arr[left], arr[right]);
			ret = max(ret, tmp_v);
			if (arr[left] < arr[right])
				left++;
			else
				right--;
		}
		return ret;
	}
};