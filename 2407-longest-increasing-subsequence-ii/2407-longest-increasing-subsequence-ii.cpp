class segtree
{
    vector<int>seg;
    public:
    segtree(int n)
    {
        seg.resize(4*n+1);
    }
    void build(int idx,int low,int high,vector<int>&arr)
    {
        if(low==high)
        {
            seg[idx]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
    }
    void update(int idx,int low,int high,int i,int val)
    {
        if(low==high)
        {
            seg[idx]=val;
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
        if(low>r || high<l)
        {
            return INT_MIN;
        }
        else if(low>=l && high<=r)
        {
            return seg[idx];
        }
        else
        {
            int mid=low+(high-low)/2;
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);
            return max(left,right);
        }

    }
    

};






class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {

        int n=nums.size();
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
        }
        vector<int>dp(mx+1,-1e7);
        segtree s(mx+1);
        s.build(0,0,mx,dp);
        int ans=-1e7;
        for(int i=0;i<n;i++)
        {
            int maxm=s.query(0,0,mx,max(0,nums[i]-k),nums[i]-1);
            if(maxm!=-1e7)
            {
                ans=max(ans,1+maxm);
                s.update(0,0,mx,nums[i],1+maxm);
            }
            else
            {
                ans=max(ans,1);
                s.update(0,0,mx,nums[i],1);
            }

        }
        return (int)ans;






        
    }
};