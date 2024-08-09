//https://leetcode.cn/problems/longest-palindromic-substring/
//最长回文子串

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        string ret;
        for(int i = n-1;i >= 0;i--)
        {
            for(int j = i;j < n;j++)
            {
                if(s[i] == s[j])
                {
                    if(i == j || i + 1 == j)
                    {
                        dp[i][j] = true;
                        if(ret.size() < s.substr(i,j-i+1).size())
                            ret = s.substr(i,j-i+1);
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                        if(dp[i][j])
                        {
                            if(ret.size() < s.substr(i,j-i+1).size())
                                ret = s.substr(i,j-i+1);
                        }

                    }
                }
            }
        }
        return ret;
    }
};