// Count the subarrays having product less than k

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i=0,j=0,c=0;
        long long p=1;
        while(j < n)
        {
            p*=a[j];
            if(p<k)
            c+=(j-i+1);
            else {
                while(p>=k)
                {
                    p/=a[i];
                    i++;
                }
                if(p<k)
                c+=(j-i+1);
            }
            j++;
        }
        return c;
    }
};

// Time Complexity: O(n)
// Auxiliary Space: O(1)