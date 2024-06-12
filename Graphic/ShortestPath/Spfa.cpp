// acwing 851
/* 
    spfa 按波次向后更新 只有距离变小的节点才能更新其后续节点
    
    其算法复杂度 与到任任一目标点的最短路径长度有直接关系 
    一般接近O(M) 其理论上限在O(NM)
    
    采用队列存储所有的距离被更新的节点编号 队列中不会存储重复的节点(区别于堆优化的dijsktra)
    
    该算法在负环处无法收敛
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int h[N] , e[N] , w[N] , ne[N] , idx;
int st[N] , dis[N];

void add(int a, int b , int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;    
}

void init()
{
    memset(h , -1 , sizeof h);
    memset(dis , 0x3f , sizeof dis);
}

void spfa(int start , int end)
{
    dis[start] = 0; 
    // st[start] = 1; // 事实上这一步可以不写 因为没有负环 start的距离不可能被更新为更小的值
    queue<int> q; q.push(start);
    
    // 该算法收敛的判定条件是没有点的距离再被更新
    // 所以该算法事实上求出了所有点到源点的最短距离_存疑
    while(q.size())
    {
        int n = q.front(); st[n] = false; q.pop();
        for(int i = h[n] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            // cout << dis[j] << " " << dis[n] << " " << w[i];
            if(dis[j] > dis[n] + w[i])
            {
                dis[j] = dis[n] + w[i];
                if(!st[j])
                {
                    q.push(j); st[j] = 1;
                }
            }
        }
    }
    
    if(dis[end] == 0x3f3f3f3f) cout << "impossible";
    else cout << dis[end];
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
    
    spfa(1 , n);
}