/*
    kruskal 每次挑一条最短的边加入生成树 并且保证不产生环
    这个实现中有两个关键操作 一个是排序 排序保证了每次考虑的都是当前可能的最短边
    另一个是是否合并的判别 如果某条边两端的两个定点位于两个不同的集合(两棵不同子树) 那么就可以将它们合并
    这样的合并方式 bottom up地保证了最终的结果一定是一颗树
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
// s用来记录某个生成子树的中的节点数量
int fa[N];

struct Edge
{
    int a , b , c;
    bool operator<(const Edge& e) const
    {
        return c < e.c;
    }
}edges[N*2];


void init()
{
    for(int i = 1 ; i < N ; i++) {fa[i] = i;}
}

int find(int x)
{
    // 路径压缩
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x , int y)
{
    int fx = find(x) , fy = find(y);
    if(fx != fy)
    {
        fa[fx] = fy;
    }    
}

void kruskal(int n , int m)
{
    sort(edges+1 , edges+m+1);
    int res = 0 , cnt = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        auto e = edges[i];
        if(find(e.a) != find(e.b))
        {
            merge(e.a , e.b);
            res += e.c; cnt++;
        }
    }

    if(cnt == n-1) cout << res;
    else cout << "impossible";
}

int main()
{
    init();
    int n , m;
    cin >> n >> m;

    int a , b , c;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> a >> b >> c;
        edges[i] = {a , b , c};
    }
    
    kruskal(n , m);
}

