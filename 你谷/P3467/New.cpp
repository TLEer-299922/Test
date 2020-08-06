#include <iostream>
int n, x, t, ans;
int zhan[2500010] = {999999999}, top = 0;
int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> t >> x;
        while (x <= zhan[top])
        {
            if (x == zhan[top])
                ans++;
            top--;
        }
        zhan[++top] = x;
    }
    std::cout << n - ans << std::endl;
}