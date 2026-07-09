class disjoint
{
    vector<int>par;
    vector<int>sz;
    public:
    disjoint(int n)
    {
        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findpar(int u)
    {
        if(par[u]==u)
        {
            return u;
        }
        return par[u]=findpar(par[u]);
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
            par[par_v]=par_u;
        }
        else
        {
            sz[par_v]+=sz[par_u];
            par[par_u]=par_v;
        }
    }

};


class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        
        disjoint ds(n);

        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
            auto it=upper_bound(nums.begin()+i+1,nums.end(),maxDiff+nums[i]);

            int idx;
            if(it==nums.end())
            {
                idx=n-1;
            }
            else
            {
                idx=it-nums.begin()-1;
            }
            if(idx>=i+1)
            {
                if(ds.findpar(i)!=ds.findpar(min(idx,i+1)))
                {
                    ds.unionbysz(i,min(idx,i+1));
                }
            }
            }




           


        }
        vector<bool>ans;
        for(auto it:queries)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findpar(u)==ds.findpar(v))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
        
    }
};