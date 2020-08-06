#include <iostream>
using namespace std;
bool c[26];
int l[21][21], ans = 1, lujing[1000][2];
void print(int n, int lj[1000][2])
{
    for (int i = 0; i <= n; i++)
        cout << '(' << lj[i][0] << ',' << lj[i][1] << "),";
    cout << endl;
}
void bfs(int x, int y, bool a[26], int s, int lj[1000][2], int dii)
{
    bool alpha = 0;
    if (a[l[x + 1][y]] == 0)
    {
        dii++;
        a[l[x + 1][y]] = 1;
        lj[dii][0] = x + 1;
        lj[dii][1] = y;
        bfs(x + 1, y, a, s + 1, lj, dii);
        alpha = 1;
    }
    dii--;
    if (a[l[x][y + 1]] == 0)
    {
        dii++;
        a[l[x][y + 1]] = 1;
        lj[dii][0] = x;
        lj[dii][1] = y + 1;
        bfs(x, y + 1, a, s + 1, lj, dii);
        alpha = 1;
    }
    dii--;
    if (a[l[x - 1][y]] == 0)
    {
        dii++;
        a[l[x - 1][y]] = 1;
        lj[dii][0] = x - 1;
        lj[dii][1] = y;
        bfs(x - 1, y, a, s + 1, lj, dii);
        alpha = 1;
    }
    dii--;
    if (a[l[x][y - 1]] == 0)
    {
        dii++;
        lj[dii][0] = x;
        lj[dii][1] = y - 1;
        a[l[x][y - 1]] = 1;
        bfs(x, y - 1, a, s + 1, lj, dii);
        alpha = 1;
    }
    dii--;
    if (!alpha)
        if (ans <= s)
            ans = s, print(dii + 1, lj);
}
int main()
{
    // freopen("a.in","r",stdin);
    /*freopen("a.out", "w", stdout);*/
    int n, m;
    char f;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> f;
            /*cout << f << ' ';*/
            l[i][j] = (int)(f - 'A');
        }
    }
    lujing[0][0] = 0;
    lujing[0][1] = 0;
    bfs(0, 0, c, ans, lujing, 0);
    cout << ans << endl;
    
    /*fclose(stdout);*/
    return 0;
}