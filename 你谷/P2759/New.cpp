#include <iostream>
#include <cmath>
long long n;
long long f(long long x)
{
    return x * log10(x);
}
int main()
{
    std::cin >> n;
    long long l = 1, r = 2e9 + 1, oldl, oldr;
    while (l < r)
    {
        long long m = (l + r) >> 1;
        if (f(m) < n - 1)
            l = m + 1;
        else
            r = m;
    }
    long long ans = l;
    for (; f(ans) == f(l); ans--)
        ;
    std::cout << ans + 1 << std::endl;
    return 0;
}