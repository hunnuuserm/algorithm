//https://leetcode.cn/problems/valid-triangle-number/
//leetcode 611有效三角形的个数

//解题思路：先排序，然后利用单调性，使用双指针解决问题

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());//优化后用单调性来解题很爽
        int n=nums.size();
        int left=0;
        int right=n-2;
        int count=0;
        for(int cur=n-1;cur>=2;cur--)
        {
            left=0;
            right=cur-1;
            while(left<right)
            {
                if(nums[left]+nums[right]>nums[cur])
                {
                    count+=(right-left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return count;
        //暴力算法会超时：
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int count=0;
        // for(int left=0;left<=n-1;left++)
        // {
        //     for(int right=n-1;right>=left;right--)
        //     {
        //         for(int i=left+1;i<right;i++)
        //         {
        //             if(nums[left]+nums[i]>nums[right])
        //             {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        //return count;
    }
};