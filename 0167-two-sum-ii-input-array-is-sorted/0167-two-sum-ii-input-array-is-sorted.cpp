class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int>ans(2);
        int n=numbers.size();
        int left=0;
        int right=n-1;
        int sum=0;
        while(left<right)
        {
            sum=numbers[left]+numbers[right];
            if(sum<target)
            {
                left++;
            }
            else if(sum==target)
            {
                ans[0]=left+1;
                ans[1]=right+1;
                return ans;
            }
            else
            {
                right--;
            }

        }
        return ans;



        
    }
};