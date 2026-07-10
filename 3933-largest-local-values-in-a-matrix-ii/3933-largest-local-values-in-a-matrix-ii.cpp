class Solution {
public:

   vector<vector<vector<int>>>pref;

   int query(int val,int sr,int sc,int er,int ec)
   {
    if(sr>er || sc>sc)
    {
        return 0;
    }
    return pref[val][er+1][ec+1]-pref[val][sr][ec+1]-pref[val][er+1][sc]+pref[val][sr][sc];
   }




    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               maxi=max(maxi,matrix[i][j]);

            }
        }
        int ans=0;
        pref.assign(maxi+1,vector<vector<int>>(n+1,vector<int>(m+1,0)));
        for(int v=0;v<=maxi;v++)
        {
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pref[v][i+1][j+1]=pref[v][i][j+1]+pref[v][i+1][j]-pref[v][i][j]+(matrix[i][j]>v);

            }
        }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=matrix[i][j];
                if(x==0)
                {
                    continue;
                }
                int sr=max(0,i-x);
                int er=min(n-1,i+x);
                int sc=max(0,j-x);
                int ec=min(m-1,j+x);
                int cnt=query(x,sr,sc,er,ec);
                vector<pair<int,int>>corn={{i-x,j-x},{i+x,j+x},{i-x,j+x},{i+x,j-x}};
                for(auto p:corn)
                {
                    int r=p.first;
                    int c=p.second;
                    if(r>=0 && r<n && c>=0 && c<m && matrix[r][c]>x)
                    {
                        cnt--;

                    }
                }
                if(cnt==0)
                {
                    ans++;
                }    

            }
        }


        return ans;
        
    }
};