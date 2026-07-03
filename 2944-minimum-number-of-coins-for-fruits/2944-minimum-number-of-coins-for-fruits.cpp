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
        vector<long long>dp(n+1, 1e18);
        deque<int>dq;
        dp[n]=0;
        dq.push_back(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!dq.empty() && dq.front()>2*i+2)
            {
                dq.pop_front();
            }
            dp[i]=prices[i]+dp[dq.front()];
            while(!dq.empty() && dp[dq.back()]>=dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[0];


        
    }
};