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

        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int distance=it[2];
            adj[u-1].push_back({v-1,distance});
            adj[v-1].push_back({u-1,distance});
        }
        vector<int>vis(n,0);
        dfs(0,adj,vis);
        return ans;
        
    }
};