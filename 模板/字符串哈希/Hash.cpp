#include <iostream>
#include <string>
#include <algorithm>
#define p 212370440130137957
#define mod 1610612741
#define ULL unsigned long long
ULL hashc[100001];
std::string c[100001];
ULL hash(std::string s)
{
    int len = s.size();
    ULL ans = 0;
    for (int i = 0; i < len; i++)
        ans = (ans * p + (ULL)s[i]) % mod;
    return ans;
}
int main()
{
    int n;
    std::cin >> n;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
        hashc[i] = hash(c[i]);
    }
    std::sort(hashc, hashc + n);
    for (int i = 1; i < n; i++)
    {
        if (hashc[i] == hashc[i - 1])
            ans--;
    }
    std::cout << ans << std::endl;
    return 0;
}