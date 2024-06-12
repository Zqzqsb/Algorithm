// acwing 848
// 采用队列优化的拓扑排序 其优化思想是 后续的entry只可能在entry去除的过程中产生
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 10;
int h[N] , e[N] , ne[N] , idx;
int vis[N] , in[N];

void init()
{
    memset(h , -1 , sizeof h);
}
void add(int a , int b)
{
    e[idx] = b; ne[idx] = h[a] ; h[a] = idx++;
    in[b]++;
}

void TpSort()
{
    int n , m; cin >> n >> m;
    
    int a , b;
    while(m--)
    {
        scanf("%d %d" , &a , &b);
        add(a , b);
    }
    
    vector<int> res;
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
    {
        if(in[i] == 0) q.push(i);
    }
    
    while(q.size())
    {
        int i = q.front(); q.pop(); res.push_back(i);
        for(int j = h[i] ; j != -1 ; j = ne[j])
        {
            in[e[j]]--;
            if(in[e[j]] == 0) q.push(e[j]);
        }
    }
    
    if(res.size() == n)
        for(auto i : res) 
            cout << i << " ";
    else
        cout << -1;
}

int main()
{
    init();
    TpSort();
}