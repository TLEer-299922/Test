#include <iostream>
#include <cstdio>
#define f(i, a, b) for(register int i = a; i <= b; i++)
#define fd(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;
int k, n, m, head[400002], a_t, ak[400002], ans[400003];
int father[400003];
struct Node
{
    int next, node, from;
} a[400002];
inline void add(int x, int y)
{
    a[++a_t].from = x;
    a[a_t].next = head[x];
    head[x] = a_t;
    a[a_t].node = y;
}
bool edge[400001];
inline int find(int x)
{
    if (father[x] == x)
        return x;
    return father[x] = find(father[x]);
}
inline void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
        father[y] = x;
}
int main()
{
    cin >> n >> m;
    f(i, 0, n)
        father[i] = i,
        head[i] = -1;
    f(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x); 
    }
    cin >> k;
    f(i, 1, k)
    {
        cin >> ak[i];
        edge[ak[i]] = 1;
    }
    int total = n - k;
    f(i, 1, 2 * m) 
        if (!edge[a[i].from] && !edge[a[i].node] && find(a[i].from) != find(a[i].node))
    {
        total--; 
        merge(a[i].from, a[i].node);
    }
    ans[k + 1] = total;
    fd(i, k, 1)
    {
        total++;
        edge[ak[i]] = 0;
        for (int j = head[ak[i]]; j != -1; j = a[j].next)
        {
            if (!edge[a[j].node] && find(ak[i]) != find(a[j].node))
            {
                total--;
                merge(ak[i], a[j].node); 
            }
        }
        ans[i] = total;
    }
    f(i, 1, k + 1) cout << ans[i] << endl;
    return 0;
}