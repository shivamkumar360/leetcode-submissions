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
        int par_u=par[u];
        int par_v=par[v];
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
    
    void dfs(int node,vector<pair<int,int>>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int dist=it.second;
            ans=min(ans,dist);

            if(!vis[adjnode])
            {
                
                dfs(adjnode,adj,vis);
            }
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {

        //vector<pair<int,int>>adj[n];
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
            // adj[u-1].push_back({v-1,distance});
            // adj[v-1].push_back({u-1,distance});
        }
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int distance=it[2];
            if(ds.findpar(1)==ds.findpar(u) || ds.findpar(1)==ds.findpar(v))
            {
               ans=min(ans,distance);
            }
            // adj[u-1].push_back({v-1,distance});
            // adj[v-1].push_back({u-1,distance});
        }

        // for(auto it:adj[0])
        // {
        //     if(ds.unionbysz(0,it));
        // }
        // for(auto it:adj[n-1])
        // {
        //     if(ds.unionbysz(n-1,it));
        // }
        // for(auto it:roads)
        // {
        //     int u=it[0];
        //     int v=it[1];
        //     int distance=it[2];
        //     if(ds.findpar(u)==ds.findpar(0) || ds.findpar())

        // }
        // vector<int>vis(n,0);
        // dfs(0,adj,vis);
        return ans;
        
    }
};