


class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int>temp(n);
        int cnt=0;
        temp[0]=0;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
            if (nums[i + 1] - nums[i] <= maxDiff)
            temp[i+1]=temp[i];
            else
            {
                cnt++;
                temp[i+1]=cnt;
            }
            }




           


        }
        vector<bool>ans;
        for(auto it:queries)
        {
            int u=it[0];
            int v=it[1];
            if(temp[u]==temp[v])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
        
    }
};