#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;
//找到数组中任意位置i,arr[i]左右比他大的,距离它最近的两个数
// 无重复值
// 找最近的较大的值,选择栈,约定栈底到栈顶是从大到小的顺序
// 找最近的较小的值,选择栈,约定栈底到栈顶是从小到大的顺序
// 1. 如果比栈顶元素小就进栈
// 2. 如果cur比栈顶元素x大,弹出栈顶元素x,左边比x大的最近的值就是它压着的数,cur就是它右边最近的比他大的值
// 有重复值
// stack<list<int>>压入栈中元素是相同值的下标链表即可,其他同理(弹出链表最后一个值,因为进来的时候就是push_back)

//较小值
vector<vector<int, int>> getNearLessNoRepeat(vector<int>& arr)
{
	vector<vector<int, int>>res;
	stack<int>st;
	for (int i = 0; i < arr.size(); i++)
	{
		//维持底到顶是从小到大的顺序
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			int popIndex = st.top(); st.pop();
			int leftLessIndex = st.empty() ? -1 : st.top(); 
			res[popIndex][0] = leftLessIndex;
			res[popIndex][1] = i;
		}
		st.push(i);
	}
	//最后栈中还有元素,说明是从小到大的,没有右边比他小的值-1
	//压着的就是最近的比他小的值
	while (!st.empty())
	{
		int popIndex = st.top(); st.pop();
		int leftLessIndex = st.empty() ? -1 : st.top();
		res[popIndex][0] = leftLessIndex;
		res[popIndex][1] = -1;
	}
	return res;
}


//较小值
vector<vector<int, int>> getNearLessNoRepeat(vector<int>& arr)
{
	vector<vector<int, int>>res;
	stack<vector<int>>st;//将arr[i]值相同的,也就是重复值放到同一个数组中,数组多大就多少个重复值
	for (int i = 0; i < arr.size(); i++)
	{
		int index = st.top()[0];
		while (!st.empty() && arr[index] > arr[i])
		{
			vector<int> popIs = st.top(); st.pop();//整个数组值弹出
			int leftLessIndex = st.empty() ? -1 : st.top()[st.top().size() - 1];
			//整个数组值都记录一下左右最近较小值
			for (int popi : popIs)
			{
				res[popi][0] = leftLessIndex;
				res[popi][1] = i;
			}
		}
		//如果再遇到一个相同值
		if (!st.empty() && arr[st.top()[0]] == arr[i])
			st.top().push_back(i);//数组中存放的都是相同值的下标
		else//遇到一个新值,或者栈为空
		{
			vector<int>tmp;
			tmp.push_back(i);
			st.push(tmp);
		}
		//处理潜在的剩余数字,一定是从小到大的
		while (!st.empty())
		{
			vector<int> popIs = st.top(); st.pop();//整个数组值弹出
			int leftLessIndex = st.empty() ? -1 : st.top()[st.top().size() - 1];
			//整个数组值都记录一下左右最近较小值
			for (int popi : popIs)
			{
				res[popi][0] = leftLessIndex;
				res[popi][1] = -1;
			}
		}
		return res;
	}
}