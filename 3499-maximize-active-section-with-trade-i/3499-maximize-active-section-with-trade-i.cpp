class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
            pre[i]=sum;
            if(s[i]=='0')
            {
                sum++;
            }
            else
            {
                sum=0;
            }
        }

        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            suff[i]=sum;
            if(s[i]=='0')
            {
                sum++;
            }
            else
            {
                sum=0;
            }
        }
        int ans=0;
        int l=0;
        int r=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                int st=i;
                while(i<n-1 && s[i+1]==s[i])
                {
                    i++;
                }
                if(pre[st]>0 && suff[i]>0)
                ans=max(ans,pre[st]+suff[i]);
            }
        }
        return ans+cnt;


        
    }
};