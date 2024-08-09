//https://leetcode.cn/problems/maximum-product-subarray/
//乘积最大子数组

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(n);
        vector<int> dp_min(n);
        dp_max[0] = dp_min[0] = nums[0];
        for(int i = 1;i < n ;i++)
        {
            dp_max[i] = max(nums[i]*dp_min[i-1],max(nums[i],nums[i]*dp_max[i-1]));
            dp_min[i] = min(nums[i]*dp_min[i-1],min(nums[i],nums[i]*dp_max[i-1]));
        }
        int ret = INT_MIN;
        for(int i =0; i < n ;i++)
        {
            ret=max(ret,dp_max[i]);
        }
        return ret;
    }
};