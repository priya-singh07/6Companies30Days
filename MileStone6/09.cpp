// https://leetcode.com/problems/guess-number-higher-or-lower-ii


class Solution {
public:
    int ans(int low, int high, vector<vector<int>>&dp) {
        if(low >= high) 
            return 0;
        if(dp[low][high] != -1) 
            return dp[low][high];
        int res=INT_MAX, j;
        for(int i=low; i<=high; i++) 
        {
            j = i;
            j += max(ans(low, i-1, dp), ans(i+1, high, dp));
            res = min(res, j);
        }
        return dp[low][high] = res;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return ans(1, n, dp);
    }
};