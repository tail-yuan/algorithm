#include<stdio.h>
#include<iostream>
using namespace std;
#include<algorithm>

#define max 200
#define MAX  10000                                     //Max����?ʾ?��T��?���?

typedef struct
{
    char v[max];                                       // �ڨ���?��?Ϣ��
    int v1, e1;                                        //������?���y��?��?���y
    int linjie[max][max];                              //��?��
}graph;

void creategraph(graph& g)                             //��?ʼ?����
{
    int w, p1, q1;                                       //w����?ʾ?Ȩ��?��?��?q1,p1��?���e����?ʾ?��?��?��?
    cin >> g.v1 >> g.e1;
    for (int i = 1; i <= g.v1; i++)
        for (int j = 1; j <= g.v1; j++)                  //��?��?�󨮸�3ֵ��
        {
            g.linjie[i][j] = MAX;
            if (i == j)
                g.linjie[i][j] = 0;
        }
    for (int i = 1; i <= g.e1; i++)                       //��3ֵ��
    {
        cin >> p1 >> q1 >> w;
        g.linjie[p1][q1] = w;
        // g.linjie[q1][p1] = g.linjie[p1][q1];
    }
}

void floyd(graph g, int path[][max], int dist[][max])         //��e��?����?��?��?����?
{
    for (int i = 1; i <= g.v1; i++)
        for (int j = 1; j <= g.v1; j++)
        {
            dist[i][j] = g.linjie[i][j];                      //dist��?�󨮱���?ʾ?�ਤ��?
            path[i][j] = j;                                   //path��?�󨮱���?ʾ?·����?
        }
    for (int k = 1; k <= g.v1; k++)
        for (int i = 1; i <= g.v1; i++)
            for (int j = 1; j <= g.v1; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                }
            }
}

int main()
{
    cout << "��?���?�����̨���?��?һ?��?ͼ?";
    graph g;                             //ͼ?g
    creategraph(g);
    int dist[max][max], path[max][max];
    floyd(g, path, dist);
    int ver1, ver2, p, q;                //ver1��?ver2��?���e����?ʾ?��?��?��?p��?qͬ?��?
    cin >> ver1 >> ver2;
    p = ver1;
    q = ver2;
    if (dist[ver1][ver2] == MAX)//��?��?֮?��?��?�ɨ���?����
    {
        cout << "��?��?֮?��?��?�ɨ���?" << endl;
        system("pause");
        return 0;
    }
    cout << "��?�̨�·����?Ϊa���o";
    while (p != q)
    {
        cout << path[p][q] << " ";
        p = path[p][q];
    }
    cout << endl << "��?�̨��ਤ��?Ϊa���o";
    cout << dist[ver1][ver2];
    cout << endl