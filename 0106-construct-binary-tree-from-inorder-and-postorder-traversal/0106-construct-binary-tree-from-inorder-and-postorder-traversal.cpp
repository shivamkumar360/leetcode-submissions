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


    TreeNode* build(TreeNode* root,vector<int>&inorder,vector<int>&postorder,int st1,int en1,int st2,int en2)
    {
        root->val=postorder[en2];
        int pos=-1;
        for(int idx=st1;idx<=en1;idx++)
        {
            if(inorder[idx]==root->val)
            {
                pos=idx;
                break;

            }
        }
        int left=pos-st1;
        int right=en1-pos;
        if(left>0)
        {
            root->left=new TreeNode();
            build(root->left,inorder,postorder,st1,pos-1,st2,en2-right-1);
        }
        if(right>0)
        {
            root->right=new TreeNode();
            build(root->right,inorder,postorder,pos+1,en1,en2-right,en2-1);
        }
        return root;

    }





    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())return NULL;

        int n=inorder.size();
        TreeNode* root=new TreeNode();
        return build(root,inorder,postorder,0,n-1,0,n-1);

        
        
    }
};