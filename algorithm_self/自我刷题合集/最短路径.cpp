#include<stdio.h>
#include<iostream>
using namespace std;
#include<algorithm>

#define max 200
#define MAX  10000                                     //Max表括?示?无T穷?大洙?

typedef struct
{
    char v[max];                                       // 节ú点?信?息￠
    int v1, e1;                                        //顶￥点?数簓，?边?数簓
    int linjie[max][max];                              //矩?阵ó
}graph;

void creategraph(graph& g)                             //初?始?化ˉ
{
    int w, p1, q1;                                       //w表括?示?权ā?重?，?q1,p1分?别纄表括?示?两?个?点?
    cin >> g.v1 >> g.e1;
    for (int i = 1; i <= g.v1; i++)
        for (int j = 1; j <= g.v1; j++)                  //对?矩?阵ó赋3值μ
        {
            g.linjie[i][j] = MAX;
            if (i == j)
                g.linjie[i][j] = 0;
        }
    for (int i = 1; i <= g.e1; i++)                       //赋3值μ
    {
        cin >> p1 >> q1 >> w;
        g.linjie[p1][q1] = w;
        // g.linjie[q1][p1] = g.linjie[p1][q1];
    }
}

void floyd(graph g, int path[][max], int dist[][max])         //佛洛?依皑?德?算?法ぁ?
{
    for (int i = 1; i <= g.v1; i++)
        for (int j = 1; j <= g.v1; j++)
        {
            dist[i][j] = g.linjie[i][j];                      //dist矩?阵ó表括?示?距à离?
            path[i][j] = j;                                   //path矩?阵ó表括?示?路·径?
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
    cout << "请?从洙?键ü盘ì输?入?一?个?图?";
    graph g;                             //图?g
    creategraph(g);
    int dist[max][max], path[max][max];
    floyd(g, path, dist);
    int ver1, ver2, p, q;                //ver1与?ver2分?别纄表括?示?两?点?，?p，?q同?理え?
    cin >> ver1 >> ver2;
    p = ver1;
    q = ver2;
    if (dist[ver1][ver2] == MAX)//两?点?之?间?不?可é达?。￡
    {
        cout << "两?点?之?间?不?可é达?" << endl;
        system("pause");
        return 0;
    }
    cout << "最?短ì路·径?为a：阰";
    while (p != q)
    {
        cout << path[p][q] << " ";
        p = path[p][q];
    }
    cout << endl << "最?短ì距à离?为a：阰";
    cout << dist[ver1][ver2];
    cout << endl