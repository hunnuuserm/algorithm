//91. 解码方法
//https://leetcode.cn/problems/decode-ways/


class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
        {
            return 0;
        }
        vector<int> dp(s.size());
        dp[0] = 1;
        if (s.size() == 1)
        {
            return 1;
        }
        if (s[1] != '0')
        {
            dp[1] += 1;
        }
        int sum1 = (s[0] - '0') * 10 + s[1] - '0';
        if (sum1 >= 10 && sum1 <= 26)
        {
            dp[1] += 1;
        }
        for (size_t i = 2; i < s.size(); i++)
        {
            int sum = s[i] - '0';//单独解码
            if (sum > 0 && sum <= 9)
            {
                dp[i] += dp[i - 1];
            }

            sum = (s[i - 1] - '0') * 10 + s[i] - '0';//与前一位一起解码
            if (sum >= 10 && sum <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size() - 1];

        /*
        vector<int> dp(s.size());
        if(s[0]=='0')
        {
            return 0;
        }
        dp[0]=1;
        if(s.size()==1)
        {
            return 1;
        }
        if(s[0]>'2'&&s[1]=='0')
        {
            return 0;
        }

        if(s[1]>'6'&&s[0]=='2')
        {
            dp[1]=1;
        }
        else if(s[0]>'2')
        {
            dp[1]=1;
        }
        else if(s[1]=='0')
        {
            dp[1]=1;
        }
        else
        {
            dp[1]=2;
        }
        for(size_t i=2;i<s.size();i++)
        {
            if(s[i]=='0'&&s[i-1]<='2'&&s[i-1]>'0')
            {
                dp[i]=dp[i-2];
            }
            else if(s[i]=='0'&&s[i-1]>'2')
            {
                return 0;
            }
             else if(s[i]=='0'&&s[i-1]=='0')
            {
                return 0;
            }
            else if(s[i-1]=='0')
            {
                dp[i]=dp[i-1];
            }
            else if(s[i]>'6'&&s[i-1]=='2')
            {
                dp[i]=dp[i-1];
            }
            else if(s[i-1]>'2')
            {
                dp[i]=dp[i-1];
            }
            else
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[dp.size()-1];
        // if(s[i-1]==0)
        // {
        //     dp[i]=dp[i-1];
        // }
        // else
        // {
        //     if(dp[i-1]>'2')
        //     {
        //         dp[i]=dp[i-1];
        //     }
        //     else if(dp[i-1]>'0'&&dp[i-1]<='2')
        //     {

        //     }
        // }*/
    }
};