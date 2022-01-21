// Elections

class Solution {
public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string, int>mp;
        for(int i=0; i<n; i++)
        mp[arr[i]]++;
        vector<string>v;
        int ma=0;
        string s;
        for(auto x:mp)
        if(x.second>ma)
        {
            ma=x.second;
            s=x.first;
        }
        v.push_back(s);
        v.push_back(to_string(ma));
        return v;
    }
};