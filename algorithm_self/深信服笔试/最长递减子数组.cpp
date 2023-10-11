//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int>Func(string& str)
//{
//    vector<int>arr;
//    char* tmp = new char[str.size() + 1];
//    strcpy(tmp, str.c_str());
//    char* cur = strtok(tmp, ",");
//    while (cur != nullptr)
//    {
//        arr.push_back(atoi(cur));
//        cur = strtok(NULL, ",");
//    }
//    delete[]tmp;
//    return arr;
//}
//int main()
//{
//	string str;
//	cin >> str;
//	vector<int>arr = Func(str);
//	int n = arr.size();
//	vector<int>dp(n + 1,1);//多开一个空间注意访问原数组下标问题
//	dp[0] = 0;
//	int ret = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		if (arr[i-2]>arr[i-1])
//		{
//			dp[i] = dp[i - 1] + 1;
//		}
//		ret = max(dp[i], ret);
//	}
//	cout << ret << endl;
//}