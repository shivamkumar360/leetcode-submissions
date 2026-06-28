class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(auto it:stones)
        {
            pq.push(it);
        }
        while(pq.size() > 1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a-b!=0)
            {
                pq.push(a-b);
            }
        }
        if(!pq.empty())
        return pq.top();
        return 0;
        
    }
};
