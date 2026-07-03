class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        int n=nums.size();
        vector<long long >dp(n+1,-1e18);
        dp[0]=nums[0];
        deque<int>dq;
        dq.push_back(0);
        for(int i=1;i<n;i++)
        {
            int newi=i-1;
            while(!dq.empty() && dq.front()<i - k)
            {
                dq.pop_front();
            }
             
            if(!dq.empty())
            {
                dp[i]=nums[i]+dp[dq.front()];
            }
          
            while(!dq.empty() && dp[i]>=dp[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
           
        }

        return dp[n-1];


        
    }
};