class Solution {
public:


    long long cut(int i,int j,vector<int>&cuts,vector<vector<long long>>&dp)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long ans=1e16;
        for(int idx=i+1;idx<=j-1;idx++)
        {
            ans=min(ans,(cuts[j]-cuts[i])+cut(i,idx,cuts,dp)+cut(idx,j,cuts,dp));
        }
        if(i+1==j)
        {
            ans=0;
        }
        return dp[i][j]=ans;

    }




    int minCost(int n, vector<int>& cuts) {
       cuts.push_back(0);
       cuts.push_back(n);
       sort(cuts.begin(),cuts.end());
       int sz=cuts.size();
       vector<vector<long long>>dp(sz,vector<long long>(sz,-1));
       return cut(0,sz-1,cuts,dp);

        
    }
};