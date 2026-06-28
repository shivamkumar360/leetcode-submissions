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
        if(parent[u]==parent[v])
        {
            return ;
        }
        int par_u=parent[u];
        int par_v=parent[v];
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
    bool validTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        if(m!=n-1)
        {
            return 0;
        }
        int comp=n;
        disjoint ds(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findpar(u)!=ds.findpar(v))
            {
                ds.unionbysz(u,v);
                comp--;
            }
        }
        if(comp==1)
        {
            return 1;
        }
        return 0;

    }
};
