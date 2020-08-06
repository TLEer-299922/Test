#include <cstdio>
#include <queue>
struct num
{
    int bh, val;
} s[1000010];
std::deque<num> a;
int main()
{
    int n, m, size = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i].val);k
        s[i].bh = i;
    }
    for (int i = 1; i <= n; i++)
    {
        while (!a.empty() && a.front().bh <= i - m)
            a.pop_front();
        while (!a.empty() && a.back().val >= s[i].val)
            a.pop_back();
        a.push_back(s[i]);
        size++;
        if (i > k)
            printf("%d ", a.front().val);
    }
    printf("\n");
    a.clear();
    size = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!a.empty() && a.front().bh <= i - m)
            a.pop_front();
        while (!a.empty() && a.back().val <= s[i].val)
            a.pop_back();
        a.push_back(s[i]);
        size++;
        if (i > 2)
            printf("%d ", a.front().val);
    }
    printf("\n");
    return 0;
}