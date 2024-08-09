//https://leetcode.cn/problems/longest-turbulent-subarray/
//最长湍流字符串

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n == 1) return 1;
        vector<int> dp(n);
        dp[0]=1;
        if(arr[1] == arr[0]) dp[1]=1;
        else dp[1]=2;
        for(int i=2;i<n;i++)
        {
            if((arr[i-1]<arr[i] && arr[i-2]>arr[i-1])
            ||(arr[i-1]>arr[i] && arr[i-2]<arr[i-1]))
            {
                dp[i]=dp[i-1]+1;
            }
            else if(arr[i] == arr[i-1])
            {
                dp[i]=1;
            }
            else
            {
                dp[i]=2;
            }
        }
        int ret=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ret=max(ret,dp[i]);
        }
        return ret;
    }
};