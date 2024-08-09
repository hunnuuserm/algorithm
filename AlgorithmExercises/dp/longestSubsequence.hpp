//https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/
//最长定差子序列

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        //方法2:
        int n = arr.size();
        vector<int> dp(n,1);
        unordered_map<int,int> hash;
        hash[arr[0]] = 0;
        int ret = 1;
        for(int i = 1;i < n;i++)
        {
            if(hash.count(arr[i] - difference))
            {
                dp[i] = dp[hash[arr[i] - difference]] + 1;
            }
            ret = max(ret,dp[i]);
            hash[arr[i]] = i;
        }
        return ret;

        //方法1:
        // int n = arr.size();
        // unordered_map<int,int> hash;//arr[i]:dp[i]
        // hash[arr[0]] = 1;
        // int ret  = hash[arr[0]];
        // for(int i = 1;i < n;i++)
        // {
        //     hash[arr[i]] = hash[arr[i] - difference] + 1;
        //     ret = max(ret,hash[arr[i]]);
        // }
        // return ret;



        //下面代码会超时:
        // int n = arr.size();
        // vector<int> dp(n,1);
        // dp[0] = 1;
        // for(int i = 1;i < n;i++)
        // {
        //     for(int j = 0;j < i;j++)
        //     {
        //         if(arr[i] - arr[j] == difference)
        //         {
        //             dp[i] = max(dp[i],dp[j] + 1);
        //         }
        //     }
        // }
        // int ret = INT_MIN;
        // for(int i = 0;i < n;i++)
        // {
        //     ret = max(ret,dp[i]);
        // }
        // return ret;
    }
};