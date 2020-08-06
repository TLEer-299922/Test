#include <iostream>
#include <queue>
#include <vector>
std::priority_queue<int, std::vector<int>, std::greater<int> > a;
int main()
{
    int n;
    std::cin >> n;
    int x, ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        a.push(x);
    }
    while (a.size() != 1)
    {
        int s = a.top();
        a.pop();
        s += a.top();
        a.pop();
        a.push(s);
        ans += s;
    }
    std::cout << ans << std::endl;
    return 0;
}