#include<iostream>
#include<string>
using namespace std;

//��ӡ����������
// abcdef
//ÿ����һ��λ��i,����·:����ַ�Ҫ���ǲ�Ҫ
void process(string str, int i)
{
	if (i == str.size())
	{
		cout << str << endl;
		return;
	}
	process(str,i+1);//Ҫiλ���ַ�
	char tmp = str[i];

	str[i] = 0;		  //��Ҫ��iλ�õ��ַ�
	process(str,i+1);

	str[i] = tmp;	//��֤strֵ�Ĳ���
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