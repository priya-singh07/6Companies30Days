// Find the order of characters in the alien language.


class Solution{
    public:
    
    void ans(vector<bool>&vis, int i, vector<int>&v, vector<int>adj[])
    {
        vis[i]=true;
        for(auto it:adj[i])
        if(!vis[it])
        ans(vis, it, v, adj);
        v.push_back(i);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        for(int i=0; i<N-1; i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            for(int j=0; j<min(s1.length(), s2.length()); j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-97].push_back(s2[j]-97);
                    break;
                }
            }
        }
        
        vector<bool>vis(K, false);
        vector<int>v;
        for(int i=0; i<K; i++)
        if(!vis[i])
        ans(vis, i, v, adj);
        reverse(v.begin(), v.end());
        string s="";
        for(int i=0; i<v.size(); i++)
        s+=v[i]+97;
        return s;
    }
};