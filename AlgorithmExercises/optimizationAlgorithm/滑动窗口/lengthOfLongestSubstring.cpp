//https://leetcode.cn/problems/longest-substring-without-repeating-characters/
//leetcode3.无重复字符的最长子串

//解题思路：hash映射+滑动窗口
//判断一个字符是否与前面的字符重合时，不用特意写一个函数，用hash映射即可轻松解决

//第二次做:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = INT_MIN;
        int left = 0, right = 0, n = s.size();
        int hash[128] = { 0 };
        while (right < n)
        {
            hash[s[right]]++;//进窗口
            while (hash[s[right]] > 1)//判断
            {
                hash[s[left++]]--;//出窗口
            }
            ret = max(ret, right - left + 1);//更新结果
            right++;
        }
        return ret == INT_MIN ? 0 : ret;
    }
};

//第一次做：
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128]={0};
        int left=0,right=0,n=s.size();
        int max_len=0;
        //写法1：
        while(right<n)
        {
            hash[s[right]]++;//进窗口
            while(hash[s[right]]>1)//判断
            {
                hash[s[left++]]--;//出窗口
            }
            max_len=max(max_len,right-left+1);//更新结果
            right++;
        }
        return max_len;
        //写法2：
        // while(right<n)
        // {
        //     while(right<n&&hash[s[right]]==0)
        //     {
        //         hash[s[right++]]++;//进窗口
        //         max_len=max(max_len,right-left);//更新结果
        //     }

        //     while(right<n&&hash[s[right]]==1)//判断
        //     {
        //         hash[s[left++]]--;//出窗口
        //     }
        // }
        //return max_len;
        //两种写法本质没有区别
    }
};