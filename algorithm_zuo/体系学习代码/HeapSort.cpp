#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap
{
public:
	//������ΪǰheapSize��ֵ��Ϊ��������
	// 
	//����: һ������indexλ�����ֵ,��ν������
	//���ϵ���
	void HeapInsert(vector<int>& arr, int index)
	{
		//index=0ʱ,(index-1)/2=0,��Ȼ����������
		while (arr[index] > arr[(int)((index - 1) / 2)])//size_t����->int
		{
			swap(arr[index],arr[(int)((index - 1) / 2)]);
			index = (index - 1)/2;
		}
	}

	//����: ���ض������ֵ,�������Ƴ�֮��,��Ȼ���ִ��
	// ����heapSize-1λ�õ�ֵ����0λ�ô�,�Ӷ���ʼ���µ���
	// ѡ�����������нϴ�ֵ,�Ƚ�֮�󽻻�λ��
	// ������������:
	//1. ����֮��û�к��ӽڵ��������
	//2. ���׽ڵ����max���ӽڵ�
	//���µ���
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
	//��ĳһ��λ�÷���ֵ�ĸı�,Ҫô�Ǳ�С��,������ִ����,���µ���,����˾����ϵ���
	//�������۾�ΪLogN����

	//����: ����֪����������Ϊ�����,���ǳ�ʼ��heapSize=0,��Ϊ[0,heapSize]��Ϊ�Ƕѿռ�
	//���൱��һ����heapInsert����
	void heapSort(vector<int>& arr)
	{
		if (arr.size() < 2)
			return;
		for (int i = 0; i < arr.size(); i++)//O(N)
		{
			HeapInsert(arr,i);//��������ȷ��λ��O(logN)
		}
		int heapSize = arr.size();
		swap(arr[0],arr[--heapSize]);
		while (heapSize > 0)//O(N)
		{
			HeapIfy(arr,0,heapSize);	//O(log(N))
			swap(arr[0],arr[--heapSize]);//O(1)
		}
	}
	//����ռ临�Ӷ���O(1) ֻ��Ҫ���뼸�������ռ伴��
	//����:�������������Ϊ�����,�����һ�����׽ڵ㿪ʼ���µ���heapIfy
	//��ײ�ռ����һ��,N/2,�޷������ٵ���,ֻ��һ��,������1
	//�����ڶ���N/4��,�������²���,��һ��,������2
	//�����ڶ���N/8��,�������²���2��,��һ��,������3
	//....
	//���帴�ӶȾ���T(N)=N/2*1+N/4*2+N/8*3....
	//��heapInsert��O(N*logN)=>O(N)
	//for (int i = (arr.size() - 1) / 2; i >= 0; i--)//O(N)
	//{
	//		HeapIfy(arr, i,heapSize);//��������ȷ��λ��O(logN)
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
//	int testTime = 5;//�����õ�̫��,�ܲ���
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