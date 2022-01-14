// Unit Area of largest region of 1's


class Solution
{
    public:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int &c)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
        return;
        c++;
        grid[i][j]=0;
        dfs(grid, i+1, j, m, n, c);
        dfs(grid, i-1, j, m, n, c);
        dfs(grid, i, j+1, m, n, c);
        dfs(grid, i, j-1, m, n, c);
        dfs(grid, i+1, j-1, m, n, c);
        dfs(grid, i+1, j+1, m, n, c);
        dfs(grid, i-1, j+1, m, n, c);
        dfs(grid, i-1, j-1, m, n, c);
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ma=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int c=0;
                if(grid[i][j]==1)
                dfs(grid, i, j, m, n, c);
                ma=max(ma, c);
            }
        }
        return ma;
    }
};