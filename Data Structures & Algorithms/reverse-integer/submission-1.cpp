class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0)
        {
            int rem=x%10;
            if(res>INT_MAX/10)
            {
                return 0;
            }
            else if(res<INT_MIN/10)
            {
                return 0;
            }
            else
            {
                res=res*10;
                res+=rem;
            }
            x/=10;

        }
        return res;

        
    }
};
