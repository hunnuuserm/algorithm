//https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/
//等差数列划分 II - 子序列，即求一个数组中所有等差子序列的数目

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n));
        // unordered_map<int,int> hash;
        // hash[nums[0]] = 0;
        long long ret = 0;
        for(int i = 1;i < n;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                for(int t = 0;t < i;t++)//这里如果不采用第三层for循环，可以采用另一种方法即在最开始的时候设置一个unordered_map<long long, vector<int>> hash，来保存nums[i]及其下标的映射关系(这种采用hash映射的方法会提高一点效率，这里就不写了，要看的话看课件)
                {
                    long long numsj = nums[j];
                    long long numsi = nums[i];
                    long long numst = nums[t];
                    long long sub1 = numsj - numsi;
                    long long sub2 = numsi - numst;
                    if(sub2 == sub1)
                    {
                        dp[i][j] += dp[t][i];
                        dp[i][j] += 1;
                    }
                    // if(nums[j] - nums[i] == nums[i] - nums[t])
                    // {
                    //     dp[i][j] += dp[t][i];
                    //     dp[i][j] += 1;
                    // }
                }
            }
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                ret += dp[i][j];
            }
        }
        return ret;
    }
};