class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n=points.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto it:points)
        {
            int x=it[0];
            int y=it[1];
            pq.push({(x*x+y*y),{x,y}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i>k-1)
            {
                points.pop_back();
            }
            else
            {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            points[i]={x,y};
            }
        }
        return points;
        
    }
};