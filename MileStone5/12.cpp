// https://leetcode.com/problems/course-schedule-ii/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v (numCourses+1);
        vector<int>indegree(numCourses,0);
        for(auto i: prerequisites){
            v[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        int cnt =0;
        queue<int>q;
        vector<int>ans;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0) 
            {
                q.push(i);
                indegree[i]--;
            }
        }
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int h = q.front();
                q.pop();
                for(auto i: v[h]){
                    indegree[i]--;
                    if(indegree[i]==0) 
                    q.push(i);
                }
                ans.push_back(h);
            }
        }
        vector<int>x;
        return ans.size()==numCourses ? ans : x;
    }
};