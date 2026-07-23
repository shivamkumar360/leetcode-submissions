class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<int,int>mp;
        int n=s.length();
        int l=0;
        int r=0;
        int maxm=0;
        int ans=0;
        while( r<n)
        {
            mp[s[r]-'A']++;
            if(maxm<mp[s[r]-'A'])
            {
                maxm=mp[s[r]-'A'];
            }
            int len=r-l+1;
            while(len-maxm>k)
            {
                mp[s[l]-'A']--;
                l++;
                len=r-l+1;
            }
            ans=max(ans,len);
            r++;

        }
        return ans;


       
        
    }
};