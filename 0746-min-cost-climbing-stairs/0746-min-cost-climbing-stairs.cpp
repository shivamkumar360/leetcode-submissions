class Solution {
public:

   int costs(vector<int>&cost,int idx,vector<int>&dp)
   {
    if(idx>=cost.size())
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    return dp[idx]=cost[idx]+min(costs(cost,idx+1,dp),costs(cost,idx+2,dp));
   }




    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(costs(cost,0,dp),costs(cost,1,dp));


        
    }
};