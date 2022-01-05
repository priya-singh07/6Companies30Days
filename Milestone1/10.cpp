// Find max 10 numbers in a list having 10M entries.

class Solution {
  public:
    vector<int> largest(int a[], int n) {
        // code here
        vector<int>v;
        priority_queue<int>pq(a,a+n);
        int k=10;
        while(k--)
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};