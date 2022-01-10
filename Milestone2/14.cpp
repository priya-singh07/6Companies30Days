// Tree Burning

class Solution {
  public:
  int ans=0,f;
  bool d=false;
  int height(Node* root)
  {
      if(!root)
      return 0;
      int l=1+height(root->left);
      int r=1+height(root->right);
      return max(l,r);
  }
  void path(Node* root, int target, int m)
  {
      if(!root)
      return;
      if(root->data == target)
      {
          d=true;
          ans=height(root)-1;
          f=m;
          return ;
      }
      path(root->left, target, m+1);
      if(d)
      {
          int h=height(root->right);
          ans=max(ans, h+f-m);
          return ;
      }
      path(root->right, target, m+1);
      if(d)
      {
          int h=height(root->left);
          ans=max(ans, h+f-m);
          return ;
      }
  }
  int minTime(Node* root, int target) 
  {
        // Your code goes here
        path(root, target, 0);
        return ans;
   }
};