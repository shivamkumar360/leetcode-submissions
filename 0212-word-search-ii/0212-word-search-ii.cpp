class Node
{
    public:
    Node *links[26];
    bool flag=false;

    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    Node* getkey(char ch)
    {
        return links[ch-'a'];
    }
    void setkey(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    void setend()
    {
        flag=true;
    }


};

class Trie {
    private:
    Node *root;
public:
    Trie() {
        root=new Node();
        
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
            {
                node->setkey(word[i],new Node());
            }
            node=node->getkey(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            
            if(!node->containskey(word[i]))
            {
                return false;
            }
            node=node->getkey(word[i]);
        }
        if(node->flag==true)
        {
            return true;
        }
        return false;

        
    }
    
    bool startsWith(string word) {

        Node* node=root;

        for(int i=0;i<word.length();i++)
        {
            
            if(!node->containskey(word[i]))
            {
                return false;
            }
            node=node->getkey(word[i]);
        }
        if(node!=NULL)
        return true;
        return false;
        
    }

    Node* getRoot(){return root;}
};



class Solution {
public:

   void findword(vector<vector<char>>&board,set<string>&ans,int row,int col,string word,Node* root)
   {
    int n=board.size();
    int m=board[0].size();
     if(row>=n || row<0 || col<0 || col>=m || board[row][col]==' ')
     {
        return ;
     }
     if(root->containskey(board[row][col]))
     {
        word+=board[row][col];
        root=root->getkey(board[row][col]);
        if(root->flag)
        {
            ans.insert(word);
        }
        char c=board[row][col];
        board[row][col]=' ';
        findword(board,ans,row+1,col,word,root);
        findword(board,ans,row-1,col,word,root);
        findword(board,ans,row,col+1,word,root);
        findword(board,ans,row,col-1,word,root);
        board[row][col]=c;
     }


   }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        Trie t;
        for(auto it:words)
        {
            t.insert(it);
        }
        set<string>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                findword(board,ans,i,j,"",t.getRoot());
            }
        }
        vector<string>an;
        for(auto it:ans)
        {
            an.push_back(it);
        }
        return an;


        
    }
};