// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/


class Solution {
  public:
  
   int sum_root(Node* root)
   {
       if(root==NULL)
       return 0;
       return sum_root(root->left)+ sum_root(root->right)+ root->data;
   }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *root)
    {
        // Your code here
        if(root==NULL)
        return;
        int sum=sum_root(root)-root->data;
        root->data=sum;
        toSumTree(root->left);
        toSumTree(root->right);
    }
};