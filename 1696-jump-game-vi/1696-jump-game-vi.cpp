class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        int n=nums.size();
        vector<long long >dp(n+1,-1e18);
        dp[0]=nums[0];
        deque<int>dq;
        for(int i=1;i<n;i++)
        {
            int newi=i-1;
            if(newi>=0)
            {
            while(!dq.empty() && dp[newi]>=dp[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(newi);
            }
            if(!dq.empty() && dq.front()<newi-k+1)
            {
                dq.pop_front();
            }
            if(!dq.empty())
            {
                dp[i]=nums[i]+dp[dq.front()];
            }
        }

        return dp[n-1];


        
    }
};