

class segtree
{
    vector<int>seg;
    public:
    segtree(int n)
    {
        seg.resize(4*n+1,INT_MIN);
    }
    void update(int idx,int low,int high,int i,int val)
    {
        if(low==high)
        {
            seg[idx]=max(seg[idx],val);
            return;
        }
        int mid=low+(high-low)/2;
        if(i<=mid)
        {
            update(2*idx+1,low,mid,i,val);
        }
        else
        {
            update(2*idx+2,mid+1,high,i,val);
        }
        seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);

        

    }
    int query(int idx,int low,int high,int l,int r)
    {
       
        if(r<low || l>high)
        {
            return INT_MIN;
        }
        else if(l<=low && high<=r)
        {
            return seg[idx];
        }
        else
        {
            int mid=low+(high-low)/2;
            return max(query(2*idx+1,low,mid,l,r),query(2*idx+2,mid+1,high,l,r));
        }
    }
};






class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        
        int n=nums1.size();
        vector<vector<int>>points;
        for(int i=0;i<n;i++)
        {
            points.push_back({nums1[i],nums2[i],nums1[i]+nums2[i]});
        }
        sort(points.begin(),points.end(),[](auto &a,auto &b)
        {
            return a[0]>b[0];
        });

        vector<vector<int>>que;
        for(int i=0;i<queries.size();i++)
        {
            que.push_back({queries[i][0],queries[i][1],i});
        }
        sort(que.begin(),que.end(),[](auto &a,auto &b)
        {
            return a[0]>b[0];
        });

        vector<int>comp;
        for(auto it:points)
        {
            comp.push_back(it[1]);
        }
        sort(comp.begin(),comp.end());
        comp.erase(unique(comp.begin(),comp.end()),comp.end());
        segtree st(comp.size());
        int ptr=0;
        vector<int>ans(queries.size());
        for(int i=0;i<que.size();i++)
        {
            int x=que[i][0];
            int y=que[i][1];
            int idx=que[i][2];
            while(ptr<n && points[ptr][0]>=x)
            {
                int pos=lower_bound(comp.begin(),comp.end(),points[ptr][1])-comp.begin();

                st.update(0,0,comp.size()-1,pos,points[ptr][2]);

                ptr++;

            }
            int pos = lower_bound(comp.begin(), comp.end(), y) - comp.begin();
            if(pos==comp.size())
            {
                ans[idx]=-1;
                continue;
            }
            int res=st.query(0,0,comp.size()-1,pos,comp.size()-1);
            if(res==INT_MIN)
            {
                ans[idx]=-1;
            }
            else
            {
                ans[idx]=res;
            }
        }

        return ans;






        
    }
};