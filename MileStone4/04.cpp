// Partition Equal Subset Sum

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0,i,j;
        for(i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2!=0)
        return 0;
        else
        {
            bool dp[N+1][sum/2+1];
            for(i=0;i<sum/2+1;i++)
            dp[0][i]=false;
            for(j=0;j<N+1;j++)
            dp[j][0]=true;
            for(i=1;i<N+1;i++)
            for(j=1;j<sum/2+1;j++)
            {
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
            if(dp[N][sum/2] == true)
            return 1;
            else
            return 0;
        }
    }
};