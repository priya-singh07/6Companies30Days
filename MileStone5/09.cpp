// https://leetcode.com/problems/pacific-atlantic-water-flow/


class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& height, vector<vector<bool>> &ocean, int m, int n)
   {
          ocean[i][j]=true;
          if(i>0 && height[i-1][j]>=height[i][j] && ocean[i-1][j]==false)
              dfs(i-1,j,height,ocean,m,n);
          if(j>0 && height[i][j-1]>=height[i][j] && ocean[i][j-1]==false)
              dfs(i,j-1,height,ocean,m,n);
          if(i<n-1 && height[i+1][j]>=height[i][j] && ocean[i+1][j]==false)
              dfs(i+1,j,height,ocean,m,n);
          if(j<m-1 && height[i][j+1]>=height[i][j] && ocean[i][j+1]==false)
              dfs(i,j+1,height,ocean,m,n);
          return;
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n=heights.size(), m=heights[0].size();
         vector<vector<bool>>p(n+1,vector<bool>(m+1,false));
         vector<vector<bool>>at(n+1,vector<bool>(m+1,false));
        for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
             {
                 if(i==0 || j==0)
                 dfs(i,j,heights,p,m,n);  
             }
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
          {
              if(i==n-1 || j==m-1)
                dfs(i,j,heights,at,m,n);  
          }
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(at[i][j] && p[i][j])
                     ans.push_back({i,j});
            }
        }
        return ans;
    }
};