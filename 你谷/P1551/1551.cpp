#include <iostream>
#include <vector>
#include <cmath>
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
    std::vector<int> nums;
};
int main()
{
    int n, m, p;
    std::cin >> n >> m >> p;
    Union a(n);
    int zi, xi, yi;
    for (int i = 0; i < m + p; i++)
    {
        std::cin >> xi >> yi;
        if (yi > xi)
            std::swap(xi, yi);
        if (i < m)
        {
            a.merge(xi, yi);
        }
        else
        {
            if (a.is_bro(xi, yi))
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        }
    }
    return 0;
}