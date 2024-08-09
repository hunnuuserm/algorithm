//https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
//leetcode 剑指offer57.和为s的两个数字

//解题思路：数组排完序了。直接根据单调性，使用双指针求解

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int s) {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right]>s)
            {
                right--;
            }
            else if(nums[left]+nums[right]<s)
            {
                left++;
            }
            else
            {
                break;
            }
        }
        return vector<int>{nums[left],nums[right]};
    }
};