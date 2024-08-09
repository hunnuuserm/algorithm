//64. 最小路径和
//https://leetcode.cn/problems/minimum-path-sum/description/

class Solution {
public:
    int minPathSum(vector<vector<int>>& gd) {
        size_t m=gd.size();
        size_t n=gd[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[1][1]=gd[0][0];
        for(size_t j=2;j<=n;j++)
        {
            dp[1][j]=gd[0][j-1]+dp[1][j-1];
        }
        for(size_t i=2;i<=m;i++)
        {
            for(size_t j=1;j<=n;j++)
            {
                dp[i][j]=gd[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};