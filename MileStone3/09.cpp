// Count Number of SubTrees having given Sum


int ans(Node* root, int X, int &c)
{
    if(root==NULL)
    return 0;
    int lh=ans(root->left, X, c);
    int rh=ans(root->right, X, c);
    int total = root->data+lh+rh;
    if(total == X)
    c++;
    return total;
}
//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int c=0;
	int m= ans(root, X, c);
	return c;
}