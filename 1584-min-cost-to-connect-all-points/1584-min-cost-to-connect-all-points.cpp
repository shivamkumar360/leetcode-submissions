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
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                edges.push_back({(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])),{i,j}});

            }
        }
        sort(edges.begin(),edges.end());
        disjoint ds(n);
        int ans=0;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i].second.first;
            int v=edges[i].second.second;
            int cost=edges[i].first;
            if(ds.findpar(u)!=ds.findpar(v))
            {
                ds.unionbysz(u,v);
                ans+=cost;
            }
        }
        return ans;


        
    }
};