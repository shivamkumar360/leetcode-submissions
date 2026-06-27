class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>>adj[n];
        for(auto it:times)
        {
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            adj[u-1].push_back({v-1,weight});
        }
        priority_queue<pair<int,int>>pq;
        pq.push({k-1,0});
        vector<int>dist(n,1e9);
        dist[k-1]=0;
        while(!pq.empty())
        {
            int node=pq.top().first;
            int weight=pq.top().second;
            pq.pop();
            if(weight>dist[node])
            {
                continue;
            }
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int edgeweight=it.second;
                if(dist[adjnode]>edgeweight+dist[node])
                {
                    dist[adjnode]=edgeweight+dist[node];
                    pq.push({adjnode,dist[adjnode]});
                }

            }
        }

        int ans=0;
            for(auto it:dist)
            {
                if(it==1e9)
                {
                    return -1;
                }
                ans=max(ans,it);
            }
            return ans;
    }
};