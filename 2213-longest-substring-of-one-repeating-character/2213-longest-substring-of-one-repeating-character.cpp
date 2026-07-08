class info
{
    public:
    char right;
    char left;
    int pre;
    int suff;
    int maxm;
    int len;
    info()
    {
        right='#';
        left='#';
        pre=0;
        suff=0;
        maxm=0;
        len=0;
        
    }
    info(char l,char r,int pre,int suff,int maxm,int len )
    {
        this->left=l;
        this->right=r;
        this->pre=pre;
        this->suff=suff;
        this->maxm=maxm;
        this->len=len;
    }
};

class segtree
{
    public:
    vector<info>seg;
    segtree(int n)
    {
        seg.resize(4*n+1);
    }

info merge(int idx)
{
    info curr;
    int l=2*idx+1;
    int r=2*idx+2;
    curr.left=seg[l].left;
    curr.right=seg[r].right;
    curr.len=seg[l].len+seg[r].len;
    curr.pre=seg[l].pre;
    if(seg[l].pre==seg[l].len && seg[l].right==seg[r].left)
    {
        curr.pre=seg[l].len+seg[r].pre;
    }
    curr.suff=seg[r].suff;
    if(seg[r].suff==seg[r].len && seg[l].right==seg[r].left)
    {
        curr.suff=seg[r].len+seg[l].suff;
    }
    curr.maxm=max(seg[l].maxm,seg[r].maxm);
    if(seg[l].right==seg[r].left)
    {
        curr.maxm=max(curr.maxm,seg[l].suff+seg[r].pre);
    }
    return curr;
}

void build(int idx,int low,int high,string &s)
{
    if(low==high)
    {
       seg[idx].left=s[low];
       seg[idx].right=s[low];
       seg[idx].pre=1;
       seg[idx].suff=1;
       seg[idx].maxm=1;
       seg[idx].len=1;
       return;
    }
    int mid=low+(high-low)/2;
    build(2*idx+1,low,mid,s);
    build(2*idx+2,mid+1,high,s);
    seg[idx]=merge(idx);
}
void update(int idx,int low,int high,int i,char val)
{
    if(low==high)
    {
        seg[idx]=info(val,val,1,1,1,1);
        return ;
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
    seg[idx]=merge(idx);
}
};





class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        int n=s.length();
        int k=queryCharacters.length();
        segtree st(n);
        st.build(0,0,n-1,s);
        vector<int>ans(k);
        for(int i=0;i<k;i++)
        {
            char val=queryCharacters[i];
            st.update(0,0,n-1,queryIndices[i],val);
            ans[i]=st.seg[0].maxm;
        }
        return ans;



        
    }
};