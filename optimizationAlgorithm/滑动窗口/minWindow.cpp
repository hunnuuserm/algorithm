//https://leetcode.cn/problems/minimum-window-substring/
//leetcode76.最小覆盖子串

//下面两种写法没有本质区别
//补充:前面的一些题中，count一般指窗口中元素的个数，但这道题的count指窗口中元素的种类

//写法1：
class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = { 0 };
        int hash2[128] = { 0 };
        int k = 0;
        for(auto&e : t)
        {
            if(hash1[e]==0)
            {
                k++;
            }
            hash1[e]++;
        }
        int left = 0,right = 0,count = 0,n=s.size();
        int begin = -1,minLen = INT_MAX;
        while(right<n)
        {
            hash2[s[right]]++;//进窗口
            if(hash2[s[right]] == hash1[s[right]])
            {
                count++;//维护种类count
            }
            while(count == k)//判断
            {
                if(minLen > right-left+1)//更新结果
                {
                    minLen=right-left+1;
                    begin=left;
                }
                if(hash2[s[left]] == hash1[s[left]])
                {
                    count--;//维护种类count
                }
                hash2[s[left]]--;//出窗口
                left++;//出窗口
            }
            right++;
        }
        return begin == -1? "" : s.substr(begin,minLen);
    }
};

//写法2:
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[128]={0};
        int k = 0;
        for(auto&e :t)
        {
            if(hash[e]==0) k++;

            hash[e]++;
        }
        int begin = -1,minLen = INT_MAX;
        for(int left = 0,right = 0,count = 0;right<s.size();right++)
        {
            hash[s[right]]--;//进窗口
            if(hash[s[right]]==0) count++;//维护种类count
            while(count == k)//判断是否满足条件(以前的题很多都是判断是否不满足条件)
            {
                if(minLen > right-left+1)//更新结果
                {
                    minLen=right-left+1;
                    begin=left;
                }
                if(hash[s[left]] == 0)
                {
                    count--;//维护种类count
                }
                hash[s[left]]++;//出窗口
                left++;//出窗口
            }
        }
        return begin == -1? "" : s.substr(begin,minLen);
    }
};