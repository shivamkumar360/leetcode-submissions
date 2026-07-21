class Solution {
public:

    int histo(vector<int>&arr)
    {
        int n=arr.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                int curr=st.top();
                st.pop();
                int prev=-1;
                int next=i;
                if(!st.empty())
                {
                    prev=st.top();
                }
                ans=max(ans,arr[curr]*(next-prev-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int curr=st.top();
            st.pop();
            int prev=-1;
            int next=n;
                if(!st.empty())
                {
                    prev=st.top();
                }
                ans=max(ans,arr[curr]*(next-prev-1));

        }
        return ans;
    }








    int maximalRectangle(vector<vector<char>>& matrix) {

        int r=matrix.size();
        int c=matrix[0].size();

        int ans=0;
        vector<int>temp(c,0);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(temp[j]!=0 && matrix[i][j]=='1')
                {
                    temp[j]++;
                }
                else if(matrix[i][j]=='1')
                {
                    temp[j]=1;
                }
                else
                {
                    temp[j]=0;
                }
            }
            ans=max(ans,histo(temp));

        }
        return ans;
        
    }
};