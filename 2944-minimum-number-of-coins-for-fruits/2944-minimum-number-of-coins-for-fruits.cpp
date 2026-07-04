class Solution {
public:
    int minimumCoins(vector<int>& prices) {

        int n=prices.size();
        vector<long long>dp(n+1,1e18);
        dp[n]=0;
        deque<int>dq;
        dq.push_back(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!dq.empty() && dq.front()>min(n,2*i+2))
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