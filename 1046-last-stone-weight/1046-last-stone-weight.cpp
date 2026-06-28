class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(auto it:stones)
        {
            pq.push(it);
        }
        while(!pq.empty())
        {
            int a=pq.top();
            pq.pop();
            int b;
            if(!pq.empty())
            {
                b=pq.top();
                pq.pop();
            }
            else
            {
                return a;
            }
            if(a-b!=0)
            {
                pq.push(a-b);
            }
        }
        return 0;


        
    }
};