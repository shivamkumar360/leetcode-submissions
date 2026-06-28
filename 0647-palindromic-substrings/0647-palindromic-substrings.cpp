class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        int l=0;
        int r=n-1;
        int ans=0;
        for(int l=n-1;l>=0;l--)
        {
            for(int r=l;r<n;r++)
            {
                if(r>l)
                {
            if(s[l]==s[r])
            {
                if(r==l+1)
                {
                    dp[l][r]=true;
                }
                else
                dp[l][r]=dp[l+1][r-1];
            }
                }
            if(dp[l][r]==true)
            {
                ans++;
            }
            }
        
            
        }
        return ans;

        
    }
};