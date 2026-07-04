class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n=nums.size();
        vector<long long >p(n+1,0);
        for(int i=0;i<n;i++)
        {
            p[i+1]=p[i]+nums[i];
        }
        deque<int>dq;
        long long minm=1e18;
        vector<long long>dp(n,1e18);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=k)
            {
                dp[i]=1;
            }
            while(!dq.empty() && nums[i]+p[i]-p[dq.front()]>=k)
            {
                dp[i]=min(dp[i],(i-dq.front()+1LL));
                dq.pop_front();
            }
            minm=min(minm,dp[i]);
            while(!dq.empty() && p[dq.back()]>=p[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(minm==1e18)
        {
            minm=-1;
        }
        return minm;


       


        
    }
};