// Brackets in Matrix Chain Multiplication


class Solution{
public:
    long long dp[501][501];
    int bracket[501][501];
    void printString(int i,int j,string &ans)
    {   
        if(i>j)
        return;
        if(i==j-1 or i==j)
        {
            ans+='A'+j-1;
            return;
        }
        ans+='(';
        printString(i,bracket[i][j],ans);
        printString(bracket[i][j],j,ans);
        ans+=')';
    }
    
    long long recurse(int arr[], int i, int j)
    {
        if(i==j-1 or i==j)
        {
            bracket[i][j]=j;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long mn=1e18;
        int b=0;
        for(int k=i+1;k<j;k++)
        {
            long long val=recurse(arr,i,k)+recurse(arr,k,j)+arr[i]*arr[k]*arr[j];
            if(val<=mn)
            {
                mn=val;
                b=k;
            }
        }   
        bracket[i][j]=b;
        return dp[i][j]=mn;
    }

    string matrixChainOrder(int p[], int n){
        // code here
        memset(dp,-1,sizeof dp);
        long long x=recurse(p,0,n-1);
        string ans="";
        printString(0,n-1,ans);
        return ans;
        
    }
};