// Phone directory


class Solution{
public:
    vector<string> removeDuplicates(string contact[], int n) {
        set<string> unqStrings(contact, contact + n);
        return vector<string>(unqStrings.begin(), unqStrings.end());
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<string>v = removeDuplicates(contact, n);
        vector<vector<string>>res;
        res.push_back(v);
        
        for(int i = 0; i < s.size(); i++) {
            vector<string> curr;
            for(int j = 0; j < res.back().size(); j++) {
                if(res.back()[j][i] == s[i]) 
                    curr.push_back(res.back()[j]);
            }
            if(curr.empty()) 
                 curr.push_back("0");
            
            if(i == 0) 
            res.pop_back();
            res.push_back(curr);
        }
        return res;
    }
};