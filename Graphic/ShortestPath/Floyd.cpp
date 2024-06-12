/*
    acwing 854
    floyd 基于动态规划 不需要开数组记录各个节点间的距离
    其核心考量是 两个节点的距离能不能由第三个节点来更新
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 210;
int graph[N][N];

int main()
{
    memset(graph , 0x3f , sizeof graph);
    for(int i = 0 ; i < N ; i++) 
    { 
        graph[i][i] = 0;
    }
       
    
    int n , m , k;
    cin >> n >> m >> k;
    
    int a , b , w;
    while(m--)
    {
        scanf("%d %d %d" , &a , &b , &w);
        graph[a][b] = min(graph[a][b] , w);
    }
    
    // k的含义是从i到j的中继节点
    // 即所有节点的组合 经过节点k能不能改善他们的相互距离
    for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                graph[i][j] = min(graph[i][j] , graph[i][k]+graph[k][j]);

    
    while(k--)
    {
        scanf("%d %d" , &a , &b);
        if(graph[a][b] >= 0x3f3f3f3f / 2)
            cout << "impossible" << endl;
        else 
            cout << graph[a][b] << endl;
    } 
}