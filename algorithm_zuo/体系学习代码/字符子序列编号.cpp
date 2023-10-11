//在数据加密和数据压缩中常需要对特殊的字符串进行编码。给定的字母表A由26个小写英文字母组成，即
//A = { a, b...z }。该字母表产生的长序字符串是指定字符串中字母从左到右出现的次序与字母在字母表中出现
//的次序相同，且每个字符最多出现1次。
// 例如，a，b，ab，bc，xyz等字符串是升序字符串。
// 对字母表A产生的所有长度不超过6的升序字符串按照字典排列编码如下：a(1)，b(2)，c(3)……，z(26)，ab(27)，
//ac(28)……az(),bc(),bd......
// 对于任意长度不超过16的升序字符串，迅速计算出它在上述字典中的编码。
//输入描述：
//第1行是一个正整数N，表示接下来共有N行，在接下来的N行中，每行给出一个字符串。输出描述：
//输出N行，每行对应于一个字符串编码。
//示例1 :
//输入
//3
//a
//b
//ab
//输出
//1
//2
//27


#include<iostream>
using namespace std;
class stringToKth
{
public:
	//以i号字符开头,长度为len的子序列有多少个.1号就是a,2号就是b......
	int g(int i, int len)
	{
		int sum = 0;
		if (len == 1)
			return 1;
		//len>1 以i号字符开头,开头确定了,sum=以i+1(26种可能)为开头,len=len-1的子序列个数+ 以i+2为开头len=len-2子序列个数
		//即使是以z开头,长度为7,是没有子序列的,直接返回.
		for (int j=i+1; j <= 26; j++)
		{
			sum += g(j,len-1);
		}
		return sum;
	}
	//长度为len的子序列有多少个,没给开头那就去试26种开头能有多少个子序列
	int f(int len)
	{
		int sum = 0;
		for (int i = 1; i <= 26; i++)
			sum += g(i,len);
		return sum;
	}
	//如何知晓哪个子序列的标号?
	//1. len=str.size(),加入str={b,v,c}长度为3,必然在所有长度为2的序列的后面,所以个数先累加所有长度为2的,长度为1的
	//2. str是b开头长度为3的,那么前面肯定是有a开头长度为3的压在前面
	//3. 继续压以b开头长度为2的所有子序列,之后b,v就确定了
	//   继续压以v开头长度为1的所有子序列直到最后一个字符c中止,之后b,v,c就确定了
	// .......
	// 即从第二个字符开始一直往下压以index为头,长度为len-1的子序列的个数
	int kth(string& str)
	{
		int sum = 0;
		//1. 
		int len = str.size();
		for (int i = 1; i < len; i++)
			sum += f(i);
		//2. 
		int first = str[0] - 'a' + 1;
		for (int i = 1; i < first; i++)
			sum += g(i,len);
		//3. 
		int pre = first;
		for (int i = 1; i < len; i++)
		{
			int cur = str[i] - 'a' + 1;
			for (int j = pre + 1; j < cur; j++)//要列举b,v之前的,bc,bd...bu
			{
				sum += g(j,len-i);
			}
			pre = cur;
		}
		return sum + 1;
	}
};