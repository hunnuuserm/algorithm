//309. 买卖股票的最佳时机含冷冻期
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
/*dp[i][0]:以i结尾，第i天以“买入”状态获得的最大利润
  dp[i][1]:以i结尾，第i天以“可卖”状态获得的最大利润
  dp[i][2]:以i结尾，第i天以“卖出”状态获得的最大利润
  dp[i][3]:以i结尾，第i天以“冷冻期”状态获得的最大利润
  dp[i][4]:以i结尾，第i天以“可买”状态获得的最大利润

  且要对dp[0][1]进行特殊处理*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(5));
        dp[0][0]=-prices[0];
        dp[0][1]=dp[0][0];
        dp[0][2]=0;
        dp[0][3]=0;
        dp[0][4]=0;
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][3]-prices[i],max(dp[i-1][0],dp[i-1][4]-prices[i]));
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][2]=max(dp[i-1][2],max(dp[i-1][0]+prices[i],dp[i-1][1]+prices[i]));
            dp[i][3]=dp[i-1][2];
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]);
        }
        int max_sum=dp[n-1][0];
        for(int i=1;i<=4;i++)
        {
            max_sum=max(max_sum,dp[n-1][i]);
        }

        return max_sum;
    }
};
