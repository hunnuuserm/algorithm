//https://leetcode.cn/problems/4sum/description/
//leetcode18.四数之和

//解题思路：先排序，然后根据单调性，使用双指针。
//注意细节,如去重等操作即可

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cur=n-1;
        while(cur>=3)
        {
            int third=cur-1;
            while(third>=2)
            {
                int left=0,right=third-1;
                while(left<right)
                {
                    long long tmp=(long long)nums[left]+(long long)nums[right]+(long long)nums[third]+(long long)nums[cur];
                    if(tmp==target)
                    {
                        ret.push_back(vector<int>{nums[left],nums[right],nums[third],nums[cur]});
                        //满足条件push_back到待返回的ret中

                        while(left<right&&nums[left]==nums[left+1])
                        {
                            left++;
                        }
                        left++;
                        while(left<right&&nums[right]==nums[right-1])
                        {
                            right--;
                        }
                        right--;
                    }
                    else if(tmp<target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
                while(third>=2&&nums[third]==nums[third-1])
                {
                    third--;//处理third的重复情况
                }
                third--;
            }

            while(cur>=3&&nums[cur]==nums[cur-1])
            {
                cur--;//处理cur的重复情况
            }
            cur--;
        }
        return ret;
    }
};