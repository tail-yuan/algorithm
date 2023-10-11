#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class SortArrDistanceLessK
{
public:
	void sortArrDistanceLessK(vector<int>& arr, int k)
	{
		priority_queue<int,vector<int>,greater<int>> heap;
		int index = 0;
		int n = arr.size();
		for (; index < min(k, n); index++)
		{
			heap.push(arr[index]);
		}
		int i = 0;
		for (; index < n; i++,index++)
		{
			heap.push(arr[index]);
			arr[i] = heap.top();
			heap.pop();
		}
		while (!heap.empty())
		{
			arr[i++] = heap.top();
			heap.pop();
		}
	}
};
class Student
{
public:
	int id;
	int age;
	string name;
	Student(int i = 0, int a = 0, string n = "")
		:id(i)
		, age(a)
		, name(n)
	{}
	//less 降序,小堆
	bool operator<(const Student& s1) const
	{
		return age < s1.age;
	}
	//greater 升序 大堆
	bool operator>(const Student& s1)const
	{
		return age > s1.age;
	}
};

struct Greater
{
	bool operator()(const Student& s1, const Student& s2)
	{
		return s1.age < s2.age;//大堆,升序
	}
};
struct Less
{
	bool operator()(const Student& s1, const Student& s2)
	{
		return s1.age> s2.age;//小堆,降序
	}
};
/*
int main()
{
	//priority_queue<int, vector<int>, less<int>> heap;//小堆 降序
	////priority_queue<int> heap;//小堆
	////priority_queue<int, vector<int>, greater<int>> heap;//大堆 升序

	//heap.push(8);
	//heap.push(4);
	//heap.push(6);
	//heap.push(1);
	//heap.push(3);
	//while (!heap.empty())
	//{
	//	cout << heap.top() << " ";
	//	heap.pop();
	//}
	// 
	// 
	//类内重载运算符
	//priority_queue<Student, vector<Student>, less<Student>>heap;
	//priority_queue<Student, vector<Student>, greater<Student>>heap;
	//传仿函数
	//priority_queue<Student, vector<Student>, Greater>heap;
	priority_queue<Student, vector<Student>, Less>heap;

	Student s1(1,2,"李华");
	Student s2(2,3,"李四");
	Student s3(3,4,"李无");
	Student s4(4,5,"李流");
	heap.push(s1);
	heap.push(s2);
	heap.push(s3);
	heap.push(s4);
	cout << heap.top().name << endl;
}
*/