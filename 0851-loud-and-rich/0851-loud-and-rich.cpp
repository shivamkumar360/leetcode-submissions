class Solution {
public:

    int ans=0;

    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&quiet)
    {
        if(quiet[ans]>quiet[node])
        ans=node;
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,quiet);
            }
        }

    }



    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n=quiet.size();
        vector<int>adj[n];
        for(auto it:richer)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            ans=i;
            dfs(i,adj,vis,quiet);
            res[i]=ans;
        }
        return res;
        
    }
};