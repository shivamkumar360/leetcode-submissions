class Solution {
public:
    int part(vector<int>&nums,int idx,int sum,vector<vector<int>>&dp)
    {
        if(idx>=nums.size() && sum!=0)
        {
            return 0;
        }
        if(idx>=nums.size())
        {
            return 1;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int ans=0;
        ans=ans || part(nums,idx+1,sum,dp);
        if(nums[idx]<=sum)
        {
            ans=ans || part(nums,idx+1,sum-nums[idx],dp);
        }
        return dp[idx][sum]=ans;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum%2)
        {
            return false;
        }
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        if(part(nums,0,sum/2,dp))
        return true;
        return false;

        
    }
};
