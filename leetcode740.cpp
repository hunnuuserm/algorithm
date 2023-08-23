//740. 删除并获得点数
//https://leetcode.cn/problems/delete-and-earn/description/

//把本题优化成打家劫舍问题即可
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> table(1e4+1);
        for(int i=0;i<nums.size();i++)
        {
            table[nums[i]]+=nums[i];
        }
        vector<int> f(1e4+1);
        auto g=f;
        f[0]=table[0];
        for(int i=1;i<1e4+1;i++)
        {
            f[i]=g[i-1]+table[i];
            g[i]=max(f[i-1],g[i-1]);
        }
        return max(f[1e4],g[1e4]);
    }
};