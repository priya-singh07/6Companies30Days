// Generate all combinations of well-formed(balanced) parentheses.

class Solution
{
    public:
    void ans(int n, vector<string>&v, string s, int open, int close)
    {
        if(open>n || close>n || close>open)
        return;
        if(open==close && open==n)
        {
            v.push_back(s);
            return;
        }
        ans(n, v, s+'(', open+1, close);
        ans(n, v, s+')', open, close+1);
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>v;
        string s="";
        ans(n, v, s, 0, 0);
        return v;
    }
};