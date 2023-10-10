//面试题 17.16. 按摩师
//https://leetcode.cn/problems/the-masseuse-lcci/description/


class Solution {
public:
    int massage(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> f(n);
        auto g=f;
        f[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            f[i]=g[i-1]+nums[i];
            g[i]=max(f[i-1],g[i-1]);
        }
        return max(f[n-1],g[n-1]);
    }
};