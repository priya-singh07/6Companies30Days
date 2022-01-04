// Given an array of strings, return all groups of strings that are anagrams.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string, vector<string> >mp;
        int N=string_list.size();
        string str;
        for(int i=0; i<N; i++)
        {
            str=string_list[i];
            sort(string_list[i].begin(), string_list[i].end());
            mp[string_list[i]].push_back(str);
        }
        vector<vector<string> >ans;
        for(auto it=mp.begin(); it!=mp.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};

// Time Complexity: O(N*|S|*log|S|) 
// Auxiliary Space: O(N*|S|)
// (|S| is the length of the string 'str')

