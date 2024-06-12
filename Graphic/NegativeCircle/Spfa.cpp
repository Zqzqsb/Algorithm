/* 
    采用边权传递的方式更新距离 最长的一次传递也不会超过n
    而spfa会在负权回路中循环 如果检测到某条更新路径超过了n
    那么就有负权回路 所以要在所有的点出进行spfa算法
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int N = 1e5 + 10;
int h[N] , e[N] , w[N] , ne[N] , idx;
int st[N] , dis[N];

// 记录每个节点入队的次数
int count[N];

void add(int a, int b , int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;    
}

void init()
{
    memset(h , -1 , sizeof h);
    memset(dis , 0x3f , sizeof dis);
}

string spfa(int start , int end , int n)
{
    // 如果只初始化1个点 可能不能够包含图中所有的联通分量
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
    {
        q.push(i); st[i] = true;
    }
    
    while(q.size())
    {
        int n = q.front(); st[n] = false; q.pop();
        for(int i = h[n] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(dis[j] > dis[n] + w[i])
            {
                dis[j] = dis[n] + w[i];
                if(count[j] >= n)
                        return "Yes";
                if(!st[j])
                {
                    q.push(j); st[j] = 1;
                    count[j] =  max(count[j] , count[n] + 1);
                }
            }
        }
    }
    return "No";
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
    
    cout << spfa(1 , n , n);
}