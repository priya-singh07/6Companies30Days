// https://leetcode.com/problems/number-of-provinces/


class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,vector<bool>&visited,int i){
      visited[i]=true;
      for(int j=0;j<isConnected[i].size();j++){
          if(!visited[j] && isConnected[i][j]==1){
          bfs(isConnected,visited,j);
          }
      }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),false);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
         if(!visited[i]){
               bfs(isConnected,visited,i);
            count++;
         }
        return count;
    }
};