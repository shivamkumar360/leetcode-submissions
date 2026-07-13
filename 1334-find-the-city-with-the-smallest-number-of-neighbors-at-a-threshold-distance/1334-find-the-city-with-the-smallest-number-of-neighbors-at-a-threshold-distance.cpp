class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dth) {

        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            dp[u][v]=weight;
            dp[v][u]=weight;
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dp[i][k]==1e9 || dp[k][j]==1e9)
                    {
                        continue;
                    }
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans=0;
        int minm=n+2;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]<=dth)
                {
                    cnt++;
                }
            }
            if(cnt<=minm)
            {
                ans=i;
                minm=cnt;
            }


        }
        return ans;
       



        
    }
};