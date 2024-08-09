//https://leetcode.cn/problems/maximum-subarray/
//leetcode53.最大子数组和

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]>=0)
            {
                dp[i]=dp[i-1]+nums[i];
            }
            else
            {
                dp[i]=nums[i];
            }
        }
        sort(dp.begin(),dp.end());
        return *(dp.end()-1);
    }
};