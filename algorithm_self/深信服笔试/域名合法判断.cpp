//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//vector<string>Func(string& str)
//{
//    vector<string>arr;
//    char* tmp = new char[str.size() + 1];
//    strcpy(tmp, str.c_str());
//    char* cur = strtok(tmp, ".");
//    while (cur != nullptr)
//    {
//        arr.push_back(cur);
//        cur = strtok(NULL, ".");
//    }
//    delete[]tmp;
//    return arr;
//}
//bool isLegal(char ch)
//{
//    if ((ch>=0&&ch<=9) || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '-')
//        return true;
//    else
//        return false;
//}
//void test(string&str)
//{
//    bool flag = true;
//    if (str.size() > 255)
//    {
//        cout << "false" << endl;
//        return;
//    }
//    vector<string>arr = Func(str);
//    if (arr.size() < 2)
//    {
//        cout << "false" << endl;
//        return;
//    }
//    //判断标签
//    //1. 开头或者结尾不能是-
//    for (auto e : arr)
//    {
//        if (e.size() > 63)
//        {
//            cout << "false" << endl;
//            return;
//        }
//        string cur = e;
//        for (int i = 0; i < cur.size(); i++)
//        {
//            if (!isLegal(cur[i]))
//            {
//                cout << "false" << endl;
//                return;
//            }
//        }
//        int s = 0, end = cur.size() - 1;
//        if (cur[s] == '-' || cur[end] == '-')
//        {
//            cout << "false" << endl;
//            return;
//        }
//    }
//    cout << "true" << endl;
//    return;
//}
//int main()
//{
//    string str;
//    cin >> str;
//    test(str);
//    return 0;
//}
