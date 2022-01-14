// Prerequisite Tasks (Similar to Question of Modern Park)


class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>v(N);
	    vector<int>indegree(N,0);
	    for(auto x:prerequisites)
	    {
	        v[x.second].push_back(x.first);
	        indegree[x.first]++;
	    }
	    vector<int>t;
	    queue<int>q;
	    for(int i=0; i<N; i++)
	    if(indegree[i]==0)
	    q.push(i);
	    while(!q.empty())
	    {
	        int curr = q.front();
	        q.pop();
	        t.push_back(curr);
	        for(auto c: v[curr])
	        {
	            indegree[c]--;
	            if(indegree[c]==0)
	            q.push(c);
	        }
	    }
	    if(t.size()!=N)
	    return false;
	    return true;
	}
};