#include<iostream>
#include<string>
#include<map>
//#include<vector>
#include<initializer_list>//ϵͳ�Լ�ʵ�ֵ���ģ��,ֻ֧��begin(),end(),size()
using namespace std;

template<class T>
class myVector
{
public:
	myVector(initializer_list<T> lt)
		:_cap(lt.size())
		,_size(0)
	{
		arr = new T[lt.size()];
		for (auto e : lt)
		{
			arr[_size++] = e;
		}
	}
	myVector<T>& operator=(initializer_list<T> l)
	{
		delete[] arr;//��ԭ���ռ��ͷ�
		int i = 0;
		for (auto e : l)
			arr[i++] = e;
		return *this;
	}

private:
	T* arr;
	int _cap;
	int _size;
};
//int main()
//{
//	myVector<int>v={1,2,3,4,5};
//	myVector<int> vv = v;
//}