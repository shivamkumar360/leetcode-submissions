class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();
        int len=queries.size();
        vector<long long>pre(n,0);
        vector<long long>suff(n,0);
        for(int i=0;i<n-1;i++)
        {
            long long diffr=(long long)nums[i+1]-nums[i];
            long long left=LLONG_MAX;
            if(i-1>=0)
            {
                left=(long long)nums[i]-nums[i-1];
            }
            pre[i+1]=pre[i]+(diffr<left?1:diffr);
        }
        for(int i=n-1;i>0;i--)
        {
            long long diffl=(long long)nums[i]-nums[i-1];
            long long diffr=LLONG_MAX;
            if(i+1<n)
            {
                diffr=(long long)nums[i+1]-nums[i];
            }
                suff[i-1]=suff[i]+(diffl<=diffr?1:diffl);
            
        }
        vector<int>ans(len);
        for(int i=0;i<len;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l<=r)
            {
                ans[i]=(int)(pre[r]-pre[l]);
            }
            else
            {
                ans[i]=(int)(suff[r]-suff[l]);
            }
        }
        return ans;


 
        

        
        
    }
};