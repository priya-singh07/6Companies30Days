// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), s = 0, k;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                if (grid[i][j] == 1)
                    v[i] = j;
        }
        for (int i=0; i<n; ++i) {
            k = i + 1;
            while (v[i] > i) {
                if (k >= n)
                    return -1;
                swap(v[i], v[k++]);
                s++;
            }
        }
        return s;
    }
};