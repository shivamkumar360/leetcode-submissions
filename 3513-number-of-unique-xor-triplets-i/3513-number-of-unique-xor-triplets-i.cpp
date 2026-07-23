class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return 1;
        if(n==2)return 2;

        int xo=0;
        for(int i=0;i<n;i++)
        {
            xo |=nums[i];
        }
        return xo+1;
    }
};