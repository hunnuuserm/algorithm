//https://leetcode.cn/problems/3sum/
//leetcode15.三数之和


   /*解题思路：先排序，然后根据单调性，使用双指针。
   但要注意去重，这题的去重操作以前没怎么见过，根据这题要学会。*/

//第二次做这道题，很快就做出来了，记录一下：
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cur = n - 1;
        while (cur >= 2)
        {
            int left = 0, right = cur - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] + nums[cur] == 0)
                {
                    ret.push_back(vector<int>{nums[left], nums[right], nums[cur]});
                    while (left < right && nums[left] == nums[left + 1])//处理相同情况
                    {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1])//处理相同情况
                    {
                        right--;
                    }
                    right--;
                }
                else if (nums[left] + nums[right] + nums[cur] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            while (cur >= 2 && nums[cur] == nums[cur - 1])//处理nums[cur]=nums[cur-1]的情况
            {
                cur--;
            }
            cur--;
        }
        return ret;
    }
};

//第一次做：
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int cur=nums.size()-1;
        int left=0;
        int right=cur-1;
        while(cur>=2)
        {
            left=0;
            right=cur-1;
            while(left<right)
            {
                if(nums[cur]+nums[left]+nums[right]>0)
                {
                    right--;
                }
                else if(nums[cur]+nums[left]+nums[right]<0)
                {
                    left++;
                }
                else
                {
                    ret.push_back(vector<int>{nums[left],nums[right],nums[cur]});
                    right--;
                    left++;
                    while(left<right&&nums[right]==nums[right+1])
                    {
                        right--;
                    }
                    while(left<right&&nums[left]==nums[left-1])
                    {
                        left++;
                    }
                }
            }
            while(cur>0&&nums[cur]==nums[cur-1])
            {
                cur--;
            }
            cur--;
        }
        return ret;
    }
};

