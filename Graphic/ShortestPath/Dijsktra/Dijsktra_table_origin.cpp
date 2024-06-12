// acwing 849
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2e5;
int h[N] , e[N] , w[N] , ne[N] , idx;
int vis[N] , dis[N];

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
    dis[start] = 0;

    for(int t = 1 ; t <= n ; t++)
    {
        int new_node = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i] && dis[i] < dis[new_node])
                new_node = i;
        }
        
        vis[new_node] = 1;
        
        for(int i = h[new_node] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(!vis[j]) dis[j] = min(dis[j] , dis[new_node] + w[i]);
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