/*
    Acwing 858
    Prim维护所有不在树中的节点到树的距离
    
    其更新的方式是 当树纳入一个新节点时 其他节点到树的距离可能会因为该节点的加入
    而发生变化。(因为该节点加入树之后，到树的距离就变成了零)
    
    事实上 该算法只考虑直接与树相邻的节点们 最近的节点也必然出现在这些节点中
    
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510  , M = 2e5 + 10;
int h[N] , e[M] , w[M] , ne[M] , idx;
int inTree[N] , dis[N];

void init()
{
    memset(h , -1 , sizeof h);
    memset(dis , 0x3f , sizeof dis);
}

void add(int a , int b , int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void prim(int n)
{
    int res = 0;
    
    // 设置一个初始点
    dis[1] = 0;
    // 进行n轮 节点的增加操作
    for(int r = 1 ; r <= n ; r++)
    {
        // 寻找一个距离最小且不在树中的节点
        int node = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(!inTree[i] && dis[i] < dis[node])
                node = i;   
        }
        // 每次都应找到一个节点 如果node为零 则树中存在多个联通分量
        if(node == 0) {cout << "impossible"; return;}
        
        // 将找到的节点加入树中
        inTree[node] = 1; res += dis[node];
        
        // 根据这个节点更新其他节点的距离
        for(int i = h[node] ; i != -1 ; i = ne[i])
        {
            int j = e[i]; dis[j] = min(dis[j] , w[i]);
        }
    }

    cout << res;
}

int main()
{
    init();
    
    int n , m;
    cin >> n >> m;
    int a , b , w;
    while(m--)
    {
        scanf("%d %d %d" , &a , &b , &w);
        add(a , b , w); add(b , a , w);   
    }

    prim(n);
}

