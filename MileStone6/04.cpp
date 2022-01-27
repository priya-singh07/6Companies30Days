// https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/

class Solution
{
    public:
    int dp[20][20];
    int ans(int i, int j, int a, int b)
    {
        if(i==a-1 && j==b-1)
        return 1;
        if(i>=a || j>=b)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int x=ans(i+1, j, a, b);
        int y=ans(i, j+1, a, b);
        return dp[i][j]=x+y;
        
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        return ans(0,0,a,b);
    }
};