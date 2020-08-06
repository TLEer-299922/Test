#include <iostream>
#include <cmath>
int main()
{
    int n;
    std::cin >> n;
    int ts = std::ceil(std::sqrt(n));
    for (int i = i; i <= ts; i--)
    {
        if (n % i == 0)
        {
            std::cout << n / i << std::endl;
            return 0;
        }
    }
}