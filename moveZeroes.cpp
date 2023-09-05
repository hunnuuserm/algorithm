//力扣283. 移动零
//https://leetcode.cn/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int cur=0,dest=-1;cur<nums.size();cur++)
        {
            if(nums[cur])
            {
                swap(nums[++dest],nums[cur]);
            }
        }
    }
};