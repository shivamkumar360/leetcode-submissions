class Solution {
public:

    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2_in, vector<vector<int>>& queries) {

        int n=nums2_in.size();
        vector<long long> nums2(n);
        for(int i = 0; i < n; i++) nums2[i] = nums2_in[i];

        unordered_map<int,int> cnt1;

        for(auto x:nums1)
        cnt1[x]++;

           // int n=nums2.size();
            int sz=sqrt(n);
            if (sz == 0) sz = 1;
            int bl=(n+sz-1)/sz;
            vector<long long>lazy(bl,0);
            vector<unordered_map<long long,int>>freq(bl);
            for(int i=0;i<n;i++)
            {
                freq[i/sz][nums2[i]]++;
            }
            vector<int>ans;
            for(auto it:queries)
            {
                if(it[0]==1)
                {
                    int x=it[1];
                    int y=it[2];
                    long long val=it[3];
                    int left=x/sz;
                    int right=y/sz;
                    if(left==right)
                    {
                        for(int i=x;i<=y;i++)
                        {
                            freq[i/sz][nums2[i]]--;
                            if(freq[i/sz][nums2[i]]==0)
                            {
                                freq[i/sz].erase(nums2[i]);
                            }
                            nums2[i]+=val;
                            freq[i/sz][nums2[i]]++;
                        }
                    }
                    else
                    {
                        
                        for(int i=x;i<min((left+1)*sz,n);i++)
                        {
                            freq[i/sz][nums2[i]]--;
                            if(freq[i/sz][nums2[i]]==0)
                            {
                                freq[i/sz].erase(nums2[i]);
                            }
                            nums2[i]+=val;
                            freq[i/sz][nums2[i]]++;
                            
                        }
                        for(int i=left+1;i<right;i++)
                        {
                            lazy[i]+=val;       
                        }
                        for(int i=max(0,right*sz);i<=y;i++)
                        {
                            freq[i/sz][nums2[i]]--;
                            if(freq[i/sz][nums2[i]]==0)
                            {
                                freq[i/sz].erase(nums2[i]);
                            }
                            nums2[i]+=val;
                            freq[i/sz][nums2[i]]++;
                        }
                    }
                }
                else
                {
                    long long tot=it[1];
                    long long cur=0;
                    for(auto &[x,c]:cnt1)
                    {
                        long long ele=x;
                        long long tar=tot-ele;
                        for(int b=0;b<bl;b++)
                        {
                            long long req=tar-lazy[b];
                            auto it = freq[b].find(req);
                            if(it!=freq[b].end())
                            cur += 1LL*c*it->second;
                        }
                    }
                    ans.push_back((int)cur);
                }
            }
            return ans;

        
    }
};