class Solution {
public:
    long long getSum(vector<int>& nums) {

        int n=nums.size();
        vector<long long>pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }

        vector<int>odd(n);
        int l=0;
        int r=-1;
        for(int i=0;i<n;i++)
        {
            int k=1;
            if(i<=r)
            {
                k=min(odd[l+r-i],r-i+1);
            }
            while(i-k>=0 && i+k<n && nums[i-k]==nums[i+k])
            {
                k++;
            }
            odd[i]=k;
            k--;
            if(i+k>r)
            {
                l=i-k;
                r=i+k;
            }
        }
        vector<int>even(n);
        l=0;
        r=-1;
        for(int i=0;i<n;i++)
        {
            int k=0;
            if(i<=r)
            {
                k=min(even[l+r-i+1],r-i+1);
            }
            while(i-k-1>=0 && i+k<n && nums[i-k-1]==nums[i+k])
            {
                k++;
            }
            even[i]=k;
            k--;
            if(i+k>r)
            {
                l=i-k-1;
                r=i+k;
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int left=i-odd[i]+1;
            int right=i+odd[i]-1;
            ans=max(ans,pre[right+1]-pre[left]);
        }
        for(int i=0;i<n;i++)
        {
            if(even[i]==0)
            {
                continue;
            }
            int left=i-even[i];
            int right=i+even[i]-1;
            ans=max(ans,pre[right+1]-pre[left]);
        }

        return ans;


        
    }
};