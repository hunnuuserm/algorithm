//https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/
//乘积为正数的最长子数组长度

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_pos(n);
        vector<int> dp_neg(n);
        if(nums[0] > 0)
        {
            dp_pos[0] = 1;
            dp_neg[0] = 0;
        }
        else if(nums[0] < 0)
        {
            dp_neg[0] = 1;
            dp_pos[0] = 0;
        }
        else
        {
            dp_pos[0] = dp_neg[0] = 0;
        }

        for(int i = 1;i < n;i++)
        {
            if(nums[i] > 0)
            {
                dp_pos[i] = dp_pos[i-1] + 1;
                dp_neg[i] = dp_neg[i-1] == 0? 0 : dp_neg[i-1] + 1;
            }
            else if(nums[i] < 0)
            {
                dp_pos[i] = dp_neg[i-1] == 0? 0 : dp_neg[i-1] + 1;
                dp_neg[i] = dp_pos[i-1] + 1;
                
            }
            else
            {
                dp_pos[i] = dp_neg[i] = 0;
            }
        }
        int ret = INT_MIN;
        for(int i = 0;i < n ;i++)
        {
            ret=max(ret,dp_pos[i]);
        }
        return ret;
    }
};