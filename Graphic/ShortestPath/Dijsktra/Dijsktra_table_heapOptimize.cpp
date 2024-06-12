// acwing 850
// 堆优化用堆(小顶)来维护所有的待纳入节点的距离
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e5;
int h[N] , e[N] , w[N] , ne[N] , idx;
int vis[N] , dis[N];
typedef pair<int , int> pos;
void init()
{
    memset(h , -1 , sizeof h);
    memset(dis , 0x3f , sizeof dis);
}

void add(int a , int b , int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

int dijsktra(int start , int end , int n)
{
    priority_queue<pos , vector<pos> , greater<pos>> q; q.push({0 , start});
    dis[start] = 0;
    
    while(q.size())
    {
        int new_node = q.top().second; q.pop();
        if(vis[new_node]) continue;
        vis[new_node] = 1;
        
        for(int i = h[new_node] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(!vis[j] && dis[j] > dis[new_node] + w[i])
            {
                dis[j] = dis[new_node] + w[i];
                q.push({dis[j] , j});
            }
        }
    }
    if(dis[end] == 0x3f3f3f3f) return -1;
    else return dis[end];
}
int main()
{
    init();
    
    int n , m; cin >> n >> m;
    int a , b , c;
    while(m--)
    {
        scanf("%d %d %d", &a , &b , &c);
        add(a , b , c);
    }
    
    cout << dijsktra(1 , n , n);
    
}