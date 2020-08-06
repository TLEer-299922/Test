#include <iostream>
#include <cstring>
bool a[101][101], b[101][101], flag = false;
int startx, starty, endx, endy, n;
void map(int x, int y)
{
    if (x == endx && y == endy)
    {
        flag = true;
        return;
    }
    a[x][y] = 1;
    if (x > 0 && !a[x - 1][y])
        map(x - 1, y);
    if (x + 1 < n && !a[x + 1][y])
        map(x + 1, y);
    if (y > 0 && !a[x][y - 1])
        map(x, y - 1);
    if (y + 1 < n && !a[x][y + 1])
        map(x, y + 1);
}
int main()
{
    int k;
    std::cin >> k;
    while (k--)
    {
        char c;
        memset(a, 1, sizeof(a));
        memset(b, 0, sizeof(b));
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> c;
                if (c == '.')
                    a[i][j] = 0;
            }
        }
        std::cin >> startx >> starty >> endx >> endy;
        map(startx, starty);
        if (flag)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
        flag = 0;
    }
}