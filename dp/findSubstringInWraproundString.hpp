//https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
//leetcode467.环绕字符串中唯一的子字符串

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            if((s[i] == s[i-1]+1)||(s[i]=='a' && s[i-1]=='z'))
            {
                dp[i]=1+dp[i-1];
            }
            else
            {
                dp[i]=1;
            }
        }
        // unordered_map<char,int> map;
        // for(int i=0;i<n;i++)
        // {
        //     map[s[i]] = max(dp[i],map[s[i]]);
        // }
        // int ret=0;
        // for(auto&e : map)
        // {
        //     ret+=e.second;
        // }

        int arr[26]={0};
        for(int i=0;i<n;i++)
        {
            if(dp[i] > arr[s[i]-'a']) arr[s[i]-'a'] = dp[i];
            // arr[s[i] - 'a'] = max(dp[i], arr[s[i] - 'a']);
        }
        int ret=0;
        for(int i=0;i<26;i++)
        {
            ret+=arr[i];
        }
        return ret;
    }
};