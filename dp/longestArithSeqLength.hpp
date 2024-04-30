//https://leetcode.cn/problems/longest-arithmetic-subsequence/
//最长等差数列

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        //方法2:
        int n = nums.size();
        unordered_map<int,int> hash;
        vector<vector<int>> dp(n,vector<int>(n,2));
        int ret = 2;
        hash[nums[0]] = 0;
        for(int i = 1;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                int sub = nums[j] - nums[i];
                if(hash.count(nums[i] - sub) && hash[(nums[i] - sub)] < i)
                {
                    dp[i][j] = dp[hash[nums[i] - sub]][i] + 1;
                }
                ret = max(ret,dp[i][j]);
            }
            hash[nums[i]] = i;
        }
        return ret;



        //写法1:
        int n = nums.size();
        unordered_map<int,vector<int>> hash;//关键:因为数组中可能有重复的元素，\
                                                所以这里不能单单采用 nums[i] : i这种\
                                                映射关系，因为nums[i]可能有多个下标，\
                                                所以用vector把所有值都为nums[i]的下标\
                                                保存在一起
        for(int i = 0;i < n;i++)
        {
            hash[nums[i]].push_back(i);
        }

        vector<vector<int>> dp(n,vector<int>(n,2));
        int ret = 2;
        for(int j = 2;j < n;j++)
        {
            for(int i = 1;i < j;i++)
            {
                int sub = nums[j] - nums[i];
                if(hash.count(nums[i] - sub))
                {
                    for(auto &e : hash[nums[i] - sub])
                    {
                        if(e < i) 
                        {
                            dp[i][j] = max(dp[i][j],dp[e][i] + 1);
                        }
                    }
                }
                ret = max(ret,dp[i][j]);
            }
        }
        return ret;

////////////////////////////////////////////////////////////
//下面代码通过不了这道题
        // int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,2));
        // int ret = INT_MIN;
        // for(int j = 2;j < n;j++)
        // {
        //     for(int i = 1;i < j;i++)
        //     {
        //         for(int k = 0;k < i;k++)
        //         {
        //             if(nums[i] - nums[k] == nums[j] - nums[i])
        //             {
        //                 dp[i][j] = max(dp[i][j],dp[k][i] + 1);
        //             }
        //             ret = max(ret,dp[i][j]);
        //         }
        //     }
        // }
        // return ret;



        // int n = nums.size();
        // unordered_map<int,int> hash;
        // for(int i = 0;i < n;i++)
        // {
        //     hash[nums[i]] = i;
        // }

        // vector<vector<int>> dp(n,vector<int>(n,2));
        // int ret = INT_MIN;
        // for(int j = 2;j < n;j++)
        // {
        //     for(int i = 1;i < j;i++)
        //     {
        //         int sub = nums[j] - nums[i];
        //         if(hash.count(nums[i] - sub) && hash[nums[i] - sub] < i)
        //         {
        //             dp[i][j] = dp[hash[nums[i] - sub]][i] + 1;
        //         }
        //         ret = max(ret,dp[i][j]);
        //     }
        // }
        // return ret;
    }
};