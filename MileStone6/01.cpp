// Path with Maximum Probability


class Solution {
public:
    void dijkstra(vector<pair<int, double>>x[], int totalNodes, int start, vector<double> &v1) {
        priority_queue<pair<double, int>,vector <pair<double, int>>> pq;
        pq.push(make_pair(1, start));
        v1[start] = 1;
        while(!pq.empty()) 
        {
            int u = pq.top().second;
            pq.pop();
            for(int v = 0; v < x[u].size(); v++) 
            {
                int neighbour= x[u][v].first;
                double w = x[u][v].second;
                if(v1[neighbour] < v1[u]*w) 
                {
                    v1[neighbour] = v1[u]*w;
                    pq.push({v1[neighbour],neighbour});
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>>x[n];
        vector<double>v1(n, 0);
        for(int i = 0; i < edges.size(); i++) {
            x[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            x[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        dijkstra(x, n, start, v1);
        return v1[end];
    }
};