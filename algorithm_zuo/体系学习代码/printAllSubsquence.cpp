#include<iostream>
#include<string>
using namespace std;

//打印所有子序列
// abcdef
//每来到一个位置i,两条路:这个字符要还是不要
void process(string str, int i)
{
	if (i == str.size())
	{
		cout << str << endl;
		return;
	}
	process(str,i+1);//要i位置字符
	char tmp = str[i];

	str[i] = 0;		  //不要第i位置的字符
	process(str,i+1);

	str[i] = tmp;	//保证str值的不变
}
void printAllSubsquence(string& str)
{
	process(str, 0);
}
void process_plus(string str, int i, string res)
{
	if (i == str.size())
	{
		cout << res << endl;
	}
	string tmp = res;
	tmp += str[i];
	process_plus(str,i+1,tmp);
	string tmp2 = res;
	process_plus(str,i+1,tmp2);
}
void printAllSubsquence_plus(string& str)
{
	process_plus(str, 0,"");
}