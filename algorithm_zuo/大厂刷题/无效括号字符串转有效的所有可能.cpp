#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//无效括号串中删掉最少的括号得到有效括号串,返回所有字面值不同的有效括号字符串
//例如: ()((())) ) 多一个),
//1. 可以删除第二个字符),-> ( ((())) )
//2. 可以删除倒数四个)中其中一个,都得到字面值相同的->()((()))
//解法一: 不剪枝收集所有结果之后再过滤
//解法二: 剪枝,将计算过的直接砍掉,效率更高.
// 
//首先: 判断括号字符串有效,[i]=(,count++,[i]=),count--;
// 当只专注于删除)时,从左往右处理: 
//		if count<0,return false; if count>=0,说明每个)都有(与他匹配
//当出现count<0时,说明)多了,就需要删除之前的其中一个),其实就是选择其中一个(改变匹配对象
//让他匹配新的). 删除)时,如果是连续的),只需要删除一个)即可,因为得到的结果是一样的.
//只有中间存在(的),删除才有不同的结果出现.因为选中的是新的(和刚出现的)匹配.
// 
//所以需要两个参数i,j 构成f(i,j)函数
//i用来遍历检查,count.j 是表示可能删除的位置.f(i,j)
//在到[i]时发现count<0,说明在[0,i]之间的j位置该删除)了,
//删完一个之后,后面的字符串向前覆盖那个被删的位置,下标重新分布导致ij位置是之前没访问的位置
//再调用f(i,j),从i位置往后检查,j是下一个可能删除的位置
// 
//	具体实现:
//到达第一个不合法位置[i]时,删完之后,f直接return 了,也就是说后续怎么删是通过调用子函数的方式记录的.
//  
//  那怎么删呢? j从deleteIndex开始,小于等于i位置.
//删掉一个j位置之后,后序字符串向前覆盖,调用子函数f(i,j),进入下一层递归,
//再进行查找,再遇到一个新的i使得count<0
//再在从j开始往后找,寻求删除一个),后面字符串向前覆盖...
// 直到再调用子函数时,发现i位置处于越界位置(因为字符串一直向前覆盖)
//此时找到一个合法字符串.然后向上返回,在上一层的j+1位置尝试删除,然后再调用子函数,依次类推.

//注意: 在找完一个j删除之后,尝试从j+1位置删除时,可能不是j+1位置,因为为了去重,
// 会存在选择的操作,也就是不找连续的)删除.
//这样收集到的一定是不一样的有效括号字符串.
//左神讲解视频:图的例子
//https://www.bilibili.com/video/BV1NV4y1B7ZZ?p=17&spm_id_from=pageDriver&vd_source=cc945ef88574fe2db5e814c0c265a4c7
//https://leetcode.cn/problems/remove-invalid-parentheses/submissions/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
class Solution
{
	vector<string>ans;
public:
	vector<string> removeInvalidParentheses(string& str)
	{
		remove(str, 0, 0, {'(',')'});
	}
	void remove(string& s, int checki, int deletei,pair<char,char>par)
	{
		int count = 0;
		for (int i = checki; i < s.size(); i++)
		{
			if (s[i] == par.second)
				count--;
			else if (s[i] == par.first)
				count++;
			if (count < 0)
			{
				for (int j = deletei; j <= i; j++)
				{
					if (s[j] == par.second && (j == deletei || s[j - 1] != par.second))
					{
						string newStr = s.substr(0, j) + s.substr(j + 1);
						remove(newStr,i,j,par);
					}
				}
				return;
			}
		}
		//循环结束,此时所有的右括号都不比左括号多,那么逆序一下,去寻求删除(
		reverse(s.begin(),s.end());
		if (par.first == '(')
			remove(s, 0, 0, { ')','(' });
		else//防止一直转不完
			ans.push_back(s);
	}
};