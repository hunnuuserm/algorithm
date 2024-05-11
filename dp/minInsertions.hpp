//https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
//让字符串成为回文串的最少插入次数

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = n - 1;i >= 0;--i)
        {
            for(int j = i;j < n;++j)
            {
                if(s[i] == s[j])
                {
                    if(i == j || i + 1 == j)//判断不能省略，否则到else就越界；当然可以另int j = i + 1,此时可以省略本行判断
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                else
                {
                    if(i + 1 == j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i+1][j-1] + 2,min(dp[i+1][j] + 1,dp[i][j-1] + 1));
                }
            }
        }
        return dp[0][n-1];
    }
};