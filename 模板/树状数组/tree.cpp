#include <cstdio>
#ifdef xxs
#include <windows.h>
#endif
int a[11111], n, m;
int lowbit(int c)
{
    return c & (-c);
}
int sum(int n)
{ //sum at n to 1
    int ans = 1, i = n;
    while (i)
    {
        ans += a[i];
        i -= lowbit(i);
    }
    return ans;
}
void add(int nc, int i)
{ //add nc at i
    while (i <= n)
    {
        a[i] += nc;
        i += lowbit(i);
    }
}
inline int qjsum(int a, int b)
{
    return sum(b) - sum(a - 1);
}
int main()
{
    scanf("%d%d", &n, &m);
    int z, x, k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        add(k, i);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &z, &x, &k);
        if (z == 1)
        {
            add(k, x);
        }
        else
        {
            printf("%d\n", qjsum(x, k));
        }
    }
#ifdef xxs
    system("pause");
#endif
}