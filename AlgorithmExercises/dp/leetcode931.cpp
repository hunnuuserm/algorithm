//931. 下降路径最小和
//https://leetcode.cn/problems/minimum-falling-path-sum/

class Solution {
public:
    int getMin(int a,int b,int c)
    {
        int min=a<b?a:b;
        min=min<c?min:c;
        return min;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        size_t n=matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,10001));
        for(size_t i=1;i<n+1;i++)
        {
            dp[1][i]=matrix[0][i-1];
        }
        for(size_t i=2;i<n+1;i++)
        {
            for(size_t j=1;j<n+1;j++)
            {
                dp[i][j]=matrix[i-1][j-1]+getMin(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
            }
        }
        int ret=dp[n][1];
        for(size_t i=2;i<n+1;i++)
        {
            ret=min(ret,dp[n][i]);
        }
        return ret;
    }
};