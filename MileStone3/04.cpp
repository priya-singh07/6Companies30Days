// Given a matrix of size r*c. Traverse the matrix in spiral form. 


class Solution
{   
    public: 
    void ans(vector<vector<int> > &matrix, int i, int j, int r, int c, vector<int>&v)
    {
        if(i>=r || j>=c)
        return;
        for(int k=j; k<c; k++)
        v.push_back(matrix[i][k]);
        for(int k=i+1; k<r; k++)
        v.push_back(matrix[k][c-1]);
        if(i!=(r-1))
        {
            for(int k=c-2; k>=j; k--)
            v.push_back(matrix[r-1][k]);
        }
        if(j!=(c-1))
        {
            for(int k=r-2; k>i; k--)
            v.push_back(matrix[k][j]);
        }
        ans(matrix, i+1, j+1, r-1, c-1, v);
        return;
    }
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>v;
        ans(matrix, 0, 0, r, c, v);
        return v;
    }
};