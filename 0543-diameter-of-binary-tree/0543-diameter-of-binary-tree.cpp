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

   int ans=0;

   int height(TreeNode* node)
   {
    if(node==NULL)
    {
        return -1;
    }
    if(node->left==NULL && node->right==NULL)
    {
        return 0;
    }
    int left=height(node->left);
    int right=height(node->right);
    ans=max(ans,left+right+2);
    return max(left,right)+1; 
   }





    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;

        
        
    }
};