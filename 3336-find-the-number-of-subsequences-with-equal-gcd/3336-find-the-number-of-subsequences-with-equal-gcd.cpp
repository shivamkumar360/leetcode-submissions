class Solution {
public:

    int mod=1e9+7;

    long long gcdpair(int idx,int gcd1,int gcd2,vector<int>&nums,vector<vector<vector<long long>>>&dp)
    {
        if(idx>=nums.size() && gcd1==gcd2)
        {
            return 1;
        }
        else if(idx>=nums.size())
        {
            return 0;
        }
        if(dp[idx][gcd1][gcd2]!=-1)
        {
            return dp[idx][gcd1][gcd2];
        }
        return dp[idx][gcd1][gcd2]=(gcdpair(idx+1,gcd1,gcd2,nums,dp)%mod+
        gcdpair(idx+1,__gcd(gcd1,nums[idx]),gcd2,nums,dp)%mod+
        gcdpair(idx+1,gcd1,__gcd(gcd2,nums[idx]),nums,dp)%mod)%mod;

    }


    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(201,vector<long long>(201,-1)));
        return (gcdpair(0,0,0,nums,dp)-1)%mod;


        
    }
};