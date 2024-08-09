//剑指 Offer 47. 礼物的最大价值
//https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/

class Solution {
public:
    int getMax(int a,int b)
    {
        return a>b?a:b;
    }
    int maxValue(vector<vector<int>>& grid) {
        size_t m=grid.size();
        size_t n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(size_t i=1;i<=m;i++)
        {
            for(size_t j=1;j<=n;j++)
            {
                dp[i][j]=grid[i-1][j-1]+getMax(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};