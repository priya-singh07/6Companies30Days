// https://leetcode.com/problems/as-far-from-land-as-possible/


class Solution {
public:
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>>& grid, int i, int j) { 
        if (i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j] == 2 or grid[i][j] == 0)
            return;
        grid[i][j] = 2;
        q.push({i,j});
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int bfs(vector<vector<int>>& grid) {
        int d = 0, maxi = -1;
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while (!q.empty()){
            int n = q.size();
            while(n--){ 
                auto a = q.front();
                q.pop();
                for (int h=0; h<4; h++) {
                    int x = dir[h][0] + a.first;
                    int y = dir[h][1] + a.second;
                    if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y] == 0) 
                    { 
                        maxi = max(maxi, d);
                        q.push({x,y});
                        grid[x][y] = 2;
                    }
                }
            }
            d++;
        }
        return maxi == -1 ? maxi : maxi+1; 
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){ 
                    dfs(grid, i, j); 
                    q.push({i,j});
                }
            }
        }
        return bfs(grid);
    }
};