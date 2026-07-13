class Solution {
public:

    int digits(long long num)
    {
        int cnt=0;
        while(num!=0)
        {
            cnt++;
            num/=10;
        }
        return cnt;
    }




    vector<int> sequentialDigits(int low, int high) {

        int dig1=digits(low);
        int dig2=digits(high);
        vector<int>ans;
        int flag=0;
        for(int i=dig1;i<=dig2;i++)
        {
            int temp=0;
            for(int j=1;j<=(10-i);j++)
            {
                int st=j;
                int temp=0;
                for(int k=1;k<=i;k++)
                {
                    temp*=10;
                    temp+=st;
                    st++;
                }
                if(temp>high)
                {
                    flag=1;
                    break;
                }
                if(temp>=low)
                {
                    ans.push_back(temp);
                }
            }
            if(flag==1)
            {
                break;
            }
        }

        return ans;


        
    }
};