#include <iostream>
#include <vector>
#include <algorithm>
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
        nums[fatheri] = fatherj;
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
    bool is_liantong()
    {
        int s = nums.size();
        int k = 0;
        for (int i = 1; i <= s; i++)
        {
            if (nums[i] == i)
                k++;
        }
        return k == 1;
    }
    std::vector<int> nums;
};
struct Used
{
    int a, b, qz;
} s[200010];
bool cmp(Used a, Used b)
{
    return a.qz < b.qz;
}
int main()
{
    int n, m, qaq = 0, ans = 0;
    std::cin >> n >> m;
    Union a(n);
    Union b(n);
    for (int i = 0; i < m; i++)
    {
        std::cin >> s[i].a >> s[i].b >> s[i].qz;
        b.merge(s[i].a, s[i].b);
    }
    std::sort(s, s + m, cmp);
    if (!b.is_liantong())
    {
        std::cout << "orz" << std::endl;
        return 0;
    }
    int last;
    for (int i = 0; i < m; i++)
    {
        if (qaq == n - 1)
        {
            if (a.is_liantong())
            {
                break;
            }
            qaq--;
            a.nums[s[i - 1].a] = last;
            ans -= s[i - 1].qz;
        }
        if (!(a.is_bro(s[i].a, s[i].b)))
        {
            last = a.nums[s[i].a];
            a.merge(s[i].a, s[i].b);
            ans += s[i].qz;
            qaq++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
/*
4 5
1 2 1
2 3 2
3 1 3
4 2 4
4 3 5

8
*/
/*
4 5
1 2 2
1 3 2
1 4 3
2 3 4
3 4 3

7
*/