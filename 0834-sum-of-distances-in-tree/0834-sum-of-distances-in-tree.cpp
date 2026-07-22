class Solution {
public:

    int total=0;

    void dfs(int node,vector<int>adj[],int parent,int dist,vector<int>&sub)
    {
        total+=dist;
        int chi=0;
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            dfs(it,adj,node,dist+1,sub);
            chi+=sub[it];
        }
        sub[node]=chi+1;

    }

    void maindfs(int node,int parent,vector<int>adj[],vector<int>&sub,vector<int>&ans)
    {
       
         for(auto it:adj[node])
        {
            if(it==parent)continue;
            ans[it]=ans[node]-2*sub[it]+(int)sub.size();
            maindfs(it,node,adj,sub,ans);
        }

    }





    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<int>adj[n];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>sub(n);
        dfs(0,adj,-1,0,sub);
        vector<int>ans(n);
        ans[0]=total;
        maindfs(0,-1,adj,sub,ans);
        return ans;


        
    }
};