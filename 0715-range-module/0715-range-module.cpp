class Node
{
    public:
    bool covered;
    int lazy;
    Node* left,*right;
    Node()
    {
        covered=false;
        lazy=-1;
        left=right=nullptr;
    }

};





class RangeModule {

    Node *root;
    public:
    RangeModule() {
        root=new Node();
    }

    void push(Node *node)
{
    if(node->left==nullptr)
        node->left=new Node();

    if(node->right==nullptr)
        node->right=new Node();

    if(node->lazy==-1)
        return;

    node->left->covered=node->lazy;
    node->right->covered=node->lazy;

    node->left->lazy=node->lazy;
    node->right->lazy=node->lazy;

    node->lazy=-1;
}

    void update(Node* node,int low,int high,int l,int r,bool val)
    {
        if(high<l || low>=r)
        {
            return ;
        }
        else if(low>=l && high<r)
        {
            node->covered=val;
            node->lazy=val;
            return;
        }
        else
        {
            int mid=low+(high-low)/2;
            if(low!=high)
            {
            push(node);
            update(node->left,low,mid,l,r,val);
            update(node->right,mid+1,high,l,r,val);
            node->covered=node->left->covered && node->right->covered;
            }

        }

    }

    bool query(Node* node,int low,int high,int l,int r)
    {
        if(high<l || low>=r)
        {
            return true ;
        }
        else if(low>=l && high<r)
        {
            return node->covered;
        }
        else
        {
            int mid=low+(high-low)/2;
            if(low!=high)
            {
            push(node);
            bool left=query(node->left,low,mid,l,r);
            bool right=query(node->right,mid+1,high,l,r);
            return left && right;
            }
            else
            {
                return node->covered;
            }

        }
    }


  






    
    void addRange(int l, int r) {

        update(root,0,1000000000,l,r,true);
    }

   
    
    bool queryRange(int l, int r) {
        return query(root,0,1000000000,l,r);
    }
    
    void removeRange(int l, int r) {
        update(root,0,1000000000,l,r,false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */