class Solution {
public:


    int  dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans,vector<int>&quiet)
    {
        if(vis[node]) return ans[node];
        ans[node]=node;
        for(auto it:adj[node])
        {
            int x=dfs(it,adj,vis,ans,quiet);
            if(quiet[ans[node]]>quiet[x])
            {
               ans[node]=x;
            }
        }
        vis[node]=1;
        return ans[node];
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
          //  vector<int>order;
            vector<int>vis(n,0);
        //     for(int i=0;i<n;i++)
        //     if(!vis[i])
        //     dfs(i,adj,vis,order);
        //     reverse(order.begin(),order.end());
        //     vector<int>ans(n);
        //     for(int i=order.size()-1;i>=0;i--)
        //     {
        //         int minm=order[i];
        //         for(auto it:adj[order[i]])
        //         {
        //             if(quiet[ans[it]]<quiet[minm])
        //             {
        //                 minm=ans[it];
        //             }
        //         }
        //         ans[order[i]]=minm;
        //     }
           
        
        // return ans;

        vector<int>ans(n);
        for(int i=0;i<n;i++)
        if(!vis[i])
        int x=dfs(i,adj,vis,ans,quiet);
        return ans;
        
    }
};