#include <cstdio>
#include <algorithm>
#include <vector>
struct Union
{
    Union(int n)
    {
        val.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            val[i] = i;
        }
    }
    int findfather(int s)
    {
        int olds = s;
        while (val[s] != s)
            s = val[s];
        if (olds != s)
            val[olds] = s;
        return s;
    }
    void merge(int a, int b)
    {
        val[findfather(b)] = findfather(a);
    }
    bool is_bro(int a, int b)
    {
        return findfather(a) == findfather(b);
    }
    std::vector<int> val;
};
struct line
{
    int l, r, qz;
    void input()
    {
        scanf("%d%d%d", &l, &r, &qz);
    }
} a[100001];
bool cmp(line a, line s)
{
    return a.qz < s.qz;
}
int main()
{
    int n, m, ans = 0, tot = 0, z = 0;
    scanf("%d%d", &n, &m);
    Union U(n);
    for (int i = 0; i < m; i++)
    {
        a[i].input();
        z += a[i].qz;
    }
    std::sort(a, a + m, cmp);
    for (int i = 0; i < m && tot < n - 1; i++)
    {
        if (!U.is_bro(a[i].l, a[i].r))
        {
            U.merge(a[i].l, a[i].r);
            ans += a[i].qz;
            tot++;
        }
    }
    printf("%d\n", z - ans);
    return 0;
}