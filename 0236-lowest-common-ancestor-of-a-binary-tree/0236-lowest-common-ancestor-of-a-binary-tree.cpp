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

   //TreeNode* ans=NULL;


    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode*q)
    {
        if(root==p || root==q || root==NULL)
        {
            return root;
        }
        TreeNode* left=  lca(root->left,p,q);
        TreeNode* right= lca(root->right,p,q);
        if(left!=NULL && right!=NULL)
        {
            return root;
        }
        else if(left==NULL)
        return right;
        return left;
   
    }




    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL)
        {
            return NULL;
        }
   
        return lca(root,p,q);
    



        
    }
};