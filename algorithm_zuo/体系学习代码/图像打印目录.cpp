//给你一个字符串类型的数组arr，譬如：
//String[] arr = { "b\\cst", "d\\", "a\\d\\e", "a\\b\\c" };
//你把这些路径中蕴含的目录结构给画出来，子目录直接列在父目录下面，并比父目录
//向右进两格，就像这样 :
//a
//  b
//    c
//  d
//    e
//b
//  cst
//d
//同一级的需要按字母顺序排列，不能乱。

//构建前缀树+深度优先遍历定制打印
//                null
//1.     a                b          d
//2.   b  d                cst
//3.  c    e
//第二层距离4空格打印一次,第三层就间隔8空格即可完成定制打印
//构建前缀树:如果有到目标节点的路,就复用,没有就新建
#include<iostream>
#include<map>
#include<vector>
using namespace std;
class GetFolderTree
{
public:
	class Node
	{
	public:
		string name;
		map<string, Node*> nextArr;
	public:
		Node(string s = "null")
			:name(s)
		{}
	};
	void print(vector<string>& floderArr)
	{
		if (floderArr.size() == 0)
			return;
		Node* head = getFolderTree(floderArr);
		printHead(head, 0);
	}
	void printHead(Node* head, int level)
	{
		if (level != 0)
			cout << get2space(level) << head->name << endl;
		//获取第二层的值
		//Node* tmp = head->nextArr[head->name];
		auto it = head->nextArr.begin();
		while (it!=head->nextArr.end())
		{
			printHead(it->second,level+1);
			it++;
		}
	}
	string get2space(int n)
	{
		string res = "";
		for (int i = 1; i < n; i++)
			res += " ";
		return res;
	}
	/*template<typename T>
	void printHead(T* head, int level)*/
	//void printHead(Node* head, int level) 解决Node* 未识别标识符的问题.1. 使用typename告诉编译器先让我编译通过,后续类型会补救2. 将Node的声明放在前面
	/*class Node
	{
	public:
		string name;
		map<string, Node*> nextArr;
	public:
		Node(string s = "null")
			:name(s)
		{}
	};*/
	Node* getFolderTree(vector<string>& floderArr)
	{
		Node* head = new Node();
		for (string& folderPath : floderArr)
		{
			//根据目录切割符,将一条dir目录名分割到一个数组中
			vector<string> paths = mySplit(folderPath, "\\");
			//从head开始向下构建树
			Node* cur = head;
			for (int i = 0; i < paths.size(); i++)
			{
				//没有就新建
				if (cur->nextArr.find(paths[i]) == cur->nextArr.end())
					cur->nextArr.insert({ paths[i],new Node(paths[i]) });
				//有就复用节点然后继续往下走
				cur = cur->nextArr[paths[i]];
			}
			//完成一条路径创建
		}
		return head;
	}
	//通过strtok函数实现C++中string的split()函数
//strtok为C语言中的字符串分割函数，其具体解释如下:
//	原型：char* strtok(char* str, const char* delimiters);
//	功能：分割字符串str，delimiters为指定的分割符，可以有多个。
//		说明：strtok只能接受C风格的字符串，如果是string类型，可以使用c_str函数进行转换。
//		strtok()用来将字符串分割成一个个片段。参数s指向欲分割的字符串，参数delim则为分割字符串，
//		当strtok()在参数s的字符串中发现到参数delim的分割字符时 则会将该字符改为\0 字符。
//		在第一次调用时，strtok()必需给予参数s字符串，往后的调用则将参数s设置成NULL。
//		每次调用成功则返回被分割出片段的指针。
	vector<string> mySplit(string& str, string&& pattern)
	{
		char* tmp_str = new char[str.size() + 1];
		strcpy(tmp_str, str.c_str());
		vector<string>res;
		char* tmp = strtok(tmp_str, pattern.c_str());
		while (tmp != nullptr)
		{
			res.push_back(std::string(tmp));
			tmp = strtok(NULL, pattern.c_str());
		}
		delete[] tmp_str;
		return res;
	}
};