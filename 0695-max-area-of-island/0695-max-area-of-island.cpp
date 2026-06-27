class Solution {
public:

    int cnt=0;
    vector<int>xd={0,0,1,-1};
    vector<int>yd={1,-1,0,0};

    void dfs(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        cnt++;
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int xc=row+xd[i];
            int yc=col+yd[i];
            if(xc>=0 && xc<n && yc>=0 && yc<m && grid[xc][yc] && !vis[xc][yc])
            {
                dfs(grid,xc,yc,vis);
            }
        }

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    cnt=0;
                    dfs(grid,i,j,vis);
                    ans=max(ans,cnt);
                }
            }
        }

        return ans;


        

        
    }
};