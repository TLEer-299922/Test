#include <cstdio>
inline int fread()
{
    char c;
    int negidt, n = 0;
    c = getchar();
    while (c < '0' && c > '9')
        c = getchar();

    while (c >= '0' && c <= '9')
    {
        n *= 10;
        n += c - '0';
        c = getchar();
    }
    // printf("%d\n", n);
    return n;
}
int x_a[40005], x_b[40005], x_c[40005], x_d[40005], n, m, x_i[40005], buck[40005];
int main()
{
    int a, b, c, d;
    n = fread();
    m = fread();
    for (int i = 1; i <= m; i++)
        x_i[i] = fread(), buck[x_i[i]]++;
    for (int i = 1; i * 9 < n; i++)
    {              //i为t
        int p = 0; //前缀和
        for (int j = i * 9 + 2; j <= n; j++)
        { //j为x_d
            d = j;
            c = j - i;
            a = j - i * 9 - 1;
            b = a + i * 2;
            p += buck[a] * buck[b];
            x_c[c] += buck[d] * p;
            x_d[d] += buck[c] * p;
        }
        p = 0;
        for (int j = n - 9 * i - 1; j > 0; j--)
        { //j为x_a
            b = j + 2 * i;
            a = j;
            c = 1 + b + 6 * i;
            d = 1 + a + 9 * i;
            p += buck[c] * buck[d];
            x_a[a] += buck[b] * p;
            x_b[b] += buck[a] * p;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d %d %d %d\n", x_a[x_i[i]], x_b[x_i[i]], x_c[x_i[i]], x_d[x_i[i]]);
    }
}
//详见.md文件
/*
xa<xb<xc<xd
Xb−Xa=2(Xd−Xc)
x_b-x_a<(x_c-x_b)/3xb−xa<(xc−xb)/3
 */