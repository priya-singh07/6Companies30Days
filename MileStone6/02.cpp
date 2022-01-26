// https://leetcode.com/problems/stone-game

class Solution {
public:
    int dp[501][501][2];
    int ans(vector<int>&piles, int start, int end, bool turn)
    {
        if(start>=end)
            return 0;
        if(dp[start][end][turn]!=-1)
            return dp[start][end][turn];
        if(turn == true){
            int a = piles[start] + ans(piles, start+1, end, false);
            int a1 = piles[end] + ans(piles, start, end-1, false);
            dp[start][end][turn] = max(a,a1);
        }
        else
        {
            int a = -piles[start] + ans(piles, start+1, end, true);
            int a1 = -piles[end] + ans(piles, start, end-1, true);
            dp[start][end][turn] = min(a,a1);
        }
        return dp[start][end][turn];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        if(ans(piles, 0, n-1, true)>0)
            return true;
        return false;
    }
};