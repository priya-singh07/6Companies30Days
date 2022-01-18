// Find a continuous sub-array which adds to a given number S.

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        int i=0,j=0,sum=0;
        vector<int>v;
        while(j<n)
        {
            sum+=arr[j];
            if(sum<s)
            j++;
            if(sum==s)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            if(sum>s)
            {
                while(sum>s)
                {
                    sum-=arr[i];
                    i++;
                }
                j++;
                if(sum==s)
            {
                v.push_back(i+1);
                v.push_back(j);
                return v;
            }
            }
    }
    v.push_back(-1);
    return v;
    }
};