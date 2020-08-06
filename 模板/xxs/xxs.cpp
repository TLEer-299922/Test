#include <cstdio>
#include <cstring>
bool is_prim[100000001];
int n, k, prim[10000001], pnum = 0;
int main()
{
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    memset(is_prim, 1, sizeof(is_prim));
    is_prim[1] = 0;
    scanf("%d%d", &n, &k);
    int i, j, x;
    for (i = 2; i <= n; i++)
    {
        if (is_prim[i])
            prim[pnum++] = i;
        for (j = 0; j < pnum && i * prim[j] <= n; j++)
        {
            is_prim[prim[j] * i] = 0;
            if (i % prim[j] == 0)
                break;
        }
    }
    for (i = 0; i < k; i++)
    {
        scanf("%d", &x);
        printf("%d\n", prim[x - 1]);
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}