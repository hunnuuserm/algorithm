//63. 不同路径 II
//https://leetcode.cn/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        size_t m=ob.size();
        size_t n=ob[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][1]=1;
        for(size_t i=1;i<=m;i++)
        {
            for(size_t j=1;j<=n;j++)
            {
                if(ob[i-1][j-1]!=1)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];
        /*
        vector<vector<int>> dp(obstacleGrid.size());
        size_t sz=obstacleGrid[0].size();
        for(size_t i=0;i<dp.size();i++)
        {
            dp[i].resize(sz);
        }
        dp[0][0]=1;
        if(obstacleGrid.size()==1)
        {
            for(size_t i=0;i<obstacleGrid[0].size();i++)
            {
                if(obstacleGrid[0][i]==1)
                {
                    return 0;
                }
            }
            return 1;
        }

          if(obstacleGrid[0].size()==1)
        {
            for(size_t i=0;i<obstacleGrid.size();i++)
            {
                if(obstacleGrid[i][0]==1)
                {
                    return 0;
                }
            }
            return 1;
        }
        if((obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)
        ||(obstacleGrid[0][0]==1))
        {
            return 0;
        }
        for(size_t i=0;i<obstacleGrid.size();i++)
        {
            for(size_t j=0;j<obstacleGrid[0].size();j++)
            {
                if(i==0&&j==0)
                {
                    continue;
                }
                else if(i==0&&obstacleGrid[i][j-1]!=1&&obstacleGrid[i][j]!=1)
                {
                     dp[i][j]=dp[i][j-1];
                }
                else if(j==0&&obstacleGrid[i-1][j]!=1
                &&obstacleGrid[i][j]!=1)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(i!=0&&j!=0&&obstacleGrid[i][j-1]!=1&&obstacleGrid[i-1][j]!=1
                &&obstacleGrid[i][j]!=1)
                {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
                else if(i!=0&&j!=0&&obstacleGrid[i][j-1]!=1&&obstacleGrid[i-1][j]==1
                &&obstacleGrid[i][j]!=1)
                {
                    dp[i][j]=dp[i][j-1];
                }
                else if(i!=0&&j!=0&&obstacleGrid[i][j-1]==1&&obstacleGrid[i-1][j]!=1
                &&obstacleGrid[i][j]!=1)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];*/
        
    }
};