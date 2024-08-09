//174. 地下城游戏
//https://leetcode.cn/problems/dungeon-game/description/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dg) {
        size_t m=dg.size();
        size_t n=dg[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m-1][n]=dp[m][n-1]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=min(dp[i][j+1],dp[i+1][j])-dg[i][j];
                dp[i][j]=max(1,dp[i][j]);
            }
        }
        return dp[0][0];
    }
};