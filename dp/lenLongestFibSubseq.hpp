//https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/
//最长的斐波那契子序列长度

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map <int,int> hash;
        for(int i = 0;i < n;i++)
        {
            hash[arr[i]] = i;
        }

        vector<vector<int>> dp(n,vector<int>(n,2));

        int ret = INT_MIN;
        for(int j = 2;j < n;j++)
        {
            for(int i = 1;i < j;i++)
            {
                int a = arr[j] - arr[i];
                if(hash.count(a) && a < arr[i])
                {
                    dp[i][j] = dp[hash[a]][i] + 1;                    
                }
                ret = max(ret,dp[i][j]);
            }
        }
        return ret < 3 ? 0 : ret;
    }
};