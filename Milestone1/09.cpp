// Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern.

class Solution {
public:
    string printMinNumberForPattern(string S){
        // code here 
        string s="";
        vector<int>v;
        int k=1, c=0;
        if(S[0]=='D')
        {
            v.push_back(2);
            v.push_back(1);
            k=3; c=0;
        }
        else
        {
            v.push_back(1);
            v.push_back(2);
            k=3; c=1;
        }
        for(int i=1; S[i]; i++)
        {
            if(S[i]=='I')
            {
                v.push_back(k++);
                c=i+1;
            }
            else
            {
                v.push_back(v[i]);
                for(int j=c; j<=i; j++)
                v[j]++;
                k++;
            }
        }
        for(int i=0; i<v.size(); i++)
        s+=to_string(v[i]);
        return s;
    }
};