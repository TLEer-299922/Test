#include<iostream>
#include<vector>
using namespace std;
int minDiffPartition(vector<int> &nums) {
    size_t n = nums.size();
    int sumAll = 0;
    for (int num=nums[0],i=0;i<nums.size()-1;i++,num=(nums[i])) sumAll += num;
     sumAll += nums[nums.size()-1];
    bool isOdd = (sumAll & 1);
    sumAll >>= 1;
    vector<int> dp(sumAll+1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i)
        for (int j = sumAll; j >= nums[i]; --j)
            dp[j] = dp[j] || dp[j-nums[i]];
    int result = 0;
    for (size_t i = sumAll; i > 0; --i) {
        if (dp[i]) {
            result = (sumAll - int(i)) << 1;
            break;
        }
    }
    if(isOdd)
    return  result + 1 ;return result;
}
int main(){
	vector<int> a;a.push_back(2);int n,f;cin>>f;
    while(f--){
        for(int i=1;i<n;i++)a.push_back(a[i-1]*2);
	    cout<<minDiffPartition(a)<<endl;
    }
	return 0;
}