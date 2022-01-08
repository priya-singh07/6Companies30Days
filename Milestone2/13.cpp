// Rotting oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int, int> >q;
        int c=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    c++;
        }
        if(c==0)
            return 0;
        q.push({-1,-1});
        int ans=0;
        while(!q.empty())
        {
            pair<int, int>p=q.front();
            q.pop();
            int i=p.first, j=p.second;
            if(i==-1 && j==-1)
            {
                if(!q.empty())
                {
                    q.push({-1,-1});
                    ans++;
                }
                continue;
            }
            if(j-1>=0 && grid[i][j-1]==1)
            {
                c--;
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if(i+1<row && grid[i+1][j]==1)
            {
                c--;
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            if(i-1>=0 && grid[i-1][j]==1)
            {
                c--;
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(j+1<col && grid[i][j+1]==1)
            {
                c--;
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
        }
        if(c)
            return -1;
        return ans;
    }
};