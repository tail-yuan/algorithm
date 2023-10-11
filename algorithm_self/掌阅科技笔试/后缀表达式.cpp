
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int>st;
        string str = "+-*/";
        for (auto s : tokens)
        {
            if (str.find(s) != string::npos)//ÊÇ²Ù×÷·û
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                switch (s[0])
                {
                case '+':st.push(a + b); break;
                case '-':st.push(b - a); break;
                case '*':st.push(a * b); break;
                case '/':st.push(b / a); break;
                }
            }
            else
                st.push(stoi(s));
        }
        return st.top();
    }
};