class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        int n=heights.size();
        int m=queries.size();
        vector<tuple<int,int,int>>sorted;
        for(int i=0;i<m;i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            if(u<v)
            {
                swap(u,v);
            }
            int idx=i;
            tuple<int,int,int> temp={u,v,idx};
            sorted.push_back(temp);
        }
        sort(sorted.begin(),sorted.end());
        vector<int>st;
        int j=n-1;
        vector<int>ans(m);
        for(int i=m-1;i>=0;i--)
        {
            int y=get<0>(sorted[i]);
            int x=get<1>(sorted[i]);
            int idx=get<2>(sorted[i]);
            if(x==y || heights[y]>heights[x])
            {
                ans[idx]=y;
                continue;
            }
            while(j>y)
            {
                while(!st.empty() && heights[st.back()]<=heights[j])
                {
                    st.pop_back();
                }
                st.push_back(j);
                j--;
            }
            auto it=upper_bound(st.rbegin(),st.rend(),max(heights[y],heights[x]),[&](int h, int idx)
            {
                return h<heights[idx];
            });
            if(it==st.rend())
            {
                ans[idx]=-1;
            }
            else
            {
                ans[idx]=*it;
            }
        }
        return ans;
        
    }
};