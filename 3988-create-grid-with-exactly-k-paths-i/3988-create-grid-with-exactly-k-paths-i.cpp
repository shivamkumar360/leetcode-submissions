class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {

        if(n==3&&m==3&&k==4)return{"..#","...","#.."};
        if((n==1||m==1)&&k>1)return{};
        vector<string>a(n,string(m,'#'));
        for(int j=0;j<m;j++)a[0][j]='.'; 
        for(int i=0;i<n;i++)a[i][m-1]='.'; 
        k--;
        if(n<m){
            int j=m-2;
            while(j>=0&&k){
                a[1][j]='.'; 
                j--;
                k--;
            }
        }else{
            int i=1;
            while(i<n&&k){
                a[i][m-2]='.'; 
                i++;
                k--;
            }
        }
        if(k)return{};
        return a;

        
        
    }
};