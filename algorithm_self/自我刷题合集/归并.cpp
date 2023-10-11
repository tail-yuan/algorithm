#include <iostream>
using namespace std;
//2路归并函数，用于把两个有序子序列归并为一个
//left指向第一个序列开头元素
//mid指向第一个序列末尾元素
//right指向第二个序列末尾元素
template <typename T>
void Merge(T myarray[], T* pResult, int left, int mid, int right, int length)
{
	cout << "Merge():left=" << left << "right=" << right << "mid=" << mid << endl;
	cout << "元素值begin:";
	for (int i = 0; i < length; i++)
	{
		cout << myarray[i] << ' ';
	}
	//把myarray指定的left到right 的范围内的数据享福知道pResult（临时空间）中
	for (int i = left; i <= right; ++i)
	{
		pResult[i] = myarray[i];
	}
	cout << endl;
	int curpos1 = left;//第一个序列的开始元素
	int curpos2 = mid + 1;//第二个序列的开始元素
	int curpos3 = left;//最终合并好的序列的开始元素
	while (curpos1 <= mid && curpos2 <= right)
	{
		if (pResult[curpos1] <= pResult[curpos2])//使用<=是为了算法的稳定性
		{
			myarray[curpos3] = pResult[curpos1];
			curpos1++;
			curpos3++;
		}
		else
		{
			myarray[curpos3] = pResult[curpos2];
			curpos2++;
			curpos3++;
		}
	}
	while (curpos1 <= mid)//子序列1比子序列2长
	{
		//直接把子序列1中剩余的内容放入myarray中
		myarray[curpos3] = pResult[curpos1];
		curpos1++;
		curpos3++;
	}
	while (curpos2 <= right)//子序列2比子序列1长
	{
		//直接把子序列1中剩余的内容放入myarray中
		myarray[curpos3] = pResult[curpos2];
		curpos2++;
		curpos3++;
	}
	cout << "元素值end:";
	for (int i = 0; i < length; i++)
	{
		cout<< myarray[i]<<" ";
	}
	cout << endl;
	return;
}
//归并排序重载函数
template <typename T>
void MergingSort(T myarray[], T* pResult,int left,int right,int length)//length是为了显示信息
{
	if (left >= right)
	{
		return;
	}//递归出口
	int mid = (left + right) / 2;//从中间分开
	MergingSort(myarray, pResult, left, mid, length);//对左半部分归并排序
	MergingSort(myarray, pResult, mid + 1, right, length);//对右半部分归并排序
	//上面因为左半部分归并排序完成，右半部分归并排序完成，所以下面是合并左半部分和右半部分了
	Merge(myarray, pResult, left, mid, right, length);
	return;
}
//归并排序入口
template <typename T>
void MergingSort(T myarray[], int length)
{
	T* pResult = new T[length];//新数组，用于保存结果
	MergingSort(myarray, pResult, 0, length - 1, length);//调用重载函数
	delete[]pResult;//释放内存
	return;
}
//非递归实现归并排序
template <typename T>
void MergingSort_noRecu(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	T* pResult = new T[length];//新数组，用于保存数据
	//表示两个子序列位置
	int left, mid, right;
	int distence = 1;//间隔，开始时元素是紧挨着的两个进行比较，两个元素之间下表间隔1
	int subseqTotal = length;//当前子序列数量，开始是把一个元素算一个子序列
	int times = 0;//归并次数
	while (subseqTotal > 1)//只要没有最终合并成1个序列，就一直循环
	{
		times++;
		cout << "-----------这是第" << times << "次归并------------。" << endl;
		for (int i = 0; i < length; i += (distence * 2))
		{
			left = i;
			mid = left + distence - 1;
			if (mid >= length)
			{
				break;
			}
			right = 2 * mid - left + 1;
			if (right >= length)//保证right合法
			{
				right = length - 1;
			}
			//必须要保证数据都合法
			if (left <= mid && right > left && right > mid)
			{
				//肯定是两个序列，能合并
				Merge(myarray, pResult, left, mid, right, length);
				subseqTotal--;//两个序列合并成一个，序列数目减少
			}
			else
			{
				//数据出错，不能合并，直接退出
				break;
			}
		}//end for i
		distence *= 2;
	}//end while
	delete[]pResult;
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18 ,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	//MergingSort(arr, length);
	MergingSort_noRecu(arr, length);
	cout << "归并排序的结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
