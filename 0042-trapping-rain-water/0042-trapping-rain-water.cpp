class Solution {
public:
    int trap(vector<int>& arr) {

        int n=arr.size();
        int lmax=0;
        int rmax=0;
        int st=0;
        int end=n-1;
        int ans=0;
        while(st<end)
        {
            lmax=max(lmax,arr[st]);
            rmax=max(rmax,arr[end]);
            if(lmax<rmax)
            {
                ans+=lmax-arr[st];
                st++;
            }
            else
            {
                ans+=rmax-arr[end];
                end--;
            }
        }

       
        
        return ans;





        
    }
};