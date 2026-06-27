class Solution {
public:


   void dfs(string node,map<string,priority_queue<string,vector<string>,greater<string>>>&adj,vector<string>&ans)
   {
    
    while(!adj[node].empty())
    {
        string adjnode=adj[node].top();
        adj[node].pop();
        dfs(adjnode,adj,ans);
    }
    ans.push_back(node);
   }





    vector<string> findItinerary(vector<vector<string>>& tickets) {
        

        map<string,priority_queue<string,vector<string>,greater<string>>>adj;
        for(int i=0;i<tickets.size();i++)
        {
            string u=tickets[i][0];
            string v=tickets[i][1];
            adj[u].push(v);
        }
        vector<string>ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;



        
    }
};