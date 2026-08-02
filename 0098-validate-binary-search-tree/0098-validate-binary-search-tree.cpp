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


    int maxm(TreeNode* root)
    {
        if(root==NULL)return INT_MIN;
        int mxm=root->val;
        int l=maxm(root->left);
        int r=maxm(root->right);
        return max(mxm,max(l,r));
    }

     int minm(TreeNode* root)
    {
        if(root==NULL)return INT_MAX;
        int mnm=root->val;
        int l=minm(root->left);
        int r=minm(root->right);
        return min(mnm,min(l,r));
    }
    
    bool check(TreeNode* root,long long low,long long high)
    {
        if(root==NULL)return true;
        if(root->val<=low || root->val >=high)return false;
        return check(root->left,low,root->val) && check(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {

        if(root==NULL)return true;


        return check(root,LLONG_MIN,LLONG_MAX);
        
      //  return false;

        
        
    }
};