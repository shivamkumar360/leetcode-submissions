/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL)
        {
            return {};
        }

        int cnt=0;
        TreeNode* curr=NULL;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int step=q.front().second;
            if(cnt!=step)
            {
                ans.push_back(curr->val);
                cnt=step;
            }
            curr=node;
            q.pop();
            if(node->left!=NULL)
            q.push({node->left,step+1});
            if(node->right!=NULL)
            q.push({node->right,step+1});
        }
        ans.push_back(curr->val);
        return ans;

        
    }
};