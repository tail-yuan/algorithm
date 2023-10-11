#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//��ʱ���,ʵʱ��ʾ
// ��Ƶ��, un_map
// ��(K������),���մ�Ƶͳ�Ƶ�С����,�Ѷ���TopK �е��ż�
// ��¼�ַ����ڶ��ϵ�λ�� un_map<key,location> 
// ���ڶ��ϵ�λ������Ϊ-1,�����ڴ�Ƶ��,ֱ����Ƶ�ܹ��ɵ��ż�,Ȼ�󽻻�
// �Լ�ʵ�ֵĶѽṹ,����ʱЧ�ʸ���ϵͳ�ṩ�Ķ�
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
		int preIndex = -1;//�Ƿ��ڶ���,Ĭ��-1�ǲ���
		//�����һ��ͳ�ƴ�Ƶ
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
			if (index == heap.size())//������
			{
				if (heap[0]->times < cur->times)//�ܸɵ��ż�
				{
					indexMap[cur] = 0;
					indexMap[heap[0]] = -1;
					heap[0] = cur;
					heapIfy(0,index);//��0��ʼ���µ���С��
				}
			}
			else
			{
				indexMap[cur] = index;
				heap[index] = cur;
				heapInsert(index++);//���ϵ���
			}
		}
		else//ԭ����,��ԭ����λ�����µ���
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
	int index;//�Ѵ�С
	vector<Node*> heap;
	unordered_map<string, Node*>strNodeMap;
	unordered_map<Node* ,int>indexMap;
};