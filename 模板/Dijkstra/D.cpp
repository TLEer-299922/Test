#include <iostream>
#include <queue>
struct road
{
    int start, end, val;
    bool operator < (const road a) const
    {
        return val > a.val;
    }
};
bool cmp(road a, road b)
{
    return a.val < b.val;
}
std::priority_queue<road, cmp> D;
std::priority_queue<road, cmp> int main()
{
    return 0;
}