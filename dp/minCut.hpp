//https://leetcode.cn/problems/palindrome-partitioning-ii/
//分割回文串 II

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n,vector<bool>(n));
        for(int i = n-1;i >= 0;i--)
        {
            for(int j = i;j < n;j++)
            {
                if(s[i] == s[j])
                {
                    if(i == j || i + 1 == j)
                    {
                        isPal[i][j] = true;
                    }
                    else
                    {
                        isPal[i][j] = isPal[i+1][j-1];
                    }
                }
            }
        }
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i < n;i++)
        {
            if(isPal[0][i])
                dp[i] = 0;
            else
            {
                for(int j = 1;j <= i;j++)
                {
                    if(isPal[j][i])
                    {
                        dp[i] = min(dp[i],dp[j-1] + 1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};