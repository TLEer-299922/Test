#include <iostream>
unsigned long long n, ans = 18446744073709551610;
void fs(unsigned long long s)
{
    if (s > 184467440737095516)
        return;
    if (s % n == 0)
    {
        if (ans > s / n)
            ans = s / n;
        return;
    }
    fs(s * 10);
    fs(s * 10 + 1);
}
int main()
{
    std::cin >> n;
    fs(1);
    if (ans == 18446744073709551610)
        std::cout << "No Solution" << std::endl;
    else 
        std::cout << ans << std::endl;
    return 0;
}