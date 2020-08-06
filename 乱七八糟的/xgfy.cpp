
#include <iostream>
#include <cstring>
using namespace std;
char s[110];
int b[110][110];
struct node
{
    int r, c, d;
} a[10100];
int rule[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main()
{
    int n, m, h = 1, t = 1, r, c, d, testr, testc, ans = 0, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        for (j = 0; j < n; j++)
            if (s[j] == '.')
                b[i][j] = 0;
            else if (s[j] == '@')
            {
                b[i][j] = 1;
                a[t].r = i;
                a[t].c = j;
                a[t].d = 1;
                t++;
            }
            else if (s[j] == '#')
                b[i][j] = 2;
    }
    cin >> m;
    while (h < t)
    {
        r = a[h].r;
        c = a[h].c;
        d = a[h].d;
        if (d == m)
            break;
        for (i = 0; i < 4; i++)
        {
            testr = r + rule[i][0];
            testc = c + rule[i][1];
            if (b[testr][testc] == 0 && 0 <= testr && testr < n && 0 <= testc && testc < n)
            {
                a[t].r = testr;
                a[t].c = testc;
                a[t].d = d + 1;
                b[testr][testc] = 1;
                t++;
            }
        }
        h++;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (b[i][j] == 1)
                ans++;
    cout << ans << endl;
    return 0;
}