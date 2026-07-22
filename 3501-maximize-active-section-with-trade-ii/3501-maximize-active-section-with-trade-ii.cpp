class Segtree
{
    vector<int>seg;
    public:
    Segtree(int n)
    {
        seg.resize(4*n+1);
    }
    void build(int idx,int low,int high,vector<int>&arr)
    {
          if(low > high)
        return;
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
    int query(int idx,int low,int high,int l,int r)
    {

         if(l > r || low > high)
        return INT_MIN;


        if(high<l || low>r)
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

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int sz=s.length();
        int n=queries.size();
        vector<int>start;
        vector<int>en;
        vector<int>leng;
        for(int i=0;i<sz;i++)
        {
            int st=i;
            while(i<sz-1 && s[i]==s[i+1])
            {
                i++;
            }
            if(s[st]=='0')
            {
                start.push_back(st);
                en.push_back(i);
                leng.push_back(i-st+1);
            }
        }

         int total=count(s.begin(),s.end(),'1');

         if(leng.size()<2)
        {
            return vector<int>(n,total);
        }



        vector<int>gain;
        for(int i=0;i<leng.size()-1;i++)
        {
            gain.push_back(leng[i]+leng[i+1]);
        }

         
        int g = gain.size();
        Segtree sg(max(1,g));

        if(g>0)
        sg.build(0,0,g-1,gain);
      
       
        vector<int>ans;
        for(auto it:queries)
        {
            int ll=it[0];
            int rr=it[1];
            int ss=lower_bound(en.begin(),en.end(),ll)-en.begin();
            int ee=upper_bound(start.begin(),start.end(),rr)-start.begin()-1;
            if(ss>=ee || ss>=leng.size() || ee<0)
            {
                ans.push_back(total);
                continue;
            }

            int firstLen =
                en[ss] - max(start[ss], ll) + 1;

            int lastLen =
                min(en[ee], rr) - start[ee] + 1;

            if (ss+ 1 == ee) {
                ans.push_back(total + firstLen + lastLen);
                continue;
            }

            int best=0;
            best=max(best,firstLen+leng[ss+1]);
            best=max(best,lastLen+leng[ee-1]);
            best=max(best,sg.query(0,0,g-1,ss+1,ee-2));
            ans.push_back(best+total);


            



        }
        return ans;



        
    }
};