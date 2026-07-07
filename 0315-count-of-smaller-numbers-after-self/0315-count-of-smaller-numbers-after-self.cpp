
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

        if(low>high)
        return;




        if(low==high)
        {
            seg[idx]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    void update(int idx,int low,int high,int i,int val)
    {

        if(low>high)
        return;



        if(low==high)
        {
            seg[idx]+=val;
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
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

    int query(int idx,int low,int high,int l,int r)
    {
        if(low>high)
        {
            return 0;
        }
        if(low>r || high<l)
        {
            return 0;
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
            return left+right;
        }
    }

};





class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();

        int pos_mx=-1;
        int neg_mx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                pos_mx=max(pos_mx,nums[i]);
            }
            else
            {
                neg_mx=max(neg_mx,abs(nums[i]));
            }
        }
        vector<int>pos_freq(pos_mx+1,0);
        vector<int>neg_freq(neg_mx+1,0);
        vector<int>neg_suffix(n);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                pos_freq[nums[i]]++;
            }
            else
            {
                neg_freq[abs(nums[i])]++;
            }
        }
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<0)
            {
                sum++;
            }
            neg_suffix[i]=sum;
        }
        segtree s1(pos_mx+1);
        segtree s2(neg_mx+1);
        s1.build(0,0,pos_mx,pos_freq);
        s2.build(0,0,neg_mx,neg_freq);

        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                s1.update(0,0,pos_mx,nums[i],-1);
                ans[i]=s1.query(0,0,pos_mx,0,nums[i]-1);
                if(i<n-1)
                {
                    ans[i]+=neg_suffix[i+1];
                }
            }
            else
            {
                s2.update(0,0,neg_mx,abs(nums[i]),-1);
                ans[i]=s2.query(0,0,neg_mx,abs(nums[i])+1, neg_mx);
            }
        }

        return ans;







        
    }
};