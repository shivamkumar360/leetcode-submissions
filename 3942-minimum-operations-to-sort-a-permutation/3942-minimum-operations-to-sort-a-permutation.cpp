class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();
        int inc=0;
        int dec=0;

            int pos=-1;
            for(int i=0;i<n;i++)
                {
                    if(nums[i]==0)
                    {
                        pos=i;
                        break;
                    }
                }
            int flag=1;
        for(int i=pos;i<n-1;i++)
            {
                if(nums[i+1]!=nums[i]+1)
                {
                    flag=0;
                }
            }
        for(int i=pos-1;i>0;i--)
            {
                if(nums[i-1]!=nums[i]-1)
                {
                    flag=0;
                }
            }
        if(flag==1)
        {
            return min(pos,(n-pos+2)); 
        }
        flag=1;
        for(int i=pos+1;i<n-1;i++)
            {
                if(nums[i+1]!=nums[i]-1)
                {
                    flag=0;
                }
            }
        for(int i=pos;i>0;i--)
            {
                if(nums[i-1]!=nums[i]+1)
                {
                    flag=0;
                }
            }
        if(flag==1)
        {
            return min(pos+1,n-pos-1)+1;
        }

        return -1;





        
        
            

        

        
        
    }
};