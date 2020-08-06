#include <cstdio>
long long mod(long long base, long long b, long long k)
{
    long long ans = 1;
    // base %= k;
    // b %= k;
    if (base == 0 && b == 0)
        return 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= base;
            ans %= k;
        }
        base *= base;
        base %= k;
        b >>= 1;
    }
    return ans %= k;
}
int main()
{
    long long b, p, k;
    scanf("%lld%lld%lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, mod(b, p, k));
    return 0;
}