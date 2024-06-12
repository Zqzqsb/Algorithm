/*
    Acwing 859
    kruskal 算法考虑每次选择一个未选择的最短边 来纳入新的节点(一个或两个)到树中
    遍历边的时间复杂度是灾难性的，我们考虑是否可以通过堆来优化这个问题(在实现kruskal的基础上)
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Edge
{
    int a , b , c;
    Edge(int a , int b , int c){this -> a = a; this -> b = b; this -> c = c;}
    bool operator>(const Edge& e) const {return this -> c > e.c;}
};


const int N = 1e5+10 , M = 2e5+10;
int tree[N][2];

priority_queue<Edge , vector<Edge> , greater<Edge> > heap;

// 我们每次选取的条件是 该边的两个节点至少有一个不在生成树内
// 考虑多个联通分量的情况 假设图有两个联通分量 节点数量为 N1 N2
// 在N1中 选N1-1个节点 在N2中 选N2选N2-1个节点 无法选出满足要求的所有节点

// 整个算法的代价是建堆的代价 + 调整堆的代价 
void kruskal(int n)
{
    cout << endl;
    int res = 0 , cnt = 0;
    while(heap.size())
    {
        Edge edge = heap.top(); heap.pop();
        int a = edge.a , b = edge.b , c = edge.c;
        
        // 这个条件过于严格 限制了树的行程 而判环的操作代价过大
        if(!tree[a] || !tree[b]) 
        {
            cout << a << " " << b << " " << c << endl;
            tree[a] = true; tree[b] = true;
            res += c;
            cnt++;
        }
    }
    
    if(cnt == n-1) cout << res;
    else cout << "impossible";
}

int main()
{
    int n , m;
    cin >> n >> m;

    int a , b , c;
    while(m--)
    {
        scanf("%d %d %d" , &a , &b , &c);
        heap.push(Edge(a , b , c));
    } 
    
    kruskal(n);
}