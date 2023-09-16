//https://leetcode.cn/problems/happy-number/
//leetcode202快乐数
//可以用双指针做，但是没必要
class Solution {
public:

    int func(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int count=0;
        while(n!=1&&count<811)
        {
            n=func(n);
            count++;
        }
        if(n==1) return true;
        else return false;
    }
};