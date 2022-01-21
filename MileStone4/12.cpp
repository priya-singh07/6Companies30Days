// Leaders in Array

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>v;
        v.push_back(a[n-1]);
        int ma=a[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(a[i]>=ma)
            {
                v.push_back(a[i]);
                ma=a[i];
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};