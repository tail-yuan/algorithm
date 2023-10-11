#include<iostream>
#include<string>
#include<vector>
using namespace std;

// [a b][c d e]
void process(string str, int i, vector<string>& res)
{
	if (i == str.size())
		res.push_back(str);
	vector<bool> visit(26, false);
	//visited�����þ���str�п��ܴ�����ͬ���ַ�,������ͬ������������һ��,��֦Ч��
	//���str�б���Ͳ�������ͬ�ַ�,��û���Ż���Ч��,Ҳ�����������.
	for (int j = i; j < str.size(); j++)
	{
		if (!visit[str[j] - 'a'])
		{
			visit[str[j] - 'a'] = true;
			swap(str[i],str[j]);
			process(str, i + 1, res);
			swap(str[i], str[j]);
		}
	}
}
vector<string> PrintAllPermutations(string& str)
{
	vector<string>res;
	if (str.size() == 0)return res;
	process(str,0,res);
}
//int main()
//{
//	string str = "abcde";
//	PrintAllPermutations(str);
//}