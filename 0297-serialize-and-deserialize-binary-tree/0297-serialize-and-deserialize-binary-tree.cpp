/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root==NULL)
        {
            return "";
        }
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* v=q.front();
            q.pop();
            if(v==NULL)
            {
                ans.append("#,");
            }
            else
            {
                ans.append(to_string(v->val)+",");
            }
            if(v!=NULL)
            {
                q.push(v->left);
                q.push(v->right);
            }
        }
        return ans;




        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty())return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                curr->left=NULL;
            }
            else
            {
            TreeNode* l=new TreeNode(stoi(str));
            curr->left=l;
            q.push(l);
            }


             getline(s,str,',');
            if(str=="#")
            {
                curr->right=NULL;
            }
            else
            {
            TreeNode* r=new TreeNode(stoi(str));
            curr->right=r;
            q.push(r);
            }

        }
        return root;


        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));