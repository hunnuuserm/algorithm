//746. 使用最小花费爬楼梯
//https://leetcode.cn/problems/min-cost-climbing-stairs/
class Solution {
public:
    int getMin(int a, int b)
    {
        return a < b ? a : b;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        size_t n = cost.size();
        dp.resize(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (size_t i = 2; i < cost.size() + 1; i++)
        {
            dp[i] = getMin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};