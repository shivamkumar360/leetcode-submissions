class Solution {
public:

    long long mod=1e9+7;

    long long kadane(vector<int>&arr,int div)
    {
        long long sum=0;
        long long maxm=-1e18;
        for(int i=0;i<arr.size();i++)
            {
                if(arr[i]%div==0)
                sum+=arr[i];
                else
                {
                    sum-=arr[i];
                }
                maxm=max(maxm,sum);
                if(sum<0)
                {
                    sum=0;
                }
            }
        return maxm;
    }



    
    int divisibleGame(vector<int>& nums) {
        
        int n=nums.size();
        set<int>st;
        long long ans=-1e18;
         long long maxm=-1e18;
        for(auto i:nums)
        {
            int j=2;
            while(i>=j)
            {
                if(i%j==0)
                {
                    st.insert(j);
                    while(i%j==0)
                    {
                        i=i/j;
                    }
                }
                j++;
            }
        }
        int k=2;
        if(st.empty())
        {
            ans=-2;
        }
        for(auto it:st)
        {
            long long summ=kadane(nums,it);
            if(maxm<summ)
            {
                maxm=summ;
                ans=it*maxm;
                k=it;
            }
            else if(maxm==summ)
            {
                if(it<k)
                {
                    ans=it*summ;
                    k=it;
                }
            }
            
        }
        ans = (ans % mod +mod) % mod;
        return (int)ans;
        

    }
};