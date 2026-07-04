class disjoint
{
    vector<int>sz;
    vector<int>par;
    public:
    disjoint(int n)
    {
        sz.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<n+1;i++)
        {
            par[i]=i;
        }
    }
    int findpar(int u)
    {
        if(par[u]==u)
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
        int par_u = findpar(u);
        int par_v = findpar(v);
        if(par_u==par_v)
        {
            return;
        }
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
class Solution {
public:

    int ans=1e5;
    
    int minScore(int n, vector<vector<int>>& roads) {

        disjoint ds(n);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int distance=it[2];
            if(ds.findpar(u)!=ds.findpar(v))
            {
                ds.unionbysz(u,v);
            }
           
        }
        int root = ds.findpar(1);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int distance=it[2];
            if(root==ds.findpar(u))
            {
               ans=min(ans,distance);
            }
           
        }

        
        return ans;
        
    }
};