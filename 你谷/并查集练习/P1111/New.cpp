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
    bool is_liant()
    {
        int c = findfather(1);
        for (int i = 2; i < val.size(); i++)
            if (c != findfather(i))
                return 0;
        return 1;
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
    int n, m, tot = 0, ans = 0;
    scanf("%d%d", &n, &m);
    Union U(n);
    for (int i = 0; i < m; i++)
    {
        a[i].input();
    }
    std::sort(a, a + m, cmp);
    for (int i = 0; i < m; i++)
    {
        U.merge(a[i].l, a[i].r);
        ans = a[i].qz;
        if (U.is_liant())
            break;
    }
    if (!U.is_liant())
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    tot = 0;
    ans = 0;
    return 0;
}