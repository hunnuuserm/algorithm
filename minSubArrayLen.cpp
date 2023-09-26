//https://leetcode.cn/problems/minimum-size-subarray-sum/
//leetcode209.长度最小的子数组
//算法思想：把暴力解法优化后，两个双指针不用回退，即类似滑动窗口

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
        //最优解法：滑动窗口
        int n=nums.size();
        int sum=0,ret=INT_MAX;
        for(int left=0,right=0;right<n;right++)
        {
            sum+=nums[right];//进窗口
            while(sum>=target)//判断
            {
                ret=min(ret,right-left+1);//更新结果
                sum=sum-nums[left];
                left++;//sum-=sum[left++];//出窗口
            }
        }
        return ret==INT_MAX?0:ret;
        //下面的解法和上面的算法思想一样，只是代码写的不美观：
		// int n=nums.size();
		// int left=0;
		// int right=0;
		// int sum=nums[0];
		// int ret=INT_MAX;
		// 	while(right<n&&left<=right)
		// 	{
		// 		if(sum<target)
		// 		{
		// 			right++;
		// 			if(right==n)
		// 			{
		// 				break;
		// 			}
		// 			sum=sum+nums[right];
		// 		}
		// 		else
		// 		{
		// 			ret=min(ret,right-left+1);
		// 			sum=sum-nums[left];
		// 			left++;
		// 		}
		// 	}
		// 	if(ret==INT_MAX) return 0;
		// 	return ret;

        //下面为暴力解法，会超时：
		// int n = nums.size();
		// vector<int> ret;
		// for (int i = 0; i < n; i++)
		// {
		// 	int sum = nums[i];
		// 	if (sum >= target)
		// 	{
		// 		ret.push_back(1);
		// 		continue;
		// 	}
		// 	for (int j = i + 1; j < n; j++)
		// 	{
		// 		sum += nums[j];
		// 		if (sum >= target)
		// 		{
		// 			ret.push_back(j - i + 1);
		// 			break;
		// 		}
		// 	}
		// }
		// sort(ret.begin(), ret.end());
		// if (!ret.empty())
		// {
		// 	return ret[0];
		// }
		// else
		// {
		// 	return 0;
		// }
	}
};