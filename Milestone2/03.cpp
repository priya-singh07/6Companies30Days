// IPL 2021 - Match Day 2

class Solution {
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int>v;
        deque<int>q;
        int i=0, j=0;
        while(j < n)
        {
            while(!q.empty() && q.back() < arr[j])
                 q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1 < k)
            j++;
            else if(j-i+1 == k)
            {
                v.push_back(q.front());
                j++;
            }
            else
            {
                if(arr[i] == q.front())
                q.pop_front();
                v.push_back(q.front());
                j++;
                i++;
            }
        }
        return v;
    }
};