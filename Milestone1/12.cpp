// Total number of Squares in N*N Chessboard

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        long long d = N*(N+1)*(2*N+1)/6;
        return d;
    }
};

// Time Complexity: O(1)
// Auxiliary Space: O(1)