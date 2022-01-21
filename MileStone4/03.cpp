// Number of distinct Words with k maximum contiguous vowels(Joe and his Dictionary Problem)


class Solution
{
  public:
    #define ll long long int
    const int p = 1e9 + 7;
    int kvowelwords(int N, int K) {
        // Write Your Code here
        vector<vector<ll>> dp(N+1, vector<ll>(K+1));
        
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= K; j++) {
                if(i == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i-1][K] * 21 % p;
                    if(j > 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] * 5 % p) % p;
                }
            }
        }
        return dp[N][K];
    }
};