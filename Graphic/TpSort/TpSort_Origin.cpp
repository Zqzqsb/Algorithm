// acwing 848
// 朴素解法
// 寻找下一点的方法为遍历 面对多个入口的拓扑序列效率较高
#include<iostream>
#include<vector>
#include<cstring>
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
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i] && in[i] == 0)
            {
                vis[i] = true; flag = true;
                res.push_back(i);
                for(int j = h[i] ; j != -1 ; j = ne[j])
                    in[e[j]]--;
            }
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