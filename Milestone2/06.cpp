// Maximum of all subarrays of size k

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>v;
        int i=0, j=0;
        deque<int>q;
        while(j < n)
        {
            while(!q.empty() && q.back()<arr[j])
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
                i++;
                j++;
            }
        }
        return v;
    }
};