#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
std::vector<int>nums;
int tot;
struct cloud
{
    int val, price;
}a[50010];
inline int find(int n)
{
    return nums[n] == n ? n : nums[n]=find(nums[n]);
}
inline void merge(int i, int j)
{
    int fatheri = find(i), fatherj = find(j);
    if (fatheri == fatherj)
        return;
    nums[fatherj] = fatheri;
}
inline void cs(int n) {
    nums.resize(n+1);
    for (int i=0;i<=n;i++)nums[i]=i;
}
int dp[50010];
int main()
{
    int mon, n, m;
    std::cin>>n>>m>>mon;
    cs(n);
    int x, y;
    for (int i=1;i<=n;i++) {
        std::cin>>a[i].price>>a[i].val;
    }
    for (int i=1;i<=m;i++) {
        std::cin>>x>>y;
        merge(x, y);
    }
    for (int i=1;i<=n;i++) {
        if (nums[i]!=i) {
            a[find(i)].price+=a[i].price;
            a[find(i)].val+=a[i].val;
            a[i].price=0;a[i].val=0;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=mon;j>=a[i].price;j--) {
            dp[j]=std::max(dp[j], dp[j-a[i].price]+a[i].val);
        }
    }
    std::cout<<dp[mon]<<std::endl;
    return 0;
}