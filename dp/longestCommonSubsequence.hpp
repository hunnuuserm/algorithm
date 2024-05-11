//https://leetcode.cn/problems/longest-common-subsequence/
//两个字符串的最长公共子序列的长度

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        s1 = " " + s1;
        s2 = " " + s2;
        vector<vector<int>> dp(m + 1,vector<int>(n + 1));
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};