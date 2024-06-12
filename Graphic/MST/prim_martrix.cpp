/*
    Acwing 858
    Prim维护所有不在树中的节点到树的节点
    
    其更新的方式是 当树纳入一个新节点时 其他节点到树的距离可能会因为该节点的加入
    而发生变化。(因为该节点加入树之后，到树的距离就变成了零)
    
    事实上 该算法只考虑直接与树相邻的节点们 最近的节点也必然出现在这些节点之中
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 510;
int graph[N][N];
int tree[N] , dis[N];

void init()
{
    // 将所有节点设为不可达
    memset(graph , 0x3f , sizeof graph);
    memset(dis  , 0x3f , sizeof dis);
}

void add(int a , int b , int c)
{
    graph[a][b] = min(graph[a][b] , c);
    graph[b][a] = graph[a][b];
}

void Prim(int n)
{
    dis[1] = 0; // 设置一个起始节点
    int res = 0;
    
    // 遍历所有节点 进行n次
    for(int t = 1 ; t <= n ; t++)
    {
        int min_node = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            // 找一个不在书中且距离最小的节点
            if(!tree[i] && dis[i] < dis[min_node])
                min_node = i;
        }
        
        // 如果图是完全连通的 那么每次都应该找到一个新的节点
        if(min_node == 0)
        {
            cout << "impossible";
            return;
        }
        
        // 将这个节点加入生成树 并更新其他节点的距离
        res += dis[min_node]; tree[min_node] = true;
        
        for(int i = 1 ; i <= n ; i++)
        {
            if(!tree[i]) dis[i] = min(dis[i] , graph[min_node][i]);
        }
        
    }
    
    cout << res;
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
    
    Prim(n);
}