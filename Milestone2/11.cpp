// Tree Serialization and Deserialization

class Solution
{
    public:
    void inorder(Node* root, vector<int>&v)
    {
        if(!root)
        return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
        return;
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>v;
        inorder(root, v);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       Node* root=new Node(-1);
       Node* temp=root;
       for(int i=0; i<A.size(); i++)
       {
           temp->right = new Node(A[i]);
           temp=temp->right;
       }
       return root->right;
    }

};