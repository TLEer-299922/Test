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
        // int fatheri = find(i), fatherj = find(j);
        // if (fatheri == fatherj)
        //     return;
        nums[i] = j;
    }
    int find(int n)
    {
        int s = n;
        while (nums[n] != n)
            n = nums[n];
        // while (s != n)
        // {
        //     int t = nums[s];
        //     nums[s] = n;
        //     s = t;
        // }
        return n;
    }
    bool is_bro(int i, int j)
    {
        int fi = find(i), fj = find(j);
        return fi == fj;
    }
    void clear()
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = i;
        }
    }
    int brothernum(int n)
    {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (is_bro(i, n))
                ans++;
        }
        return ans;
    }
    std::vector<int> nums;
};
struct line
{
    int x, y, qz;
} list[5001];
bool cmp(line n, line m)
{
    return n.qz < m.qz;
}
int main()
{
    int n, qnum, q[5010][2];
    std::cin >> n >> qnum;
    Union H(n);
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> list[i].x >> list[i].y >> list[i].qz;
    }
    std::sort(list, list + n - 1, cmp);
    for (int i = 0; i < qnum; i++)
    {
        std::cin >> q[i][0] >> q[i][1];
    }
    for (int i = 0; i < qnum; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (list[j].qz < q[i][0])
                continue;
            H.merge(list[j].x, list[j].y);
        }
        std::cout << H.brothernum(q[i][1]) << std::endl;
        H.clear();
    }
    return 0;
}