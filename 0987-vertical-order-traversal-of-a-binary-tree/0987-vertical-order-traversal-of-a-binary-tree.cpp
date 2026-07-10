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

   void traverse(TreeNode* node,int row,int col,map<int, vector<pair<int,int>>>&mp)
   {
     if(node==NULL)
     {
        return ;
     }
     mp[col].push_back({row,node->val});
     traverse(node->left,row+1,col-1,mp);
     traverse(node->right,row+1,col+1,mp);
    
   }


    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, vector<pair<int,int>>> mp;
        traverse(root,0,0,mp);

        vector<vector<int>> ans;

        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end());

            vector<int> col;
            for (auto &p : it.second)
                col.push_back(p.second);

            ans.push_back(col);
        }
        return ans;





    }
};