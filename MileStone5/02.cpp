// https://practice.geeksforgeeks.org/problems/word-search/1/

class Solution {
public:
    bool present(vector<vector<char>>& board, int i, int j, int m, int n, string word)
    {
        if(word.size()==0)
            return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[0])
            return false;
        
        char c1=board[i][j];
        board[i][j]='.';
        string s=word.substr(1);
        bool a = present(board, i, j+1, m, n, s);
        bool b = present(board, i, j-1, m, n, s);
        bool c = present(board, i+1, j, m, n, s);
        bool d = present(board, i-1, j, m, n, s);
        board[i][j]=c1;
        return a || b || c || d;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                if(board[i][j] == word[0])
                    if(present(board, i, j, m, n, word))
                         return true;
        }
        return false;
    }
};