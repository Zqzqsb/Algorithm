// acwing 853
/*  
    单源最短路径算法 以BFS方式向外更新距离
    Bellman-ford O(nm) 迭代n次每次m条 适用有负权的稀疏图
    可以控制最多只经过k条边(迭代次数) 这样即使有负环也没关系
    
    遍历所有边 选择所有边 用当前所有可达的距离 更新该边的目标点
    因为负权边的存在 某些两个不可达节点 可能会发距离更新
    d[b] = min(d[b] , d[a] + w_ab) w_ab为负权 
    
    将起点的距离初始化为0

    假设 任一两节点 存在一条最短路径 那么该路径的长度不会超过所有节点的数量
    所以Bellman-ford的运行次数不会超过n次
*/
// 因为遍历所有边 所以直接用结构体数组存储所有边 

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int M = 1e5+10 , N = 2010;
struct Edge
{
    int a , b , c;
}edges[M];
int dis[N] , last[N];

void init()
{
    memset(dis , 0x3f , sizeof dis);
}

string bellman_ford(int num_edges , int num_nodes)
{
    dis[1] = 0;
    
    bool update = true;
    int cnt = 0;
    while(update)
    {
        if(cnt >= num_nodes)
            return "Yes";
        cnt++;
        
        update = false;
        memcpy(last , dis , sizeof dis);
        for(int i = 1 ; i <= num_edges ; i++)
        {
            Edge e = edges[i];
            if(dis[e.b] > last[e.a] + e.c)
            {
                dis[e.b] = last[e.a] + e.c;
                update = true;
            }
        }
    }
    return "No";
}

/*
    4 4
    1 2 -1
    1 4 -1
    2 3 -1
    3 4 -1

    对于这组输入 答案是No
    第一次更新 0 -1 INF-1 INF-1
    第二次更新 0 -1 -2    INF-1
    第三次更新 0 -1 -2    -3
    会进入第四次但不会更新
*/
int main()
{
    init();
    
    int n , m; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++)
    {
        scanf("%d %d %d" , &edges[i].a , &edges[i].b , &edges[i].c);
    }
    
    cout << bellman_ford(m , n);
}