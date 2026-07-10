class Solution {
public:

    static const int logm=18;
    int up[logm][100005];
    pair<int,int>arr[100005];
    int pos[100005];

    int jumps(int u,int v)
    {
        if(u==v)
        {
            return 0;
        }
        if(up[0][u]>=v)
        {
            return 1;
        }
        if(up[logm-1][u]<v)
        {
            return -1;
        }
        int jump=0;
        for(int i=logm-1;i>=0;i--)
        {
            if(up[i][u]<v)
            {
                jump+=(1<<i);
                u=up[i][u];
            }
        }
        return jump+1;
    }





    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        for(int i=0;i<n;i++)
        {
            arr[i]={nums[i],i};
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
           pos[arr[i].second]=i;
        }
        int right=0;
        for(int left=0;left<n;left++)
        {
            while(right<n-1 && arr[right+1].first-arr[left].first<=maxDiff)
            {
                right++;
            }
            up[0][left]=right;
        }
        for(int j=1;j<logm;j++)
        {
            for(int i=0;i<n;i++)
            {
                up[j][i]=up[j-1][up[j-1][i]];
            }
        }
        vector<int>ans;
        for(auto it:queries)
        {
            int u=pos[it[0]];
            int v=pos[it[1]];
            if(u>v)
            {
                swap(u,v);
            }
            ans.push_back(jumps(u,v));
        }

        return ans;


        
    }
};