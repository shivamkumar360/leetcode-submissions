class Solution {
public:

int xd[4]={0,0,1,-1};
int yd[4]={1,-1,0,0};
  class disjoint
   {
        vector<int>par;
        vector<int>sz;
        public:
        disjoint(int n)
        {
            par.resize(n+1);
            sz.resize(n+1,1);
            for(int i=0;i<=n;i++)
            {
                par[i]=i;
            }
        }
        int findpar(int u)
        {
            if(u==par[u])
            {
                return u;
            }
            else
            {
                return par[u]=findpar(par[u]);
            }
        }
        void unionbysz(int u,int v)
        {
            if(findpar(u)==findpar(v))
            {
                return ;
            }
            int par_u=findpar(u);
            int par_v=findpar(v);
            if(sz[par_u]>sz[par_v])
            {
                sz[par_u]+=sz[par_v];
                par[par_v]=par_u;
            }
            else
            {
                sz[par_v]+=sz[par_u];
                par[par_u]=par_v;
            }
        }

   };




    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();
        vector<pair<int,int>>pos(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                pos[grid[i][j]]={i,j};
            }
        }
        disjoint ds(n*n);
        for(int i=0;i<n*n;i++)
        {
            int x=pos[i].first;
            int y=pos[i].second;
            for(int j=0;j<4;j++)
            {
                int xc=x+xd[j];
                int yc=y+yd[j];
                if(xc>=0 && xc<n && yc>=0 && yc<n && grid[xc][yc]<i && ds.findpar(grid[xc][yc])!=ds.findpar(i))
                {
                    ds.unionbysz(i,grid[xc][yc]);
                }
            }
            if(ds.findpar(grid[0][0])==ds.findpar(grid[n-1][n-1]))
            {
                return i;
            }
        }
        return 0;

        
    }
};