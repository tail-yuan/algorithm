#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

//���鼯
//��ʼÿ��Ԫ�ض��Ƕ�����Element<>,����Union������,��Bָ��A,A��ΪB�ĸ���Ԫ��,��Cָ��D
// A��Ϊ�Լ���B�Ĵ���Ԫ��,D��Ϊ�Լ���C��,��ΪAB��CD�Ĵ���Ԫ�ز�ͬ,������Ϊ���߲���ͬһ����
//Union A Cʱ,��sizeС�ļ��ϵĴ���Ԫ��Cָ��A,��ʱA�����ĸ��Ĵ���Ԫ��,��ͬһ������
//���ܻ����������Ȼ���������⵼��O()����O(1)
//��ô�Ż�:ĳһԪ��x�����Ҵ���Ԫ��ʱ,���������ҹ����������ĵĸ��׵�parentָ��,����ΪA(����Ԫ��)
//ʹ�ø��ӱ��,Ч�ʸ���.
//��ƽ=>O(1) �������findHead�����ƽ�N,���߳���N��ʱ.
template<class V>
class UnionFind
{
public:
	class Element
	{
	public:
		Element(V val)
			:value(val)
		{}

		V value;
	};
public:
	UnionFind(list<V>& vlist)
	{
		for (auto e : vlist)
		{
			Element* ele = new Element(e);
			elementMap.insert(make_pair(e,ele));
			fatherMap.insert(make_pair(ele,ele));
			sizeMap.insert(make_pair(ele,1));
		}
	}
	Element<V>* findHead(Element<V>*element)
	{
		stack<Element<V>*> path;
		while (element != fatherMap[element])
		{
			path.push(element);
			element = fatherMap[element];
		}
		while (!path.empty())
		{
			fatherMap.insert(make_pair(path.top(),element));
			path.pop();
		}
		return element;
	}
	bool isSameSet(V& a, V& b)
	{
		if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
		{
			return findHead(elementMap[a]) == findHead(elementMap[b]);
		}
		return false;//���鼯��û�о���false
	}
	void Union(V& a, V& b)
	{
		if (elementMap.find(a) == elementMap.end() || elementMap.find(b) == elementMap.end())
			return;
		Element<V>* aFather = findHead(elementMap[a]);
		Element<V>* bFather = findHead(elementMap[b]);
		if (aFather == bFather)
			return;
		//��С�����ӵ������
		Element<V>* big = sizeMap[aFather] >= sizeMap[bFather] ? aFather : bFather;
		Element<V>* small = big == aFather ? bFather : aFather;
		fatherMap.insert(small,big);
		sizeMap[big]=sizeMap[aFather]+sizeMap[bFather];
		sizeMap.erase(small);
	}
private:
	unordered_map<V, Element<V>*> elementMap;
	unordered_map<Element<V>*, Element<V>*> fatherMap;//һ��Ԫ�صĸ���Ԫ��
	unordered_map<Element<V>*, int>sizeMap;
};