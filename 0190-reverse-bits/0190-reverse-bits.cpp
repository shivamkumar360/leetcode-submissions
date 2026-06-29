class Solution {
public:
    int reverseBits(int n) {

        int ans=0;
        for(int i=31;i>=0;i--)
        {
            ans+=(((1LL<<i) & n)?1:0)*(1LL<<(31-i));
        }
        return ans;
        
    }
};