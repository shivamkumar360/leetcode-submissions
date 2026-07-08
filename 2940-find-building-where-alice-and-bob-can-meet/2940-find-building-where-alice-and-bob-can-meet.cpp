class segtree
{
    vector<int>seg;
    public:
    segtree(int n)
    {
        seg.resize(4*n+1);
    }
    void build(int idx,int low ,int high,vector<int>&arr)
    {
        if(low==high)
        {
            seg[idx]=arr[low];
            return ;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
    }
    int query(int idx,int low,int high,int st,int target)
    {
        if(high<st)
        {

            return -1;
        }
        if(seg[idx]<=target)
        {
            return -1;
        }
        if(low==high)
        {
            return low;
        }
            int mid=low+(high-low)/2;
            int left= query(2*idx+1,low,mid,st,target);
            if(left!=-1)
            {
                return left;
            }
            else
            return query(2*idx+2,mid+1,high,st,target);
        
    }
};








class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        int n=heights.size();
        int m=queries.size();
        vector<int>ans(m);
        segtree s(n);
        s.build(0,0,n-1,heights);
        for(int i=0;i<m;i++)
        {
            int maxidx=max(queries[i][0],queries[i][1]);
            int minidx=min(queries[i][0],queries[i][1]);
            if(maxidx==minidx || heights[maxidx]>heights[minidx])
            {
                ans[i]=maxidx;
                continue;
            }
            int temp=s.query(0,0,n-1,maxidx+1,heights[minidx]);
            ans[i]=temp;
        }
        return ans;

        // vector<tuple<int,int,int>>sorted;
        // for(int i=0;i<m;i++)
        // {
        //     int u=queries[i][0];
        //     int v=queries[i][1];
        //     if(u<v)
        //     {
        //         swap(u,v);
        //     }
        //     int idx=i;
        //     tuple<int,int,int> temp={u,v,idx};
        //     sorted.push_back(temp);
        // }
        // sort(sorted.begin(),sorted.end());
        // vector<int>st;
        // int j=n-1;
        // vector<int>ans(m);
        // for(int i=m-1;i>=0;i--)
        // {
        //     int y=get<0>(sorted[i]);
        //     int x=get<1>(sorted[i]);
        //     int idx=get<2>(sorted[i]);
        //     if(x==y || heights[y]>heights[x])
        //     {
        //         ans[idx]=y;
        //         continue;
        //     }
        //     while(j>y)
        //     {
        //         while(!st.empty() && heights[st.back()]<=heights[j])
        //         {
        //             st.pop_back();
        //         }
        //         st.push_back(j);
        //         j--;
        //     }
        //     auto it=upper_bound(st.rbegin(),st.rend(),max(heights[y],heights[x]),[&](int h, int idx)
        //     {
        //         return h<heights[idx];
        //     });
        //     if(it==st.rend())
        //     {
        //         ans[idx]=-1;
        //     }
        //     else
        //     {
        //         ans[idx]=*it;
        //     }
        // }
        // return ans;
        
    }
};