class Solution {
public:
    int countSubstrings(string s) {

        int n=s.length();
        vector<bool>curr(n,false);
        vector<bool>prev(n,false);
        int ans=0;
        for(int l=n-1;l>=0;l--)
        {
            curr.assign(n,false);
            curr[l]=true;
            for(int r=l;r<n;r++)
            {
                if(r>l)
                {
            if(s[l]==s[r])
            {
                if(r==l+1)
                {
                    curr[r]=true;
                }
                else
                curr[r]=prev[r-1];
            }
                }
            if(curr[r]==true)
            {
                ans++;
            }
            }
            prev=curr;
        
            
        }
        return ans;
        
    }
};
