/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

   TreeNode* ans=NULL;


    void lca(TreeNode* root,TreeNode* p,TreeNode*q,unordered_map<TreeNode*,pair<bool,bool>>&mp)
    {
        mp[root]={false,false};
        if(root==p)
        {
            mp[root].first=true;
        }
        if(root==q)
        {
            mp[root].second=true;
        }
        if(root->left!=NULL)
        {
            lca(root->left,p,q,mp);
            if(mp[root->left].first==true)
            {
                mp[root].first=true;
            }
            if(mp[root->left].second==true)
            {
                mp[root].second=true;
            }
        }
        if(root->right!=NULL)
        {
            lca(root->right,p,q,mp);
            if(mp[root->right].first==true)
            {
                mp[root].first=true;
            }
            if(mp[root->right].second==true)
            {
                mp[root].second=true;
            }
        }
        if(mp[root].first==true && mp[root].second==true && ans==NULL)
        {
            ans= root;
        }
    }




    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL)
        {
            return NULL;
        }
        unordered_map<TreeNode*,pair<bool,bool>>mp;
        lca(root,p,q,mp);
        return ans;



        
    }
};