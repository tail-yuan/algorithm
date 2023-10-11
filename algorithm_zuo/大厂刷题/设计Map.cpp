#include<iostream>
#include<map>
using namespace std;

//map ԭ�нӿ� insert(<,>),get����[],֮�������һ��setAll(int x)����,���������е�valȫ��Ϊx
//��setAll֮����Ȼ���Խ���insert����,�����key or �����Ѿ����ڵ�key��val
//��֤������������֮��,����ʱ�临�ӶȻ���O(1)

//���:
//������һ������time ����ʱ���,ÿ��<key,val>����ʱ,val�滻Ϊ<val,time>,time++
//����setAll�¼�ʱ,����allTime��¼����ʱ��.֮��ÿ��getʱ�������time<allTime��ô����allTime����
//��ΪҪ��֤O(1),���ܽ�ԭ���е�ֵ����һ��Ȼ���޸�ֵ.���ǲ�������ʱ����Ƚϵķ�ʽ����ѡ���ĸ�val


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