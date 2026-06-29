class Solution {
public:
    const long long neg = -4e18;
    long long maxSubarraySum(vector<int>& nums, int k) {

        long long ans=neg, before=neg, inside=neg, after=neg;
        for(int a:nums){
            long long kx=(long long)a*k;
            after=max(inside,after)+a;
            inside=max({0LL,inside,before})+kx;
            before =max(0LL,before) + a;
            ans = max({ans, before, after, inside});
        }
        before=neg, inside=neg, after=neg;
        for(int a:nums){
            long long kx=(long long)a/k;
            after=max(inside,after)+a;
            inside=max({0LL,inside,before})+kx;
            before = max(0LL,before) + a;
            ans = max({ans, before, after, inside});
        }
        return ans;

        
        
    }
};