#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[3], ans;
//6 5 9
bool to()
{
    sort(a, a + 3);
    int ab = abs(a[0] - a[1]);
    int bc = abs(a[1] - a[2]);
    int ac = abs(a[0] - a[2]);
    if (ab == 1 && bc == 1 || bc == 1 && ac == 1 || ac == 1 && ab == 1)
        return false;
    if (ab > bc)
        if (a[0] < a[1])
            a[2] = a[0] + 1;
        else
            a[2] = a[1] + 1;
    else if (a[1] > a[2])
        a[0] = a[2] + 1;
    else
        a[0] = a[1] + 1;
    return true;
}
int main()
{
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    while (to())
        ans++;
    printf("%d\n", ans);
    return 0;
}