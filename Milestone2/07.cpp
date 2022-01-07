// First non-repeating character in a stream

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string s = "";
        unordered_map<char, int> mp;
        queue<int> q;
        for (int i = 0; A[i]; i++)
        {
            mp[A[i]]++;
            if (mp[A[i]] == 1)
                q.push(A[i]);
            while (!q.empty() && mp[q.front()] > 1)
                q.pop();
            if (q.empty())
                s += '#';
            else
                s += q.front();
        }
        return s;
    }
};