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
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int query(int idx,int low,int high,int l,int r)
    {
        if(r<low || l>high)
        {
            return 0;
        }
        else if(l<=low && high<=r)
        {
            return seg[idx];
        }
        else
        {
            int mid=low+(high-low)/2;
            return query(2*idx+1,low,mid,l,r)+query(2*idx+2,mid+1,high,l,r);
        }
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
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];

    }
};


class NumArray {
public:

    segtree *s;
    int n;
    NumArray(vector<int>& nums) 
    {
        n=nums.size();
        s=new segtree(n);
        s->build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {

        s->update(0,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        return s->query(0,0,n-1,left,right);


        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */