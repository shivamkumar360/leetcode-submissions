class Solution {
public:
    const static int nmax=(int)1e5+2;
    int bits[nmax];
    
    int highestPowerOf2(int n) {
    if (n == 0) return 0;
    return 1 << (31 - __builtin_clz(n));
}
    void init()
    {
        bits[0]=0;
    bits[1]=1;
    bits[2]=1;
    bits[3]=2;
    bits[4]=1;
        for(int i=5;i<nmax;i++)
        {
            int high=highestPowerOf2(i);
            int diff=i-high;
            bits[i]=bits[diff]+1;
        }
    }
    vector<int> countBits(int n) {
        init();
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(bits[i]);
        }
        return ans;
        
        
    }
};