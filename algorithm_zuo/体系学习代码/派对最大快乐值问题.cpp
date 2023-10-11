
#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Info
{
public:
	int comeMaxH;
	int noComeMaxH;
	Info(int c = 0, int n = 0)
		:comeMaxH(c)
		, noComeMaxH(n)
	{}
};
class Employee
{
public:
	int happyVal;
	vector<Employee*> sub;
};
class MaxHappy
{
public:
	Info* process(Employee* x)
	{
		if (x->sub.size() == 0)
			return new Info(x->happyVal,0);
		int come = x->happyVal;
		int noCome = 0;
		for (Employee* e : x->sub)
		{
			Info* nextInfo = process(e);
			come += nextInfo->noComeMaxH;
			noCome += max(nextInfo->comeMaxH,nextInfo->noComeMaxH);
		}
		return new Info(come,noCome);
	}
	int maxHappy(Employee* boss)
	{
		Info* headInfo = process(boss);
		return max(headInfo->comeMaxH,headInfo->noComeMaxH);
	}
};