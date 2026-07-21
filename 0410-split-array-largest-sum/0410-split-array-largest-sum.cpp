class Solution {
public:

    bool isvalid(vector<int>&arr,long long mid,int k)
    {
        int n=arr.size();
        long long sum=0;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
            {
                return false;
            }
            if(sum+arr[i]>mid)
            {
                cnt++;
                sum=0;
            }
            sum+=arr[i];
        }
        if(cnt>k)
        return false;
        return true;

    }




    int splitArray(vector<int>& nums, int k) {

        long long st=0;
        long long end=1e9+1;
        long long ans=0;
        while(st<=end)
        {
            long long mid=st+(end-st)/2;
            if(isvalid(nums,mid,k))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return (int)ans;


        
    }
};