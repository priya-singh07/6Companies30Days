// Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.


class Solution
{
	public:
	
	void dfs1(vector<int> adj[], vector<bool>&vis, int cur, int c, int d){
        vis[cur]=true;
        for(int child:adj[cur]){
            if(vis[child]||(cur==c&&child==d)||(cur==d&&child==c)){
                continue;
            }
            dfs1(adj, vis, child, c, d);
        }
    }
    void dfs(vector<int> adj[], vector<bool>&vis, int cur){
        vis[cur]=true;
        for(int child:adj[cur]){
            if(!vis[child]){
                dfs(adj, vis, child);
            }
        }
    }
    
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool>vis(V, false);
        int count=0;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(adj, vis, i);
                count++;
            }
            vis[i]=false;
        }
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs1(adj, vis, i, c, d);
                count--;
            }
        }
        if(count<0)
        return 1;
        else
        return 0;
    }
};