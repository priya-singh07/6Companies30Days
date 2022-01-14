// Find all the unique quadruple from the given array that sums up to the given number.

class Solution{
    public:
    // arr[] : int input array of integers
    // K : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>>v;
        if(n<4)
            return v;
        for(int i=0; i<n-3; i++)
        {
            if(i!=0 && arr[i]==arr[i-1])
                continue;
            for(int j=i+1; j<n-2; j++)
            {
                if(j!=i+1 && arr[j]==arr[j-1])
                continue;
                int k1=j+1, l=n-1;
                while(k1<l)
                {
                    int sum = arr[i]+arr[j]+arr[k1]+arr[l];
                    if(sum == K)
                    {
                        vector<int>v1={arr[i],arr[j],arr[k1],arr[l]};
                        v.push_back(v1);
                        int curr_k=k1, curr_l=l;
                        while(k1<n && arr[curr_k]==arr[k1])
                            k1++;
                        while(k1<l && arr[curr_l]==arr[l])
                            l--;
                    }
                    else if(sum > K)
                        l--;
                    else
                        k1++;
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};