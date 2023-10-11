#include<iostream>
#include<map>
using namespace std;

//map 原有接口 insert(<,>),get方法[],之外新添加一个setAll(int x)方法,将表中所有的val全改为x
//在setAll之后依然可以进行insert操作,新添加key or 更新已经存在的key的val
//保证新添加这个操作之后,操作时间复杂度还是O(1)

//题解:
//新增加一个变量time 代表时间戳,每个<key,val>插入时,val替换为<val,time>,time++
//发生setAll事件时,变量allTime记录发生时刻.之后每次get时如果发现time<allTime那么返回allTime即可
//因为要保证O(1),不能将原表中的值遍历一遍然后修改值.而是采用这种时间戳比较的方式决定选择哪个val


template<class V,class A=int>
class MyVal
{
public:
	V val;
	int time;
	MyVal(V& v, int t)
		:val(v)
		, time(t)
	{}
};
template<class K,class V>
class MyMap
{
private:
	map<K, MyVal<V, int>> treeMap;
	int time;
	MyVal<V, int>allTime;
public:
	MyMap()
		:time(0)
	{}
public:
	void put(K& key, V& val)
	{
		treeMap.insert(key,MyVal(val,time++));
	}
	void setAll(V& val)
	{
		allTime = MyVal(val,time++);
	}
	V get(K& key)
	{
		if (treeMap.count(key) == 0)
			return V();
		else
		{
			if (treeMap[key].time > allTime.time)
				return treeMap[key].val;
			else
				return allTime.val;
		}
	}
};

int main()
{
	return 0;
}