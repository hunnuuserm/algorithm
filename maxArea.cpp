//https://leetcode.cn/problems/container-with-most-water/description/
//leetcode 11.盛最多水的容器

//主要思想是利用单调性，使用双指针来解决问题

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int left=0;
        int right=n-1;
        int sum=0;
        while(left<right)
        {
            sum=max(sum,min(h[left],h[right])*(right-left));
            if(h[left]<h[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return sum;
        //暴力解法会超时（毕竟是中等难度的题目）：
        // int n=h.size();
        // size_t sum=0;
        // for(int left=0;left<n;left++)
        // {
        //     for(int right=left;right<n;right++)
        //     {
        //         sum=max(sum,min(h[left],h[right])*(right-left));
        //     }
        // }
        //return sum;
    }
};