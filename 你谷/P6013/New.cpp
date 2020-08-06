#include <iostream>
using std::cin;
using std::cout;
using std::endl;
long long nowmon, ans = 0, x, have_mon[1000010], fynum = 1, m, y;
int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (i)
            have_mon[i] += have_mon[i - 1];
        if (x == 3)
        {
            cin >> x >> y;
            have_mon[y - 1] += x;
            have_mon[i] -= x;
        }
        else if (x == 2)
        {
            cin >> y;
            if (have_mon[i] < y)
                ans++;
            else
                have_mon[i] -= y;
        }
        else
        {
            cin >> y;
            have_mon[i] += y;
        }
    }
    cout << ans << endl;
    return 0;
}