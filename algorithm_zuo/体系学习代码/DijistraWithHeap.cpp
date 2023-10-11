#include"Graph.hpp"
#include"Node.hpp"
#include"Edge.hpp"

#include<unordered_map>
#include<unordered_set>



class NodeRecord
{
public:
	Node* node;
	int distance;
	NodeRecord(Node* n=nullptr, int dis=0)
	{
		node = n;
		distance = dis;
	}
};
class NodeHeap
{
public:
	vector<Node*> nodes;
	unordered_map<Node*, int> heapIndexMap;//��¼�ڵ��ڶ��е��±�λ��
	unordered_map<Node*, int >distanceMap;
	int size;
public:
	NodeHeap(int s=0)
	{
		size = s;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	bool isEntered(Node* node)
	{
		return heapIndexMap.find(node) != heapIndexMap.end();
	}
	// һ���ڵ������,���ǵ�����,�±�����Ϊ-1
	bool inHeap(Node* node)
	{
		return isEntered(node) && heapIndexMap[node] != -1;
	}
	//�������ϵ���
	void addOrUpdateOrIgnore(Node*node, int dis)// dis = weigtSum(A->B->toNode)
	{
		if (inHeap(node))//�ڶ���, ����ֵ������λ��(��nodes���е�λ��,�Լ�map�е��±��¼)
		{
			distanceMap.insert(make_pair(node,min(distanceMap[node],dis)));
			insertHeapify(node, heapIndexMap[node]);
		}
		//���������ǲ��ڶ���,-1��������
		//��һ�ν����ڵ�ս���,�����½�;
		if (!isEntered(node))
		{
			nodes[size] = node;
			heapIndexMap.insert(make_pair(node,size));
			distanceMap.insert(make_pair(node,dis));
			insertHeapify(node,size++);
		}
	}
	void swapIndexAndNode(int index1, int index2)
	{
		//heapIndexMap.insert(make_pair(nodes[index1],index2));
		heapIndexMap[nodes[index1]] = index2;
		heapIndexMap[nodes[index2]] = index1;
		Node* tmp = nodes[index1];
		nodes[index1] = nodes[index2];
		nodes[index2] = tmp;
	}
	//�����ϵ���
	void insertHeapify(Node* node, int index)
	{
		while (distanceMap[nodes[index]] < distanceMap[nodes[(index - 1) / 2]])
		{
			swapIndexAndNode(index,(index-1)/2);
			index = (index - 1) / 2;
		}
	}
	//���µ���
	void heapify(int index, int size)
	{
		int left = index * 2 + 1;
		while (left < size)
		{
			//�ҳ����ӽڵ��еĽ�Сֵ
			int smallest = left + 1 < size
				&& distanceMap[nodes[left + 1]] < distanceMap[nodes[left]] ? left + 1 : left;
			smallest = distanceMap[nodes[smallest]] < distanceMap[nodes[index]] ? smallest : index;
			if (smallest == index)//��������Ѿ�����С��,˵�����µ���������
				break;
			swapIndexAndNode(smallest, index);
			index = smallest;
			left = index * 2 + 1;
		}
	}
	//��Ҫ��ͷ�����index=size-1λ�ý���(nodes����,�Լ�indexMap�еľ���)
	NodeRecord* pop()
	{
		NodeRecord* nodeRecord = new NodeRecord(nodes[0],distanceMap[nodes[0]]);

		swapIndexAndNode(0,size-1);
		heapIndexMap[nodes[size-1]] = -1;//���������ǵ���������Ϊ-1
		distanceMap.erase(nodes[size-1]);
		free(nodes[size - 1]);
		nodes[size - 1] = nullptr;
		heapify(0,--size);//�������֮��С�Ѵ�0��ʼ���µ���
		return nodeRecord;
	}
};
unordered_map<Node*, int> DijkstraWithDIYHeap(Node* head, int size)
{
	NodeHeap* nodeHeap = new NodeHeap(size);
	nodeHeap->addOrUpdateOrIgnore(head,0);
	unordered_map<Node*, int> res;
	while (!nodeHeap->isEmpty())
	{
		//��С���л�ȡ����С���۵�toNode�ڵ�
		NodeRecord* record = nodeHeap->pop();
		Node* cur = record->node;
		int dis = record->distance;
		//���ڵ�B�����ı߶�����С����
		for (Edge* e : cur->edge[0])
		{
			nodeHeap->addOrUpdateOrIgnore(e->to,e->weight+dis);
		}
		res.insert(make_pair(cur,dis));
	}
	return res;
}