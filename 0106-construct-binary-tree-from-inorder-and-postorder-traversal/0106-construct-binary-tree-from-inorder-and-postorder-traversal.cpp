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


    TreeNode* build(TreeNode* root,vector<int>&inorder,vector<int>&postorder,int st1,int en1,int st2,int en2,vector<int>&pos)
    {
        root->val=postorder[en2];
        int poss=pos[root->val+3000];
        int left=poss-st1;
        int right=en1-poss;
        if(left>0)
        {
            root->left=new TreeNode();
            build(root->left,inorder,postorder,st1,poss-1,st2,en2-right-1,pos);
        }
        if(right>0)
        {
            root->right=new TreeNode();
            build(root->right,inorder,postorder,poss+1,en1,en2-right,en2-1,pos);
        }
        return root;

    }





    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())return NULL;

        int n=inorder.size();

        vector<int> pos(6001);

    for (int i = 0; i < inorder.size(); i++)
    pos[inorder[i] + 3000] = i;




        TreeNode* root=new TreeNode();
        return build(root,inorder,postorder,0,n-1,0,n-1,pos);

        
        
    }
};