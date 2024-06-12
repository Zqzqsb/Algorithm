/*
    Acwing 858.859
    Prim维护所有不在树中的节点到树的节点
    
    其更新的方式是 当树纳入一个新节点时 其他节点到树的距离可能会因为该节点的加入
    而发生变化。(因为该节点加入树之后，到树的距离就变成了零)
    
    事实上 该算法只考虑直接与树相邻的节点们 最近的节点也必然出现在这些节点之中
    可以优先队列存储这个待更新的节点 在稀疏图中 这个优化的效果并不明显 因为遍历所有节点的代价并不是很大

    但是在稠密图中 该算法的执行时间显著降低 可以通过Acwing 859
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

const int N = 510  , M = 2e5 + 10;
int h[N] , e[M] , w[M] , ne[M] , idx;
int inTree[N] , dis[N];
typedef pair<int , int> POS;
void init()
{
    memset(h , -1 , sizeof h);
    memset(dis , 0x3f , sizeof dis);
}

void add(int a , int b , int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void Prim(int n)
{
    priority_queue<POS , vector<POS> , greater<POS> > heap;
    heap.push(POS(0 , 1)); dis[1] = 0;
    int res = 0 , cnt = 0;
    while(heap.size())
    {
        // 取出堆顶的元素
        int node = heap.top().second; heap.pop();
       
        // 堆中会加入重复的元素 如果第一次拿到的是有效的最短距离 后面的重复记录则跳过
        if(inTree[node]) continue;
        
        // 将有效的节点数量加一 并将这个距离加入生成树
        cnt++; res += dis[node]; inTree[node] = 1;
        
        // 根据堆顶元素更新其他元素的可达距离
        for(int i = h[node] ; i != -1 ; i = ne[i])
        {
            int j = e[i]; 
            // 将不在树中 切距离变小的节点加入堆
            if(!inTree[j] && dis[j] > w[i])
            {
                dis[j] = w[i];
                heap.push(POS(dis[j] , j));
            }
        }

    }

    if(cnt == n) cout << res;
    else cout << "impossible" << endl;
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

    Prim(n);
}


