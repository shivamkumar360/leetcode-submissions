class Solution {
public:

    int bfs(int node, vector<int> adj[], int dest) {
        if (node == dest)
        return 0;
        vector<int>vis(4, 0);
        queue<pair<int,int>> q;
        q.push({node, 0});
        vis[node] = 1;
        while (!q.empty()) 
        {
            int adjnode = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (adjnode == dest) 
            return dist;
            for (auto it : adj[adjnode]) 
            {
                if (!vis[it]) 
                {
                    q.push({it, dist + 1});
                    vis[it] = 1;
                }
            }
        }
        return -1;
    }
   

    int minOperations(string s1, string s2) {

        vector<int>adj[4];
        adj[0]={1,2};
        adj[1]={3};
        adj[2]={3};
        adj[3]={0};
        int n=s1.length();
        int dist[4][4];
        for (int i = 0; i < 4; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                dist[i][j] = bfs(i, adj, j);
            }
        }

        vector<long long>prev(2,1e18);
        int tar=s2[n-1]-'0';
        prev[tar]=0;
        if(tar==1)
        {
            prev[0]=1;
        }

        for(int i=n-2;i>=0;i--)
        {
            int nxt=s1[i+1]-'0';
            vector<long long>curr(2,1e18);
            for(int bit=0;bit<=1;bit++)
            {
                int current=2*bit+nxt;
                for(int val=0;val<=1;val++)
                {
                    int target=2*(s2[i]-'0')+val;
                    int cost=dist[current][target];
                    if(prev[val]<1e17)
                    {
                        curr[bit]=min(curr[bit],(long long)cost+prev[val]);
                    }
                }
            }
            prev=curr;
        }
        

        long long result = prev[s1[0] - '0'];
        if(result>1e17)
        {
            result=-1;
        }
        return (int)result;
        
        
        
    }
};