class Solution {
public:
    int decode(string&s,int idx,vector<int>&dp)
    {
        if(idx>=s.length())
        {
            return 1;
        }
        if(s[idx]-'0'== 0 )
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int ans=0;
        ans+=decode(s,idx+1,dp);
        if(idx+1<s.length() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')))
        {
            ans+=decode(s,idx+2,dp);
        }
        return dp[idx]=ans;

    }
    int numDecodings(string s) {
         int n=s.length();
        vector<int>dp(n,-1);
        return decode(s,0,dp);
        
    }
};
