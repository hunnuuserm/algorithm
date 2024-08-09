//力扣123. 买卖股票的最佳时机 III
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

//根据题意，最后一天获得最大利润时有6中可能状态：
//即  第n天后，手中无股票，完成0笔交易
//    第n天后，手中无股票，完成1笔交易
//    第n天后，手中无股票，完成2笔交易
//    第n天后，手中有股票，完成0笔交易
//    第n天后，手中有股票，完成1笔交易
//    第n天后，手中有股票，完成2笔交易
//
//    本题中dp表f：
//    f[i][0] : 第i天后，手中无股票，完成0笔交易
//    f[i][1] : 第i天后，手中无股票，完成1笔交易
//    f[i][2] : 第i天后，手中无股票，完成2笔交易
//    dp表g：
//    g[i][0] : 第i天后，手中有股票，完成0笔交易
//    g[i][1] : 第i天后，手中有股票，完成1笔交易
//    g[i][2] : 第i天后，手中有股票，完成2笔交易

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> f(n,vector<int>(3));
        auto g=f;
        f[0][0]=0;
        g[0][0]=-prices[0];
        f[0][1]=0;
        g[0][1]=-prices[0];
        f[0][2]=0;
        g[0][2]=-prices[0];
        for(int i=1;i<n;i++)
        {
            f[i][0]=f[i-1][0];
            g[i][0]=max(g[i-1][0],f[i-1][0]-prices[i]);
            f[i][1]=max(f[i-1][1],g[i-1][0]+prices[i]);
            g[i][1]=max(g[i-1][1],f[i-1][1]-prices[i]);
            f[i][2]=max(f[i-1][2],g[i-1][1]+prices[i]);
            g[i][2]=max(g[i-1][2],f[i-1][2]-prices[i]);
        }
        int f_max=max(max(f[n-1][0],f[n-1][1]),f[n-1][2]);
        int g_max=max(max(g[n-1][0],g[n-1][1]),g[n-1][2]);
        return max(f_max,g_max);

    }
};