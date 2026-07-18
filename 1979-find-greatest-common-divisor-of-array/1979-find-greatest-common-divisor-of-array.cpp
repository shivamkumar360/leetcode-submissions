class Solution {
public:
    int findGCD(vector<int>& nums) {

        int maxm=*max_element(nums.begin(),nums.end());
        int minm=*min_element(nums.begin(),nums.end());
        return __gcd(maxm,minm);
        
    }
};