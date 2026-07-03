class Solution {
public:

    long long fruit(int idx,vector<int>&prices,vector<long long>&dp)
    {
        int n=prices.size();
        if(idx>=prices.size())
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        long long ans=1e18;
        for(int i=idx+1;i<=min(n,idx+idx+2);i++)
        {
            ans=min(ans,fruit(i,prices,dp));
        }
        return dp[idx]=prices[idx]+ans;
    }




    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<long long>dp(n,-1);
        return fruit(0,prices,dp);


        
    }
};