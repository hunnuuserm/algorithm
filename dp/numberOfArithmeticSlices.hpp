//https://leetcode.cn/problems/arithmetic-slices/
//等差数列划分

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n =nums.size();
        if(n < 3) return 0;

        vector<int> dp(n);
        dp[0]=dp[1]=0;
        for(int i=2;i<n;i++)
        {
            dp[i] = (nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) ? dp[i-1]+1 : 0;
        }
        int ret = 0;
        for(int i=0;i<n;i++)
        {
            ret+=dp[i];
        }
        return ret;
    }
};