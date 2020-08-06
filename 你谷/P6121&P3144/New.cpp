#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
struct Union
{
    Union(int n)
    {
        nums.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            nums[i] = i;
        }
    }
    int merge(int i, int j)
    {
        int fatheri = find(i), fatherj = find(j);
        if (fatheri == fatherj)
            return 0;
        nums[fatheri] = fatherj;
        return 1;
    }
    int find(int n)
    {
        int s = n;
        while (nums[n] != n)
            n = nums[n];
        while (s != n)
        {
            int t = nums[s];
            nums[s] = n;
            s = t;
        }
        return n;
    }
    bool is_all()
    {
        int a = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == i)
                a++;
        }
        return a == 1;
    }
    void clear()
    {
        for (int i = 1; i < nums.size(); i++)
            nums[i] = i;
    }
    std::vector<int> nums;
};
struct line
{
    int x, y;
    void get()
    {
        std::cin >> x >> y;
    }
    void to_a(line a)
    {
        x = a.y;
        y = a.x;
    }
} a[200010], b[200010];
int c[200010];
bool ans[200010];
bool cmp(line a, line b)
{
    if (a.x != b.x)
        return a.x > b.x;
    return a.y > b.y;
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    Union A(n);
    for (int i = 0; i < m; i++)
        a[i].get();
    for (int i = 0; i < m; i++)
        b[i].to_a(a[i]);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];
    std::sort(a, a + m, cmp);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[j].x != c[i] && b[j].x != c[i])
                continue;
            A.merge(a[j].x, a[j].y);
        }
        ans[c[i]] = A.is_all();
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i + 1])
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}