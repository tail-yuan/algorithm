#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//使用单调栈,维护栈中从底到顶是从大到小排序的
//插入时, while(cur>st.top()) st.pop,然后插入,
//如果遍历结束时,st.size()>=K,那么就取栈底的K个元素就是最大值
//如果遍历结束发现不够K个,说明你要求的太高了,就得在遍历的过程中加个心眼降低标准
//尽量保证得够K个元素组成子序列,当你发现st.size()+cur之后的元素正好凑成K个时
//就别弹栈了,直接返回这些个就行了,你再弹栈后面元素就不够了
//无论cur此时的字典序多大,直接接上就行了
//这种贪心方式: 经过对数器是正确的
// 
//可以暴力生成所有K个的子序列,然后比对大小得到最大子序列
class Solution
{
public:
	string maxString(string& s, int k)
	{
		if (k <= 0 || s.size() < k)
			return "";
		int n = s.size();
		string st = "";
		int size = 0;//在size位置添加元素,size-1是栈顶
		for (int i = 0; i < s.size(); i++)
		{
			//弹出一个,发现后续的还够,就可以弹出.如果不够就别弹顶了
			//所以是问一下,再弹.这种在size位置插入很有普遍性
			while (size > 0 && st[size-1] < s[i] && size + n - i > k)
				--size;
			if (size+ n - i == k)
				return st+ s.substr(i);
			st[size++] = s[i];
		}
		return st;
	}
};