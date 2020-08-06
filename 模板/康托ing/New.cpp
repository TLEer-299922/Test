#include <iostream>
long long a[100010];
long long jiec(long long n)
{
    if (n == 0)
        return 0;
    long long t = n;
    while (--n)
        t *= n;
    return t;
}
int main()
{
    long long n;
    std::cin >> n;
    long long a[n + 1];
    for (long long i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    long long ans = 1;
    for (long long i = 0; i < n; i++)
    {
        ans += (a[i] - 1) * jiec(n - i - 1);
    }
    std::cout << ans << std::endl;
    return 0;
    // freopen("a.out", "w", stdout);
    // for (long long i = 1; i <= 100000; i++)
    // {
    //     std::cout << jiec(i) << ',';
    // }
    // std::cout << std::endl;
    // fclose(stdout);
}