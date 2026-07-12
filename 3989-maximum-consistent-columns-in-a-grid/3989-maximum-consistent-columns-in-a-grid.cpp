class Solution {
public:

    int column(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int limit)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(j==0)
        {
            return dp[i][j]=max(column(i+1,0,grid,dp,limit),1+column(i+1,i+1,grid,dp,limit));
        }
        else
        {
            int ans=0;
            int flag=0;
            for(int idx=0;idx<n;idx++)
            {
                if(abs(grid[idx][i]-grid[idx][j-1])>limit)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans=max(ans,1+column(i+1,i+1,grid,dp,limit));
            }
            ans=max(ans,column(i+1,j,grid,dp,limit));
            return dp[i][j]=ans;
        }


    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) 
    {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(m+1,-1));
        return column(0,0,grid,dp,limit);




  
    }
};