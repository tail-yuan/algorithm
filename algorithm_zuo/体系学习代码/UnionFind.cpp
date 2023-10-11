#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

//并查集
//开始每个元素都是独立的Element<>,经过Union操作后,让B指向A,A作为B的父亲元素,让C指向D
// A作为自己和B的代表元素,D作为自己和C的,因为AB和CD的代表元素不同,所以认为四者不是同一集合
//Union A C时,让size小的集合的代表元素C指向A,此时A就是四个的代表元素,在同一集合了
//可能会存在链表仍然过长的问题导致O()不是O(1)
//那么优化:某一元素x向上找代表元素时,将他向上找过程中遇到的的父亲的parent指向,都改为A(代表元素)
//使得更加扁扁,效率更高.
//扁平=>O(1) 如果调用findHead次数逼近N,或者超过N次时.
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
		return false;//并查集中没有就是false
	}
	void Union(V& a, V& b)
	{
		if (elementMap.find(a) == elementMap.end() || elementMap.find(b) == elementMap.end())
			return;
		Element<V>* aFather = findHead(elementMap[a]);
		Element<V>* bFather = findHead(elementMap[b]);
		if (aFather == bFather)
			return;
		//将小的连接到大的上
		Element<V>* big = sizeMap[aFather] >= sizeMap[bFather] ? aFather : bFather;
		Element<V>* small = big == aFather ? bFather : aFather;
		fatherMap.insert(small,big);
		sizeMap[big]=sizeMap[aFather]+sizeMap[bFather];
		sizeMap.erase(small);
	}
private:
	unordered_map<V, Element<V>*> elementMap;
	unordered_map<Element<V>*, Element<V>*> fatherMap;//一个元素的父亲元素
	unordered_map<Element<V>*, int>sizeMap;
};