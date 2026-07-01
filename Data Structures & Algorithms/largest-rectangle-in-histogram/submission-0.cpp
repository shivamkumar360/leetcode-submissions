class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        stack<int>st;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                int temp=st.top();
                st.pop();
                int nse=i;
                int pse=-1;
                if(!st.empty())
                {
                    pse=st.top();
                }
                ans=max(ans,heights[temp]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
            {
                int temp=st.top();
                st.pop();
                int nse=n;
                int pse=-1;
                if(!st.empty())
                {
                    pse=st.top();
                }
                ans=max(ans,heights[temp]*(nse-pse-1));
            }
            return ans;

        
    }
};
