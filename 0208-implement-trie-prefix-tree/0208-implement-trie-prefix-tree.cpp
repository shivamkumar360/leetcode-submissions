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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */