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
	unordered_map<Node*, int> heapIndexMap;//记录节点在堆中的下标位置
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
	// 一个节点进过堆,但是弹出了,下标设置为-1
	bool inHeap(Node* node)
	{
		return isEntered(node) && heapIndexMap[node] != -1;
	}
	//都是向上调整
	void addOrUpdateOrIgnore(Node*node, int dis)// dis = weigtSum(A->B->toNode)
	{
		if (inHeap(node))//在堆上, 更新值并调整位置(在nodes表中的位置,以及map中的下标记录)
		{
			distanceMap.insert(make_pair(node,min(distanceMap[node],dis)));
			insertHeapify(node, heapIndexMap[node]);
		}
		//进来过但是不在堆上,-1不做处理
		//第一次进来节点刚进来,那我新建;
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
	//并向上调整
	void insertHeapify(Node* node, int index)
	{
		while (distanceMap[nodes[index]] < distanceMap[nodes[(index - 1) / 2]])
		{
			swapIndexAndNode(index,(index-1)/2);
			index = (index - 1) / 2;
		}
	}
	//向下调整
	void heapify(int index, int size)
	{
		int left = index * 2 + 1;
		while (left < size)
		{
			//找出孩子节点中的较小值
			int smallest = left + 1 < size
				&& distanceMap[nodes[left + 1]] < distanceMap[nodes[left]] ? left + 1 : left;
			smallest = distanceMap[nodes[smallest]] < distanceMap[nodes[index]] ? smallest : index;
			if (smallest == index)//如果父亲已经是最小了,说明向下调整结束了
				break;
			swapIndexAndNode(smallest, index);
			index = smallest;
			left = index * 2 + 1;
		}
	}
	//需要将头结点与index=size-1位置交换(nodes表中,以及indexMap中的距离)
	NodeRecord* pop()
	{
		NodeRecord* nodeRecord = new NodeRecord(nodes[0],distanceMap[nodes[0]]);

		swapIndexAndNode(0,size-1);
		heapIndexMap[nodes[size-1]] = -1;//进来过但是弹出就设置为-1
		distanceMap.erase(nodes[size-1]);
		free(nodes[size - 1]);
		nodes[size - 1] = nullptr;
		heapify(0,--size);//交换完毕之后将小堆从0开始向下调整
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
		//从小堆中获取到最小代价的toNode节点
		NodeRecord* record = nodeHeap->pop();
		Node* cur = record->node;
		int dis = record->distance;
		//将节点B所连的边都放入小堆中
		for (Edge* e : cur->edge[0])
		{
			nodeHeap->addOrUpdateOrIgnore(e->to,e->weight+dis);
		}
		res.insert(make_pair(cur,dis));
	}
	return res;
}