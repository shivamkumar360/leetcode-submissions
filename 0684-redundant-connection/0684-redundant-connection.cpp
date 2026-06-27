class disjoint
{
    private:
    vector<int>sz;
    vector<int>parent;
    public:
    disjoint(int n)
    {
        sz.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findpar(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        else
        {
            return parent[u]=findpar(parent[u]);
        }
    }
    void unionbysz(int u,int v)
    {
        int par_u=findpar(u);
        int par_v=findpar(v);
        if(par_u==par_v)
        {
            return;
        }
        if(sz[par_u]>sz[par_v])
        {
            sz[par_u]+=sz[par_v];
            parent[par_v]=par_u;
        }
        else
        {
            sz[par_v]+=sz[par_u];
            parent[par_u]=par_v;
        }
    }

};


class Solution {
public:
    vector<int>findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjoint ds(n);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(ds.findpar(u)!=ds.findpar(v))
            {
                ds.unionbysz(u,v);
            }
            else
            {
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
        }
        return ans;


        




        
    }
};