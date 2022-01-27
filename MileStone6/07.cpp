// https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/


class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        int l[N+1], h[N+1];
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<N-1; i++){
            mini = min(mini, arr[i]);
            l[i+1] = mini;
        }
        for(int i=N-1; i>0; i--){
            maxi = max(maxi, arr[i]);
            h[i-1] = maxi;
        }
        for(int i=1; i<N-1; i++){
            if(arr[i] > l[i] && arr[i] < h[i])
                return {l[i], arr[i], h[i]};
        }
        
        return {};
    }
};