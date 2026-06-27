class Solution {
public:

    vector<int>xd={0,0,1,-1};
    vector<int>yd={1,-1,0,0};

    // void dfs(vector<vector<int>>&grid,int row,int col)
    // {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vis[row][col]=0;
    //     for(int i=0;i<4;i++)
    //     {
    //         int xc=row+xd[i];
    //         int yc=col+yd[i];
    //         if(xc>=0 && xc<n && yc>=0 && yc<m && !vis[xc][yc])
    //         {
    //             dfs(grid,xc,yc);
    //         }
    //     }

    // }

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int j=0;j<m;j++)
        {
            pac[0][j]=1;
            q.push({0,j});
        }
        for(int j=0;j<n;j++)
        {
            pac[j][0]=1;
            q.push({j,0});
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xc=x+xd[i];
                int yc=y+yd[i];
                if(xc>=0 && xc<n && yc>=0 && yc<m && !pac[xc][yc] && heights[xc][yc]>=heights[x][y])
                {
                    pac[xc][yc]=1;
                    q.push({xc,yc});
                }
            }
        }


        for(int j=0;j<n;j++)
        {
            atl[j][m-1]=1;
           // vis[j][m-1]=1;
            q.push({j,m-1});
        }
        
        for(int j=0;j<m;j++)
        {
            atl[n-1][j]=1;
            //vis[n-1][j]=1;
            q.push({n-1,j});
        }

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xc=x+xd[i];
                int yc=y+yd[i];
                if(xc>=0 && xc<n && yc>=0 && yc<m && !atl[xc][yc] && heights[xc][yc]>=heights[x][y])
                {
                    atl[xc][yc]=1;
                    q.push({xc,yc});
                }
            }
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        


        
    }
};