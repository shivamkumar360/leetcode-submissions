class Solution {
public:


    int nodes=0;
    int ed=0;

    void dfs(int node,vector<pair<int,int>>adj[],vector<int>&edgevis,vector<int>&vis)
    {
        vis[node]=1;
        nodes++;
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int edgenum=it.second;
            if(!edgevis[edgenum])
            {
                edgevis[edgenum]=1;
                ed++;
            }
            if(!vis[adjnode])
            {
                dfs(adjnode,adj,edgevis,vis);
            }
        }
    }




    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<pair<int,int>>adj[n];
        int cnt=0;
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,cnt});
            adj[v].push_back({u,cnt});
            cnt++;
        }
        vector<int>vis(n,0);
        vector<int>edgevis(edges.size(),0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                nodes=0;
                ed=0;
                dfs(i,adj,edgevis,vis);
                if(ed==(nodes*(nodes-1))/2)
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};