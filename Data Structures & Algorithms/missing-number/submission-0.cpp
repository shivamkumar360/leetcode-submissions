class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            x=x^i;
        }
        int xn=0;
        for(auto it:nums)
        {
            xn^=it;
        }
        return xn^x;
        
    }
};
