class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n=speed.size();
        vector<pair<int,int>>pos;
        for(int i=0;i<n;i++)
        {
            pos.push_back({position[i],speed[i]});
        }
        stack<pair<int,int>>st;
        sort(pos.begin(),pos.end());
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty())
            {
                int u=st.top().first;
                int v=st.top().second;
                double time=(target-u)/double(v);
                double reach;
                if(pos[i].second>v)
                {
                    double reach=(u-pos[i].first)/(double)(pos[i].second-v);
                    if(reach>time)
                    {
                        st.push({pos[i].first,pos[i].second});

                    }
                }
                else
                {
                    st.push({pos[i].first,pos[i].second});
                }
            }
            else
            {
                st.push({pos[i].first,pos[i].second});

            }
        }
        return st.size();



        
    }
};