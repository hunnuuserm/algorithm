//https://leetcode.cn/problems/maximum-length-of-pair-chain/
//最长数对链

class Compare
{
public:
    bool operator()(vector<int> v1,vector<int> v2)
    {
        return v1[1] < v2[1];
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),Compare());
        int n = pairs.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        int ret = INT_MIN;
        for(int i = 0;i < n;i++)
        {
            ret = max(ret,dp[i]);
        }
        return ret;
    }
};
