  bool comp(string &word1,string &word2)
    {
        if(word1.length()<word2.length())
        {
            return true;
        }
        return false;
    }
bool isvalid(string &word1,string &word2)
{
    int i=0;
    int j=0;
    int cnt=0;
    if(word1.length()!=word2.length()-1)return false;
    while( j<word2.length())
    {
        if(i<word1.length() && word1[i]==word2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
            cnt++;
        }
    }
    if(cnt!=1)
    {
        return false;
    }
    return true;


}

class Solution {
public:
   
    int longestStrChain(vector<string>& arr) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        vector<int>dp(n,1);
        int ans=1;
        for(int j=1;j<n;j++)
        {
            for(int i=j-1;i>=0;i--)
            {
                if(isvalid(arr[i],arr[j]))
                {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
            ans=max(ans,dp[j]);
        }
        return ans; 

       


       



        
    }
};