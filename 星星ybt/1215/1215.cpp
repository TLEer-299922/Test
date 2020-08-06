#include <iostream>
#include <cstring>
int xn, yy, n;
bool a[1001][1001], flag = false;
void bfs(int x, int y)
{
    if (x == xn && y == yy)
    {
        flag = 1;
        return;
    }
    a[x][y] = 1;
    if (x - 1 >= 0 && !a[x - 1][y])
    {
        bfs(x - 1, y);
    }
    if (x + 1 < n && !a[x + 1][y])
    {
        bfs(x + 1, y);
    }
    if (y - 1 >= 0 && !a[x][y - 1])
    {
        bfs(x, y - 1);
    }
    if (y + 1 < n && !a[x][y + 1])
    {
        bfs(x, y + 1);
    }
    /*
	2
	3
	.##
	..#
	#..
	0 0 2 2
	5
	.....	
	###.#
	..#..
	###..
	...#.
	0 0 4 0
*/
}
int main()
{
    int k;
    std::cin >> k;
    while (k--)
    {
        std::memset(a, 1, sizeof(a));
        int beginx, beginy;
        char c;
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
        std::cin >> beginx >> beginy >> xn >> yy;
        if (a[xn][yy] || a[beginx][beginy])
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        bfs(beginx, beginy);
        if (flag)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
        flag = 0;
    }
    return 0;
}