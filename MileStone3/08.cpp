// Connect Nodes at Same Level


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*>q;
       q.push(root);
       q.push(NULL);
       while(!q.empty())
       {
           Node* n = q.front();
           q.pop();
           if(n == NULL)
           {
               if(!q.empty())
               q.push(NULL);
           }
           else
           {
               n->nextRight = q.front();
               if(n->left)
               q.push(n->left);
               if(n->right)
               q.push(n->right);
           }
       }
    }    
      
};