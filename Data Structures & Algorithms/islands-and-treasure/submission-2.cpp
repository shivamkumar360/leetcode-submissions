class Solution {
public:
    vector<int>xd={0,0,1,-1};
    vector<int>yd={1,-1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({0,{i,j}});
                    grid[i][j]=0;
                }
            }
        }
        
        while(!q.empty())
        {
            int step=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xc=row+xd[i];
                int yc=col+yd[i];
                if(xc>=0 && xc<n && yc>=0 && yc<m && grid[xc][yc]!=-1 && grid[xc][yc]==INT_MAX)
                {
                    q.push({step+1,{xc,yc}});
                    grid[xc][yc]=step+1;
                }
            }

        }



        
    }
};
