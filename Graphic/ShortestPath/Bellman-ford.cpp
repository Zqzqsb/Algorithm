// acwing 853
/*  
    单源最短路径算法 以BFS方式向外更新距离
    Bellman-ford O(nm) 迭代n次每次m条 适用有负权的稀疏图
    可以控制最多只经过k条边(迭代次数) 这样即使有负环也没关系
    
    遍历所有边 选择所有边 用当前所有可达的距离 更新该边的目标点
    因为负权边的存在 某些两个不可达节点 可能会发距离更新
    d[b] = min(d[b] , d[a] + w_ab) w_ab为负权 
    
    将起点的距离初始化为0
*/
// 因为遍历所有边 所以直接用结构体数组存储所有边 

#include <iostream>
#include <cstring>
using namespace std;

const int M = 1e5+10 , N = 510;
struct Edge
{
    int a , b , c;
}edges[M];
int dis[N] , last[N];

void init()
{
    memset(dis , 0x3f , sizeof dis);
}

void bellman_ford(int start , int end , int num_edges , int k)
{
    dis[start] = 0; 
    
    for(int t = 1 ; t <= k ; t++)
    {
        memcpy(last , dis , sizeof dis);
        for(int i = 1 ; i <= num_edges ; i++)
        {
            Edge e = edges[i];
            if(dis[e.b] > last[e.a] + e.c)
                dis[e.b] = last[e.a] + e.c;
        }
    }

    if(dis[end] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dis[end];
}
int main()
{
    init();
    
    int n , m , k; cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d %d %d" , &edges[i].a , &edges[i].b , &edges[i].c);
    }
    
    bellman_ford(1 , n , m , k);
}