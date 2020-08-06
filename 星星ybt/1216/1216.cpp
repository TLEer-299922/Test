#include <iostream>
#include <cstring>
int Is_Black[30][30];
int ans, n, m, xn, yn, nextn, nextm;
void go(int x, int y)
{
    ans++;
    Is_Black[x][y] = 2;
    if (x < n - 1 && Is_Black[x + 1][y] == 1)
        go(x + 1, y);
    if (y < m - 1 && Is_Black[x][y + 1] == 1)
        go(x, y + 1);
    if (x > 0 && Is_Black[x - 1][y] == 1)
        go(x - 1, y);
    if (y > 0 && Is_Black[x][y - 1] == 1)
        go(x, y - 1);
}
int main()
{
    char c;
    std::cin >> nextm >> nextn;
    
    do
    {
        memset(Is_Black, 0, sizeof(Is_Black));
        m = nextm, n = nextn;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> c;
                if (c != '#')
                    Is_Black[i][j] = 1;
                if (c == '@')
                    xn = i, yn = j;
            }
        }
        std::cin >> nextm >> nextn;
        go(xn, yn);
        std::cout << ans << std::endl;
        ans = 0;
    } while (nextm && nextn);
    return 0;
}