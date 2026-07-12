class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())
        return {};
        vector<pair<int,int>>sorted;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            sorted.push_back({arr[i],i});
        }
        sort(sorted.begin(),sorted.end());
        int cnt=1;
        int last=sorted[0].first;
        for(int i=0;i<n;i++)
        {
            if(sorted[i].first!=last)
            {
                cnt++;
                last=sorted[i].first;
            }
            arr[sorted[i].second]=cnt;
        }
        return arr;




        
    }
};