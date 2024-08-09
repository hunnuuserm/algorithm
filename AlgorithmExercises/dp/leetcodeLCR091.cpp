//LCR 091. 粉刷房子
//https://leetcode.cn/problems/JEj789/description/

//经典简单多状态dp问题

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n= costs.size();
        //创建3个dp表
        vector<int> r(n);
        auto b=r;
        auto g=r;
        //初始化
        r[0]=costs[0][0];
        b[0]=costs[0][1];
        g[0]=costs[0][2];
        //填表
        for(int i=1;i<n;i++)
        {
            r[i]=min(b[i-1],g[i-1])+costs[i][0];
            b[i]=min(r[i-1],g[i-1])+costs[i][1];
            g[i]=min(r[i-1],b[i-1])+costs[i][2];
        }
        return min(r[n-1],min(b[n-1],g[n-1]));
    }
};