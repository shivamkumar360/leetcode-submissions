class Solution {
public:
    

    void init(vector<int>& bits,int n)
    {
        bits[0]=0;
        int high = 1;
    
        for(int i=1;i<=n;i++)
        {
            if(high*2==i)
            {
                high=i;
            }
            bits[i]=bits[i-high]+1;
        }
    }
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        init(bits,n);
        return bits;
        
        
    }
};