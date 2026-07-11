class Solution {
public:


    int nodes=0;
    int ed=0;

    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        nodes++;
        ed+=adj[node].size();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }




    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int>adj[n];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                nodes=0;
                ed=0;
                dfs(i,adj,vis);
                if(ed==(nodes*(nodes-1)))
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};