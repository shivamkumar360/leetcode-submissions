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

    int sz(TreeNode* root)
    {
        if(root==NULL)return 0;
        return sz(root->left)+sz(root->right)+1;
    }


    int kthSmallest(TreeNode* root, int k) {

        if(root->left==NULL && root->right==NULL)return root->val;
        
        if(root->left==NULL)
        {
            if(k==1)return root->val;
            else
            {
                return kthSmallest(root->right,k-1);
            }
        }
        
        int v=sz(root->left)+1;
        if(k==v)return root->val;
        else if(k>v)return kthSmallest(root->right,k-v);
        else
        {
            return kthSmallest(root->left,k);
        }
        

       


        
    }
};