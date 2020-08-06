#include <cstdio>
#include <algorithm>
#include <vector>
struct Union
{
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
    int jsans()
    {
        int ans = 0;
        for (int i = 1; i < val.size(); i++)
        {
            if (val[i] == i)
                ans++;
        }
        return ans;
    }
    void clear(int n)
    {
        val.resize(n + 1);
        for (int i = 1; i < val.size(); i++)
            val[i] = i;
    }
    std::vector<int> val;
}U;
int main()
{
#ifdef Test
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n, m;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        U.clear(n);
        scanf("%d", &m);
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            U.merge(a, b);
        }
        printf("%d\n", U.jsans() - 1);
    }
#ifdef Test
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}