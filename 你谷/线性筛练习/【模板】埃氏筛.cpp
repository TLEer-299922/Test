#include <cstdio>
#include <cstring>
#include <cmath>
int prim[100000010], tot = 0, n, q;
bool is_prim[100000010];
int main()
{
    memset(is_prim, true, sizeof(is_prim));
    scanf("%d%d", &n, &q);
    is_prim[0] = is_prim[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (!is_prim[i])
            continue;
        prim[++tot] = i;
        for (int j = i * 2; j < n; j += i)
        {
            is_prim[j] = false;
        }
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        printf("%d\n", prim[n]);
    }
    return 0;
}