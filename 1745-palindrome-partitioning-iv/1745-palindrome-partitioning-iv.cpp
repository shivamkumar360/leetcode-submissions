class Solution {
public:

vector<vector<int>>dp;

   bool ispal(int i,int j,string &s)
   {
      if(i>=j)
      {
        return true;
      }
      if(dp[i][j]!=-1)
      {
        return dp[i][j];
      }
      if(s[i]==s[j])
      {
        return dp[i][j]=ispal(i+1,j-1,s);
      }
      return dp[i][j]=false;

   }




    bool checkPartitioning(string s) {

        int n=s.length();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(ispal(0,i,s) && ispal(i+1,j,s) && ispal(j+1,n-1,s))
                {
                    return true;
                }

            }
        }
        return false;
        



         
        
    }
};