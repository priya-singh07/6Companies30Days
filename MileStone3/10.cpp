// Stickler Thief (Similar to Alibaba and Thiefes Question)

class Solution
{
    public:
    
    int ans(int arr[], int curridx, int n, vector<int>&v)
    {
        if(curridx>=n)
        return 0;
        if(v[curridx]!=-1)
        return v[curridx];
        int a = arr[curridx] + ans(arr, curridx+2, n, v);
        int b = ans(arr, curridx+1, n, v);
        return v[curridx] = max(a,b);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>v(10001, -1);
        int l1 = ans(arr, 0, n, v);
        int l2 = ans(arr, 1, n, v);
        return max(l1, l2);
    }
};