#include <iostream>
int ax[100010], ay[100010], bx[100010], by[100010], n, px, py, ans = -1;
int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> ax[i] >> ay[i] >> px >> py;
        bx[i] = ax[i] + px;
        by[i] = ay[i] + py;
    }
    std::cin >> px >> py;
    for (int i = 0; i < n; i++)
        if ((px >= ax[i] && px <= bx[i]) && (py >= ay[i] && py <= by[i]))
            ans = i + 1;
    std::cout << ans << std::endl;
    return 0;
}