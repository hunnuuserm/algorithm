//714. 买卖股票的最佳时机含手续费
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

//dp[i][0]:第i天结束后，处于“买入”状态，此时的最大利润
//dp[i][0]:第i天结束后，处于“可买”状态，此时的最大利润

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            int n=prices.size();
            vector<vector<int>> dp(n,vector<int>(2));
            dp[0][0]=-prices[0];
            dp[0][1]=0;
            for(int i=1;i<n;i++)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]-fee);
            }
            return max(dp[n-1][0],dp[n-1][1]);
    }
};