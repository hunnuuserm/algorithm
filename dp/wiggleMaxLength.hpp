//摆动序列
//https://leetcode.cn/problems/wiggle-subsequence/
//解析:看笔记

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> up(n,1);
        vector<int> down(n,1);
        up[0] = 1;
        down[0] = 1;
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[i] > nums[j])
                {
                    up[i] = max(up[i],down[j]+1);
                }
            }
            for(int j = 0;j < i;j++)
            {
                if(nums[i] < nums[j])
                {
                    down[i] = max(up[j]+1,down[i]);
                }
            }
        }
        int ret = INT_MIN;
        for(int i = 0;i < n;i++)
        {
            ret=max(ret,max(up[i],down[i]));
        }
        return ret;
    }
};