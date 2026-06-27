class Solution {
public:

    int cnt=0;
    vector<int>xd={0,0,1,-1};
    vector<int>yd={1,-1,0,0};

    void dfs(vector<vector<int>>&grid,int row,int col)
    {
        int n=grid.size();
        int m=grid[0].size();
        cnt++;
        grid[row][col]=0;
        for(int i=0;i<4;i++)
        {
            int xc=row+xd[i];
            int yc=col+yd[i];
            if(xc>=0 && xc<n && yc>=0 && yc<m && grid[xc][yc])
            {
                dfs(grid,xc,yc);
            }
        }

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    cnt=0;
                    dfs(grid,i,j);
                    ans=max(ans,cnt);
                }
            }
        }

        return ans;


        

        
    }
};