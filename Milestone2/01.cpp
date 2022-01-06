// calculating maximum profit

class Solution {
  public:
  int dp[501][201][2];
  int ans(int A[], int curridx, bool b, int K, int N)
  {
      if(K == 0)
      return 0;
      if(curridx >= N)
      return 0;
      if(dp[curridx][K][b]!=-1)
      return dp[curridx][K][b];
      int buy, idle, sell;
      if(b)
      {
          idle = ans(A, curridx+1, b, K, N);
          buy = -A[curridx] + ans(A, curridx+1, false, K, N);
          return dp[curridx][K][b] = max(idle, buy);
      }
      else
      {
          idle = ans(A, curridx+1, b, K, N);
          sell = A[curridx] + ans(A, curridx+1, true, K-1, N);
          return dp[curridx][K][b] = max(idle, sell);
      }
      
  }
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(dp, -1, sizeof(dp));
        return ans(A, 0, true, K, N);
    }
};