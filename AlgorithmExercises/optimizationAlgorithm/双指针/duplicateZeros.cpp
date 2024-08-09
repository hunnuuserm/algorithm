//力扣1089. 复写零
//https://leetcode.cn/problems/duplicate-zeros/submissions/

//本体不能从前向后用双指针，这样会覆盖没有处理的部分。

//补充：  最好把写出来int n = arr.size（），
//        因为arr.size（）是无符号数，而自己定义的n是有符号数，
//        做oj的时候无符号数容易出现想不到的错误


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int cur=0;
        int dest=-1;
        //1.先找到最后一个要“复写”的数
        while(dest<n-1)
        {
            if(arr[cur])
            {
                dest+=1;
            }
            else
            {
                dest+=2;
            }
            if(dest>=n-1)
            {
                break;
            }
            cur++;
        }
        //2.从后向前完成“复写”
        while(dest>=0)
        {
            if(arr[cur])
            {
                arr[dest--]=arr[cur--];
            }
            else
            {
                
                if(dest==n)//处理特殊的边界情况
                {
                    dest=n-1;
                    arr[dest--]=arr[cur--];
                }
                else
                {
                    arr[dest--]=arr[cur];
                    arr[dest--]=arr[cur--];
                }
            }
        }
    }
};