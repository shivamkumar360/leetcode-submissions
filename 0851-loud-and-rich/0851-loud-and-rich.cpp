class Solution {
public:


    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&order)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,order);
            }
        }
        order.push_back(node);
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
            vector<int>order;
            vector<int>vis(n,0);
            for(int i=0;i<n;i++)
            if(!vis[i])
            dfs(i,adj,vis,order);
            reverse(order.begin(),order.end());
            vector<int>ans(n);
            for(int i=order.size()-1;i>=0;i--)
            {
                int minm=order[i];
                for(auto it:adj[order[i]])
                {
                    if(quiet[ans[it]]<quiet[minm])
                    {
                        minm=ans[it];
                    }
                }
                ans[order[i]]=minm;
            }
           
        
        return ans;
        
    }
};