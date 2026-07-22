class Solution {
public:

    const static int N=(int)1e5+2;
    int mx1[N];
    int mx2[N];
    int up[N];


    void dfs(int node,int parent,vector<int>adj[],vector<int>&sub)
    {
        mx1[node]=0;
        mx2[node]=0;
        for(auto it:adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            dfs(it,node,adj,sub);
            int sb;
            if(it%2)
            {
                sb=1+sub[it];
            }
            else
            {
                sb=2+sub[it];
            }
            if(sb>=mx1[node])
            {
                mx2[node]=mx1[node];
                mx1[node]=sb;
            }
            else if(sb>=mx2[node])
            {
                mx2[node]=sb;
            }
        }
        sub[node]=mx1[node];

    }

    void maindfs(int node,int parent,vector<int>adj[],vector<int>&sub,vector<int>&ans)
    {
        up[0]=0;
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            int cost=(it%2?1:2);
            int contrib=cost+sub[it];
            int bestWithoutChild;
            if (contrib == mx1[node])
            bestWithoutChild = mx2[node];
            else
            bestWithoutChild = mx1[node];
            up[it] = (node % 2 ? 1 : 2) + max(up[node], bestWithoutChild);
            ans[it] = max(sub[it], up[it]);
            maindfs(it,node,adj,sub,ans);
        }
    }




    vector<int> timeTaken(vector<vector<int>>& edges) {

        int n=edges.size()+1;
        vector<int>adj[n];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>sub(n);
        dfs(0,-1,adj,sub);
        vector<int>ans(n);
        ans[0]=sub[0];
        maindfs(0,-1,adj,sub,ans);
        return ans;





        
    }
};