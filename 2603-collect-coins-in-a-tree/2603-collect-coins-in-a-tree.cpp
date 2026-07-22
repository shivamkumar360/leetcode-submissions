class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {

        int n=coins.size();
        vector<unordered_set<int>>tree(n);
        for(auto it:edges)
        {
            tree[it[0]].insert(it[1]);
            tree[it[1]].insert(it[0]);
        }
        vector<int>leaf;
        
        for(int i=0;i<n;i++)
        {
            int u=i;
            while(tree[u].size()==1 && coins[u]==0)
            {
                int v=*(tree[u].begin());
                tree[u].erase(v);
                tree[v].erase(u);
                u=v;
            }
            if(tree[u].size()==1)
            {
                leaf.push_back(u);
            }
        }
        for(int j=0;j<2;j++)
        {
            vector<int>temp;
        for(int u:leaf)
        {
            if(tree[u].size()==1)
            {
                int v=*(tree[u].begin());
                tree[u].erase(v);
                tree[v].erase(u);
                if(tree[v].size()==1)
                {
                    temp.push_back(v);

                }
            }
        }
        leaf=temp;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=tree[i].size();
        }
        return ans;
    }
};