// Find the length of the Longest Arithmetic Progression (LLAP) in it.


class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2)
        return n;
        int t[n][n], ans=2;
        for(int i=0; i<n; i++)
        t[i][n-1]=2;
        for(int j=n-2; j>=1; j--)
        {
            int i=j-1, k=j+1;
            while(i>=0 && k<n) {
                if(A[i]+A[k]<2*A[j])
                k++;
                else if(A[i]+A[k]>2*A[j])
                {
                    t[i][j]=2;
                    i--;
                }
                else
                {
                    t[i][j]=t[j][k]+1;
                    ans=max(ans, t[i][j]);
                    i--;
                    k++;
                }
            }
            while(i>=0)
            {
                t[i][j]=2;
                i--;
            }
        }
        return ans;
    }
};