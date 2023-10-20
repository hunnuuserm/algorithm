//https://leetcode.cn/problems/fruit-into-baskets/
//leetcode904.水果成篮

//本题目是经典的滑动窗口题目，正常做即可

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0,right=0,ret=0;
        vector<int> v;
        v.resize(n,0);
        int count=0;
        while(right<n)
        {
            if(v[fruits[right]]==0)
            {
                count++;//维护水果种类
            }
            v[fruits[right]]++;//进窗口
            while(count>2)//判断
            {
                v[fruits[left]]--;
                if(v[fruits[left]]==0)
                {
                    count--;//维护水果种类
                }
                left++;//出窗口
            }
            ret=max(ret,right-left+1);//更新结果
            right++;
        }
        return ret;
    }
};