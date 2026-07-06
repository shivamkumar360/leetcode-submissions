class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int mini=INT_MAX;
        long long b=budget;
        for(int i=0;i<n;i++)mini=min(mini,items[i][1]);
        vector<long long>cnt(n+1,0);
        for(int i=0;i<n;i++)cnt[items[i][0]]++;

        vector<long long>mul(n+1,0);
        for(int f=1;f<=n;f++){
            for(int m=f;m<=n;m+=f)mul[f]+=cnt[m];
        }
        map<int,long long>mp;
        for(int i=0;i<items.size();i++){
            int a=items[i][0];
            int b=items[i][1];
            long long d=mul[a]-1;
            if(d>0 && b<=2*mini)mp[b]+=d;
        }
        long long ans=0;
        for(auto&it : mp){
            long long x = it.first;
            long long y = it.second;
            long long pk=min(y,b/x);
            ans+=2*pk;
            b-=pk*x;
        }
        ans+=b/mini;
        return ans;
        
    }
};