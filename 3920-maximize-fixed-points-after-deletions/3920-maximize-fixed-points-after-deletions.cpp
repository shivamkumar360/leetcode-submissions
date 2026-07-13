class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans;
        vector<pair<int,int>>shift;
        for(int i=0;i<n;i++)
        {
            if(i>=nums[i])
            {
                shift.push_back({i-nums[i],nums[i]});
            }
        }
        sort(shift.begin(),shift.end());


        for(auto it:shift)
        {
            int x=it.second;
            auto last=lower_bound(ans.begin(),ans.end(),x);
            if(last==ans.end())
            {
                ans.push_back(x);
            }
            else
            {
                *last=x;
            }
        }
       return ans.size();
        
        
    }
};