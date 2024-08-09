//https://leetcode.cn/problems/maximum-sum-circular-subarray/
//leetcode918.环形子数组的最大和

// 思路:
// 将问题转化为求：max(非环形子数组的最大和、sum-非环形子数组的最小和)即可


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        for(auto&e:nums) sum+=e;
        vector<int> dp_max(n);
        vector<int> dp_min(n);
        dp_max[0]=nums[0];
        dp_min[0]=nums[0];
        int ret=max(dp_max[0],sum-dp_min[0]);
        for(int i=1;i<n;i++)
        {
            dp_max[i]=max(nums[i],nums[i]+dp_max[i-1]);
            dp_min[i]=min(nums[i],nums[i]+dp_min[i-1]);
            ret=max(ret,max(dp_max[i],sum-dp_min[i]));
        }
        if(ret == 0)//处理特殊情况，即处理空子数组的情况（这里的最小子数组为整个nums，sum-最小子数组后的结果为0，为空子数组）
        {
            int retSum=INT_MIN;
            for(int i=0;i<n;i++)
            {
                retSum=max(retSum,dp_max[i]);
            }
            return retSum;
        }
        
        return ret;


        //下面这样不行，以为只能在dp[0]中保证nums[0]被算一次，其他的dp[i]中不能保证nums[i]只被算了一次。
    //     int n=nums.size();
    //     vector<int> arr(n);
    //     arr[n-1]=nums[n-1];
    //     int i=n-2;
    //     int maxsum=arr[n-1];
    //     while(i>=1)
    //     {
    //         arr[i]=nums[i]+arr[i+1];
    //         maxsum=max(maxsum,arr[i]);
    //         i--;
    //     }
    //     vector<int> dp(n);
    //     dp[0]=max(nums[0],nums[0]+maxsum);
    //     int ret=dp[0];
    //     for(int i =1;i<n;i++)
    //     {
    //         dp[i]=max(nums[i],nums[i]+dp[i-1]);
    //         ret=max(ret,dp[i]);
    //     }
    //     return ret;
     }
};