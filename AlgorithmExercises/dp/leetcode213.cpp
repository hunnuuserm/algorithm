//213. 打家劫舍 II
//https://leetcode.cn/problems/house-robber-ii/description/

  /*分类讨论 
  将一个环形问题转化为两个线性问题
  本题分为偷第一家和不偷第一家两个线性问题*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n>=4)
        {
            vector<int> f1(n-3);
            f1[0]=nums[2];
            vector<int> g1(n-3);
            for(int i=1;i<n-3;i++)
            {
                f1[i]=g1[i-1]+nums[i+2];
                g1[i]=max(f1[i-1],g1[i-1]);
            }
            int sum1=nums[0]+max(f1[n-4],g1[n-4]);
            vector<int> f2(n);
            vector<int> g2(n);
            f2[0]=nums[1];
            for(int i=1;i<n-1;i++)
            {
                f2[i]=g2[i-1]+nums[i+1];
                g2[i]=max(f2[i-1],g2[i-1]);
            }
            int sum2=max(f2[n-2],g2[n-2]);
            return max(sum1,sum2);
        }
        else
        {
            int ret=nums[0];
            for(int i=1;i<n;i++)
            {
                ret=max(ret,nums[i]);
            }
            return ret;
        }
    }
};
   