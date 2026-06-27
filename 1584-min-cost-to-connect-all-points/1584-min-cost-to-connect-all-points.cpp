


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,-1}});
        vector<int>vis(n,0);
        int ans=0;
        while(!pq.empty())
        {
            int node=pq.top().second.first;
            int cost=pq.top().first;
            int parent=pq.top().second.second;
            pq.pop();
            if(vis[node])continue;
            if(parent!=-1)
            {
                ans+=cost;
            }
            vis[node]=1;
            
            for(int i=0;i<n;i++)
            {
                if(!vis[i] && i!=node)
                {
                    int wei=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
                    pq.push({wei,{i,node}});
                }
            }

        }
        return ans;
    }
};