#include <iostream>
#include <vector>
#include <algorithm>
struct village
{
    int size, xiab;
} a[310];
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
    void merge(int i, int j)
    {
        int fatheri = find(i), fatherj = find(j);
        if (fatheri == fatherj)
            return;
        if (a[fatheri].size < a[fatherj].size)
            nums[fatheri] = fatherj;
        else
            nums[fatherj] = fatheri;
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
    bool is_bro(int i, int j)
    {
        int fi = find(i), fj = find(j);
        return fi == fj;
    }
    int jinum()
    {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i == nums[i])
                ans++;
        }
        return ans;
    }
    std::vector<int> nums;
};

bool cmp(village a, village b)
{
    return a.size > b.size;
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    Union A(n);
    for (int i = 1; i <= n; i++)
    {
        a[i].xiab = i;
        std::cin >> a[i].size;
    }
    int x, y;
    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        if (a[x].size == a[y].size)
        {
            std::cout << "merge~" << std::endl;
            continue;
        }
        A.merge(x, y);
    }
    if (A.jinum() != 1 || m < (n - 1))
    {
        std::cout << "Non" << std::endl;
        return 0;
    }
    std::sort(a + 1, a + n + 1, cmp);
    if (a[1].size == a[2].size)
    {
        std::cout << "Non" << std::endl;
        return 0;
    }
    std::cout << "Oui, j'ai trouve la solution." << std::endl
              << a[1].xiab << std::endl;
    return 0;
}