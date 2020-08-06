#include <iostream>
#include <map>
#include <cmath>
#include <string>
struct Union
{
    void merge(std::string i, std::string j)
    {
        std::string fatheri = find(i), fatherj = find(j);
        if (fatheri == fatherj)
            return;
        nums[fatheri] = fatherj;
    }
    std::string find(std::string n)
    {
        std::string s = n;
        while (nums[n] != n)
            n = nums[n];
        while (s != n)
        {
            std::string t = nums[s];
            nums[s] = n;
            s = t;
        }
        return n;
    }
    bool is_bro(std::string i, std::string j)
    {
        std::string fi = find(i), fj = find(j);
        return fi == fj;
    }
    std::map<std::string, std::string> nums;
};
int main()
{
    int n, m;
    std::cin >> n >> m;
    Union a;
    std::string xi, yi;
    for (int i = 0; i < n; i++)
    {
        std::cin >> xi;
        a.nums[xi] = xi;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> xi >> yi;
        a.merge(xi, yi);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        std::string aa, b;
        std::cin >> aa >> b;
        if (a.is_bro(aa, b))
            std::cout << "Yes." << std::endl;
        else
            std::cout << "No." << std::endl;
    }
    return 0;
}