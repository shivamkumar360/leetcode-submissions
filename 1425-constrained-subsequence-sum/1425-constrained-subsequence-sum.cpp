class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int n=nums.size();
        vector<long long>dp(n,0);
        deque<int>dq;
        long long maxm=-1e18;
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i];
            while(!dq.empty() && dq.front()<i-k)
            {
                dq.pop_front();
            }
            long long temp=0;
            if(!dq.empty())
            temp=dp[dq.front()];

            dp[i]=nums[i]+max(0LL,temp);

            maxm=max(maxm,dp[i]);
            if (dp[i] > 0) {
    while (!dq.empty() && dp[i] >= dp[dq.back()])
        dq.pop_back();
    dq.push_back(i);
}

        }
        return maxm;
    


        
    }
};