class Solution {
public:
    bool isPalindrome(string s) {
        int a=0;
        int b=s.length()-1;
        while(a<=b)
        {
            while(a<b)
            {
                if(!isalnum(s[a]))
                {
                    a++;
                }
                else
                break;

            }
            while(a<b)
            {
                if(!isalnum(s[b]))
                {
                    b--;
                }
                else
                break;

            }
            if(tolower(s[a])==tolower(s[b]))
            {
                a++;
                b--;
            }
            else
            return false;
        }
        return true;
        
    }
};