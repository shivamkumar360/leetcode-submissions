class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int n=nums.size();
        vector<long long>dp(n,-1e18);
        long long maxm=-1e18;
        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.front()<i-k)
            {
                dq.pop_front();
            }
            dp[i]=nums[i];
            if(!dq.empty())
            dp[i]+=max(0LL,dp[dq.front()]);
            while(!dq.empty() && dp[dq.back()]<=dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            maxm=max(maxm,dp[i]);
        }
        return maxm;



        
      
    


        
    }
};