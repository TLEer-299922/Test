#include <iostream>
int main()
{
    int nowmon, inmom = 0;
    int ys[12];
    for (int i = 0; i < 12; i++)
        std::cin >> ys[i];
    for (int i = 0; i < 12; i++)
    {
        nowmon += 300;
        nowmon -= ys[i];
        if (nowmon < 0)
        {
            std::cout << '-' << i + 1 << std::endl;
            return 0;
        }
        if (nowmon >= 100)
        {
            int m = nowmon / 100;
            inmom += m * 100;
            nowmon -= m * 100;
        }
    }
    nowmon += inmom * 1.2;
    std::cout << nowmon << std::endl;
    return 0;
}