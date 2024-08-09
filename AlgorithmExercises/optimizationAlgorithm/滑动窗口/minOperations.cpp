//https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
//leetcode1658.将x减到0的最小操作数

//思路:正难则反：将原问题转换为：
//第一步转换为：找出nums左右两头的两个子数组，使得这两个子数组的长度最小且两个子数组中元素相加等于x
//第二步转换为：找出最长的子数组，使得这个子数组中的元素和为sum-x(sum为nums所有元素的和)
//经过第二步转换后就是以前经常做的滑动窗口类型的题目

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //正难则反，反向做：
        int n=nums.size(),s=0;
        for(auto&e: nums)
        {
            s+=e;
        }
        int left=0,right=0,len=INT_MIN,target=s-x,sum=0;
        if(target<0) return -1;
        while(right<n)
        {
            sum+=nums[right];//进窗口
            while(sum>target)//判断
            {
                sum-=nums[left++];//出窗口
            }
            if(sum==target)
            {
                len=max(len,right-left+1);//更新结果
            }
            right++;
        }
        return len==INT_MIN?(-1):(n-len);


        //正向做很难，有很多中情况，而且下面的代码只能通过一般的测试用例：
        // int n=nums.size();
        // int left=0,right=n-1;
        // if(nums[left]>x&&nums[right]>x) return -1;
        // if(nums[left]==x||nums[right]==x) return 1;
        // int count=0;
        // while(x>0&&left<right)
        // {
        //     if((nums[left]>nums[right]&&nums[left]<=x)||(nums[right]>x&&nums[left]<=x))
        //     {
        //         x-=nums[left++];
        //         count++;
        //     }
        //     //else if((nums[right]>nums[left]&&nums[right]<x)||(nums[left]>x&&nums[right]<x))
        //     else
        //     {
        //         x-=nums[right--];
        //         count++;
        //     }
        // }
        // return x==0?count:-1;
    }
};