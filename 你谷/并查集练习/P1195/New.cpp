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
    bool Unbro(int a, int b)
    {
        return findfather(a) != findfather(b);
    }
    void merge(int a, int b)
    {
        val[findfather(b)] = findfather(a);
    }
    void print()
    {
        for (int i = 1; i < val.size(); i++)
            printf("%d ", i);
        printf("\n");
        for (int i = 1; i < val.size(); i++)
            printf("| ");
        printf("\n");
        for (int i = 1; i < val.size(); i++)
            printf("v ");
        printf("\n");
        for (int i = 1; i < val.size(); i++)
            printf("%d ", val[i]);
        printf("\n");
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
} a[10001];
bool cmp(line a, line s)
{
    return a.qz < s.qz;
}
int main()
{
    int n, m, k, tot = 0, ans = 0;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%d%d", &m, &k);
        Union U(n);
        for (int i = 0; i < m; i++)
        {
            a[i].input();
        }
        std::sort(a, a + m, cmp);
        for (int i = 0; i < m && tot < (n - k); i++)
        {
            if (U.Unbro(a[i].l, a[i].r))
            {
                U.merge(a[i].l, a[i].r);
                tot++;
                ans += a[i].qz;
            }
        }
        // U.print();
        if (tot < (n - k))
        {
            printf("No Answer\n");
            continue;
        }
        printf("%d\n", ans);
        tot = 0;
        ans = 0;
    }
    return 0;
}
/*
3 1 2
1 2 1
1

4 5 1
1 2 2
1 3 2 
2 3 3
1 4 4
3 4 4

8

*/