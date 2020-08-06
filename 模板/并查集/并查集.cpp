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
    int n, m;
    std::cin >> n >> m;
    Union a(n);
    int zi, xi, yi;
    for (int i = 0; i < m; i++)
    {
        std::cin >> zi >> xi >> yi;
        if (yi > xi)a.
            std::swap(xi, yi);
        if (zi == 1)
        {
            a.merge(xi, yi);
        }
        else
        {
            if (a.is_bro(xi, yi))
                std::cout << "Y" << std::endl;
            else
                std::cout << "N" << std::endl;
        }
    }
    return 0;
}
/*
10 20
1 4 8
1 1 2
1 7 2
2 6 8
1 3 2
2 9 5
1 7 1
2 9 10
1 1 5
2 1 9
1 4 8
2 7 9
2 9 1
2 9 6
2 10 8
1 3 5
1 6 10
1 4 8
2 5 4
1 8 4
*/