// Count ways to N'th Stair(Order does not matter)

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        long long t[m+1];
        t[0]=1, t[1]=1;
        for(int i=2; i<=m; i++)
        t[i] = 1 + t[i-2];
        return t[m];
    }
};