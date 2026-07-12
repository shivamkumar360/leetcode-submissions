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


   int lefth(TreeNode* node)
   {
    if(node==NULL)
    {
        return 0;
    }
    return 1+lefth(node->left);
   }
    int righth(TreeNode* node)
   {
    if(node==NULL)
    {
        return 0;
    }
    return 1+righth(node->right);
   }




    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh=lefth(root);
        int rh=righth(root);
        if(lh==rh)
        {
            return (1<<lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};