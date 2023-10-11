#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//随时添加,实时显示
// 词频表, un_map
// 堆(K个长度),按照词频统计的小跟堆,堆顶是TopK 中的门槛
// 记录字符串在堆上的位置 un_map<key,location> 
// 不在堆上的位置设置为-1,憋着在词频中,直到词频能够干掉门槛,然后交换
// 自己实现的堆结构,调整时效率高于系统提供的堆
//

class Node
{
public:
	int times;
	string str;
	Node(string s, int t)
		:times(t)
		, str(s)
	{}
};
class TopKPrintInRealTime
{
public:
	TopKPrintInRealTime(int k=0)
	{
		heap.resize(k);
		index = 0;
	}
	void add(string& str)
	{
		Node* cur = nullptr;
		int preIndex = -1;//是否在堆上,默认-1是不在
		//如果第一次统计词频
		if (strNodeMap.find(str) == strNodeMap.end())
		{
			cur = new Node(str,1);
			strNodeMap.insert(make_pair(str,cur));
			indexMap.insert(make_pair(cur,-1));
		}
		else
		{
			cur = strNodeMap[str];
			cur->times++;
			preIndex = indexMap[cur];
		}
		if (preIndex == -1)
		{
			if (index == heap.size())//堆满了
			{
				if (heap[0]->times < cur->times)//能干掉门槛
				{
					indexMap[cur] = 0;
					indexMap[heap[0]] = -1;
					heap[0] = cur;
					heapIfy(0,index);//从0开始向下调整小堆
				}
			}
			else
			{
				indexMap[cur] = index;
				heap[index] = cur;
				heapInsert(index++);//向上调整
			}
		}
		else//原本在,从原本的位置向下调整
		{
			heapIfy(preIndex, index);
		}
	}
	void heapInsert(int index)
	{
		while (index != 0)
		{
			int parent = (index - 1) / 2;
			if (heap[index]->times < heap[parent]->times)
			{
				//swap(heap[index], heap[parent]);
				my_swap(index, parent);
				index = parent;
			}
			else
				break;
		}
	}
	void heapIfy(int index, int heapSize)
	{
		int l = index * 2 + 1;
		int r = index * 2 + 2;
		int smallest = index;
		while (l < heapSize)
		{
			if (heap[l]->times < heap[index]->times)
				smallest = l;
			if (r < heapSize && heap[r]->times < heap[smallest]->times)
				smallest = r;
			if (smallest != index)
				//swap(heap[index], heap[smallest]);
				my_swap(index,smallest);
			else
				break;
			index = smallest;
			 l = index * 2 + 1;
			 r = index * 2 + 2;
		}
	}
	void my_swap(int x,int y)
	{
		indexMap[heap[x]] = y;
		indexMap[heap[y]] = x;
		swap(heap[x],heap[y]);
	}
	void print()
	{
		for (int i = 0; i < heap.size(); i++)
		{
			if (heap[i] == nullptr)
				break;
			cout << heap[i]->str << " " << heap[i]->times << endl;
		}
	}
private:
	int index;//堆大小
	vector<Node*> heap;
	unordered_map<string, Node*>strNodeMap;
	unordered_map<Node* ,int>indexMap;
};