#include <iostream>
bool a[10002] = {false};
int main()
{
    int n, m, ans;
    std::cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        for (int j = x; j <= y; j++)
        {
            a[j] = 1;
        }
    }
    for (int i = 0; i <=n; i++)
    {
        if (!a[i])
            ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}