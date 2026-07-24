class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n=nums.size();
        unordered_set<int>xo;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                xo.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>final;
        for(int i=0;i<n;i++)
        {
            for(auto it:xo)
            {
                final.insert(it^nums[i]);
            }
        }
        return final.size();
        
    }
};