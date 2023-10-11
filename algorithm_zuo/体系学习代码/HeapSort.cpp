#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap
{
public:
	//我们认为前heapSize个值作为堆来看待
	// 
	//需求: 一个个在index位置添加值,如何建立大堆
	//向上调整
	void HeapInsert(vector<int>& arr, int index)
	{
		//index=0时,(index-1)/2=0,依然不满足条件
		while (arr[index] > arr[(int)((index - 1) / 2)])//size_t类型->int
		{
			swap(arr[index],arr[(int)((index - 1) / 2)]);
			index = (index - 1)/2;
		}
	}

	//需求: 返回堆中最大值,并将他移除之后,仍然保持大堆
	// 将第heapSize-1位置的值放在0位置处,从顶开始向下调整
	// 选出两个孩子中较大值,比较之后交换位置
	// 交换跳出条件:
	//1. 交换之后没有孩子节点继续向下
	//2. 父亲节点大于max孩子节点
	//向下调整
	void HeapIfy(vector<int>& arr, int index, int heapSize)
	{
		int left = 2 * index + 1;
		while (left < heapSize)
		{
			int better = left;
			if (left + 1 < heapSize && (arr[left + 1] > arr[left]))
			{
				better = left + 1;
			}
			int largest = arr[index] > arr[better] ? index : better;
			if (largest == index)
				break;
			swap(arr[largest], arr[index]);
			index = largest;
			left = index * 2 + 1;
		}
	}
	//在某一个位置发生值的改变,要么是变小了,如果保持大根堆,向下调整,变大了就向上调整
	//调整代价均为LogN级别

	//需求: 将已知数组中整理为大跟堆,我们初始化heapSize=0,认为[0,heapSize]认为是堆空间
	//就相当于一个个heapInsert操作
	void heapSort(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		for (int i = 0; i < arr.size(); i++)//O(N)
		{
			HeapInsert(arr,i);//经历调整确定位置O(logN)
		}
		int heapSize = arr.size();
		swap(arr[0],arr[--heapSize]);
		while (heapSize > 0)//O(N)
		{
			HeapIfy(arr,0,heapSize);	//O(log(N))
			swap(arr[0],arr[--heapSize]);//O(1)
		}
	}
	//额外空间复杂度是O(1) 只需要申请几个变量空间即可
	//需求:将整个数组调整为大跟堆,从最后一个父亲节点开始向下调整heapIfy
	//最底层占将近一半,N/2,无法向下再调整,只看一眼,代价是1
	//倒数第二层N/4个,可以向下操作,看一眼,代价是2
	//倒数第二层N/8个,可以向下操作2次,看一眼,代价是3
	//....
	//整体复杂度就是T(N)=N/2*1+N/4*2+N/8*3....
	//从heapInsert的O(N*logN)=>O(N)
	//for (int i = (arr.size() - 1) / 2; i >= 0; i--)//O(N)
	//{
	//		HeapIfy(arr, i,heapSize);//经历调整确定位置O(logN)
	//}
};

void comparator(vector<int>& arr)
{
	sort(arr.begin(),arr.end());
}
vector<int> generateRandomArr(int maxSize, int maxVal)
{
	vector<int>arr;
	arr.resize((int)((maxSize + 1) * rand()));
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = (int)((maxVal + 1) * rand()) - (int)(maxVal*rand());
	}
	return arr;
}
bool isEqual(vector<int>& arr1, vector<int>& arr2)
{
	if ((arr1.size() == 0&& arr2.size() != 0) || (arr1.size()!=0 && arr2.size()==0))
		return false;
	if (arr1.size() == 0 && arr2.size() == 0)
		return true;
	if (arr1.size() != arr2.size())
		return false;
	for (int i = 0; i < arr1.size(); i++)
	{
		if (arr1[i] != arr2[i])
		{
			cout << i << " " << arr1[i] << " " << arr2[i] << endl;
			return false;
		}
	}
}
void printArr(vector<int>& arr)
{
	if (arr.size() == 0)return;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//int main()
//{
//	int testTime = 5;//别设置的太多,跑不完
//	int maxSize = 100;
//	int maxVal = 100;
//	bool succeed = true;
//	Heap heap;
//
//	for (int i = 0; i < testTime; i++)
//	{
//		vector<int>arr1 = generateRandomArr(maxSize, maxVal);
//		vector<int>arr2 = arr1;
//		heap.heapSort(arr1);
//		comparator(arr2);
//		/*if (!isEqual(arr1, arr2))
//		{
//			succeed = false;
//			break;
//		}*/
//		for (int i = 0; i < arr1.size(); i++)
//		{
//			if (arr1[i] != arr2[i])
//			{
//				cout << i << " " << arr1[i] << " " << arr2[i] << endl;
//				succeed = false;
//				break;
//			}
//		}
//	}
//	if (succeed)
//		cout << "Nice" << endl;
//	else
//		cout << "Fucking" << endl;
//	
//	vector<int>arr = generateRandomArr(maxSize, maxVal);
//	//printArr(arr);
//	vector<int>arr2 = arr;
//	heap.heapSort(arr);
//	comparator(arr2);
//	printArr(arr);
//}

//int main()
//{
//	vector<int>arr=generateRandomArr(1, 1);
//	for (int i = 0; i < arr.size(); i++)
//	{
//		cout << arr[i] << " ";
//	}
//}