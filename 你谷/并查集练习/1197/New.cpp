#include <cstdio>
#include <cstring>
int ak[400010], ans[400010], fath[400010], head[400010], a_t;
bool edge[400010];
struct line
{
    int next, ndbh, from;
} a[400010];
void add(int x, int y)
{
    a[++a_t].from = x;
    a[a_t].next = head[x];
    head[x] = a_t;
    a[a_t].ndbh = y;
}
int find(int n)
{
    return fath[n] == n ? n : fath[n] = find(fath[n]);
}
void merge(int i, int j)
{
    i = find(i), j = find(j);
    if (i != j)
        fath[j] = i;
}
int main()
{
    memset(edge, 0, sizeof(edge));
    int n, m, k, tot;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        fath[i] = i;
        head[i] = -1;
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    scanf("%d", &k);
    tot = n - k;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &ak[i]);
        edge[ak[i]] = true;
    }
    for (int i = 1; i <= m * 2; i++)
    {
        if (!edge[a[i].from] && !edge[a[i].ndbh] && find(a[i].from) != find(a[i].ndbh))
        {
            tot--;
            merge(a[i].from, a[i].ndbh);
        }
    }
    ans[k + 1] = tot;
    for (int i = k; i >= 1; i--)
    {
        tot++;
        edge[ak[i]] = false;
        for (int j = head[ak[i]]; j != -1; j = a[j].next)
        {
            if (!edge[a[j].ndbh] && find(ak[i]) != find(a[j].ndbh))
            {
                tot--;
                merge(ak[i], a[j].ndbh);
            }
        }
        ans[i] = tot;
    }
    for (int i = 1; i <= k + 1; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}