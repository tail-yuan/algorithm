#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
char theoperator[10];
int Addition = 0;
int subtraction = 0;
int multiplication = 0;
int division = 0;
int parentheses = 0;
int FloatingpointNumbers = 0;
int randomnumber(int n)  //���������
{
    int number;
    number = rand() % n;
    return number;
}
int judge(int n)
{
    if (n <= 1)
    {
        n = randomnumber(10);
    }
    return n;
}// �жϺ���ֵ
float theFloatingpointNumbers()//�������С��
{
    int  number;
    float numberone;
    number = rand() % 100;
    numberone = number / 100.0;
    return numberone;
}
void showopernumber(int *oper,int i)//�������
{
    float n;
    int m;
    {
        if (FloatingpointNumbers == 1)
        {
            m = randomnumber(4);
            if (m == 2)
            {
                n = theFloatingpointNumbers();
                cout << *(oper+i) + n;
            }
            else
                cout <<*(oper+1);
        }
        if (FloatingpointNumbers == 0)
            cout << *(oper + 1);

    }
}
void Addparentheses(char *a,int k)//��������
{    
    
    int m,c,b;
    char *p1,*p2;
    p1=a;
    m = rand() % (k-1);
    p1 = p1 + m;
    p2 = p1;
    p1 = p1 + (k - m);
    for (b=0; b <k-m; b++)
    {
        *p1 = *(p1-1);
        p1--;
    }
    *p1= '(';
    c = rand() % (k - m+1);
    c = c + m;
    
    while (1)
    {
        if ((c - m < 2)||(c-m==k))
        {
            c = rand() % (k - m+1);
            c = c + m;
        }
        else
            break;
    }
    p2 = a + c;
    p1 = a+k+1;
    for (b = 0; b < k + 1 - c; b++)
    {
        *p1 = *(p1 - 1);
        p1--;
    }
    *p1 = { ')'};
    /*for (b = 0; b < k + 2; b++)
        cout << *(a+b);*/
}
void show(char *symbol, int *oper, int a)//��������
{
    ofstream outfile;
    outfile.open("myfile.txt");
    char *p1, *p2;
    int *p3;
    int  i,m;
    char n;
    p1 = symbol;
    p2 = p1;
    p3 = oper;
    if (division == 1)
    {
        if (*p1 == '(')
        {
            cout << *p1;
            outfile << *p1;
            p1++;
            for (i = 0; i < a; i++)
            {
            
                showopernumber(oper, i);
                if (*p1 == ')')
                {
                    cout << *p1 << *(p1 + 1);
                    outfile<< *p1 << *(p1 + 1);
                    p1 = p1 + 2;
                }
                else
                {
                    cout << *p1;
                    p1++;
                    outfile << *p1;
                }
            }
            p1 = p2;
            cout << endl << endl;
        }
        if (*p1 != '(')
        {
            for (i = 0; i < a; i++)
            {
                //cout << oper[i];
                //outfile << oper[i];
                showopernumber(oper, i);
                if (*(p1 + 1) == '(')
                {
                    cout << *p1 << *(p1 + 1);
                    outfile << *p1 << *(p1 + 1);
                    p1 = p1 + 2;
                }
                else if (*p1 == ')')
                {
                    cout << *p1 << *(p1 + 1);
                    outfile << *p1 << *(p1 + 1);
                    p1 = p1 + 2;
                }
                else
                {
                    cout << *p1;
                    p1++;
                    outfile << *p1;
                }
            }
            p1 = p2;
            cout << endl << endl;
            outfile << endl;
            outfile.close();
        }
    }
    if (division == 0)
    {
        for (i = 0; i < a; i++)
        {
            showopernumber(oper, i);
            cout << symbol[i];
            outfile << oper[i] << symbol[i];
        }
        cout << endl << endl;
    }
}
void arithmetic(int n, int k, int l)//������������������
{
    int a, b, c, d, i, h = 0, mg = 0;
    int oper[100];
    char symbol[100];

    a = randomnumber(10);
    a = judge(a);
    b = a - 1;
    for (d = 0; d < n; d++)
    {
        for (i = 0; i < a; i++)
        {
            oper[i] = randomnumber(l);

        }
        for (i = 0; i < b; i++)
        {
            c = randomnumber(k);
            symbol[i] = theoperator[c];
        }
        symbol[i] = '=';
        if (division == 1)
        {
            d = randomnumber(10);
        }
        if (d > 6)
        {
            Addparentheses(symbol, a);
        }
        show(symbol, oper, a);
        a = randomnumber(10);
        while (1)
        {
            a = judge(a);
            if (a > 1)
                break;
        }
        b = a - 1;
    }
}
int Generationofarray(int a, int b, int c, int d)//���ɷ�������
{
    int sum = 0;
    if (Addition == 1)
    {
        theoperator[sum] = '+';
        sum++;
    }
    if (subtraction == 1)
    {
        theoperator[sum] = '-';
        sum++;
    }
    if (multiplication == 1)
    {
        theoperator[sum] = '*';
        sum++;
    }
    if (division == 1)
    {
        theoperator[sum] = '/';
        sum++;
    }
    return sum;
}
int main()
{    
    int number;
    int a, b, c, d, sum, i, l,j,x;
    cout << "��������Ҫ������Ŀ������" << ' ';
    cin >> number;
    cout << "�����ɵ������Ƿ�����ӷ��������������1����������0" << ' ';
    cin >> a;
    if (a == 1)
    {
        Addition = 1;
    }
    cout << "�����ɵ������Ƿ���������������������1����������0" << ' ';
    cin >> b;
    if (b == 1)
    {
        subtraction = 1;
    }
    cout << "�����ɵ������Ƿ�����˷��������������1����������0" << ' ';
    cin >> c;
    if (c == 1)
    {
        multiplication = 1;
    }
    cout << "�����ɵ������Ƿ���������������������1����������0" << ' ';
    cin >> d;
    if (d == 1)
    {
        division = 1;
    }
    cout << "��ȷ����������������ֵ" << endl;
    cout << "ʮ����������1 " << endl;
    cout << "100����������2" << endl;
    cin >> l;
    cout << "�����ɵ������Ƿ�������ţ������������1����������0"<<' ';
    cin >> j;
    cout << "�����ɵ������Ƿ�����������������������1����������0" << ' ';
    cin >> x;
    if (j == 1)
    {
        parentheses = 1;
    }
    if (x == 1)
    {
        FloatingpointNumbers = 1;
    }
    sum = Generationofarray(Addition, subtraction, multiplication, division);
    if (l == 1)
    {
        arithmetic(number, sum, 11);
    }
    if (l == 2)
    {
        arithmetic(number, sum, 101);
    }
    

}
