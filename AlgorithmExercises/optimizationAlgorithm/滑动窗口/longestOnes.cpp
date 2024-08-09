//https://leetcode.cn/problems/max-consecutive-ones-iii/
//leetcode 1004. 最大连续1的个数 III
//滑动窗口

//第二次做，代码写的很简洁，记录一下:
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size();
        int ret = 0;
        while (right < n)
        {
            if (nums[right] == 0) k--;//进窗口
            while (k < 0)//判断
            {
                if (nums[left++] == 0) k++;//出窗口
            }
            ret = max(ret, right - left + 1);//更新结果
            right++;
        }
        return ret;
    }
};

//第一次做：
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sign=k,n=nums.size(),left=0,right=0;
        int ret=0;
        while(right<n)
        {
            if(nums[right]==0)
            {
                k--;
            }
                    //进窗口
            while(k<0)//判断
            {
                if(nums[left]==0)
                {
                    k++;
                }
                left++;//出窗口
            }
           ret=max(ret,right-left+1);//更新结果
           right++;
        }
        return ret;
    }
};