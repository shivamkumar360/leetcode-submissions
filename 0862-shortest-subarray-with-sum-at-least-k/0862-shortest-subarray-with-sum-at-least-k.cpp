class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int st=0;
        int end=0;
        long long sum=0;
        int minm=n+1;
        vector<long long>p(n+1,0);
        for(int i=0;i<n;i++)
        {
            p[i+1]=p[i]+nums[i];
        }
        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=k)
            {
                minm=1;
            }
            else
            {
                while (!dq.empty() &&
       nums[i] + p[i] - p[dq.front()] >= k)
{
    minm = min(minm, i - dq.front() + 1);
    dq.pop_front();
}
            }
            while(!dq.empty() && p[dq.back()]>=p[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(minm==n+1)
        {
            minm=-1;
        }
        return minm;


        
    }
};