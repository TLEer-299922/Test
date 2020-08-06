#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
std::map<std::string, std::string> nums;
std::string find(std::string n)
{
    return nums[n] == n ? n : find(nums[n]);
}
void merge(std::string i, std::string j)
{
    std::string fatheri = find(i), fatherj = find(j);
    if (fatheri == fatherj)
        return;
    nums[fatherj] = fatheri;
}
int main()
{
    char c;
    std::string name, last;
    std::cin >> c;
    while (c != '$')
    {
        std::cin >> name;
        if (nums[name] == "")
            nums[name] = name;
        if (c == '#')
            last = name;
        if (c == '+')
            merge(last, name);
        if (c == '?')
            std::cout << name << ' ' << find(name) << std::endl;
        std::cin >> c;
    }
    return 0;
}