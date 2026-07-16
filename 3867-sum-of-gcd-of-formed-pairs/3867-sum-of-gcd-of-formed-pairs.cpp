class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>pre(n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            pre[i]=__gcd(mx,nums[i]);
        }
        long long sum=0;
        sort(pre.begin(),pre.end());
        int l=0;
        int r=n-1;
        while(l<r)
        {
            sum+=__gcd(pre[l],pre[r]);
            l++;
            r--;
        }
        return sum;

        
    }
};