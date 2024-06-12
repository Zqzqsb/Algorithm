// Acwing 849
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 510;
int graph[N][N];
int dis[N] , vis[N];

void init()
{
    memset(graph , 0x3f , sizeof graph);
    memset(dis , 0x3f , sizeof dis);
}

void add(int a , int b , int c)
{
    graph[a][b] = min(graph[a][b] , c);
}

int dijkstra(int s , int e , int n)
{
    dis[s] = 0;
    
    // 纳入操作要做n次
    for(int t = 1 ; t <= n ; t++)
    {
        int new_node = 0;
        // 遍历所有未访问节点的距离 将距离最小的节点设为新要纳入的节点
        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i] && dis[i] < dis[new_node])
            {
                new_node = i;
            }
        }
        
        vis[new_node] = 1; 
        
        // 根据已经新纳入的节点 更新所有节点的可达距离
        for(int i = 1 ; i <= n ; i++)
        {
            // 这里已经有距离的节点的距离不会因为新节点的加入而更新
            // 原理参照dijsktra证明
            if(!vis[i]) dis[i] = min(dis[i] , dis[new_node] + graph[new_node][i]);
        }
    }
    
    if (dis[e] == 0x3f3f3f3f)
        return -1;
    else
        return dis[e];
}

int main()
{
    init();
    
    int n , m; cin >> n >> m;
    int a , b , c;
    while(m--)
    {
        scanf("%d %d %d" , &a , &b , &c);
        add(a , b , c);
    }
    
    cout << dijkstra(1 , n , n);
}