#include<iostream>
#include<vector>
using namespace std;
//有26个字母a-z，找出所有字母的组合，a、b、c、ab、abc、a~z都是一个组合(顺序无关)
vector<char> arr = {'a','b','c','d','e','f','g','h','i','j','k','l',
				'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void  f(int index ,string& cur)
{
	if (index == arr.size())
	{
		cout << cur << endl;
		return;
	}
	//使用这个字符
	f(index+1,cur+=arr[index]);
	//不使用这个字符
	f(index=1,cur);
}
//int main()
//{
//	string cur = "";
//	f(0,cur);
//}