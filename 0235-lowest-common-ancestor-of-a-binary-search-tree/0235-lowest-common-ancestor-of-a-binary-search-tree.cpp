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


    TreeNode* lca(TreeNode* root,TreeNode* p, TreeNode* q)
    {

        int pval=p->val;
        int qval=q->val;
        int rval=root->val;
        if(pval>rval && qval>rval)
        {
            return lca(root->right,p,q);
        }
        else if(pval<rval && qval<rval)
        {
            return lca(root->left,p,q);
        }
        else 
        {
            return root;
        }
       



        // if(root==NULL || root==p || root==q)
        // {
        //     return root;
        // }
        // TreeNode* left=lca(root->left,p,q);
        // TreeNode* right=lca(root->right,p,q);
        // if(left!=NULL && right!=NULL)
        // {
        //     return root;
        // }
        // else if(left==NULL)
        // {
        //     return right;
        // }
        // else
        // {
        //     return left;
        // }
    }




    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lca(root,p,q);
        
    }
};