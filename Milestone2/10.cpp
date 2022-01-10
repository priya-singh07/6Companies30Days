// Nuts and Bolts Problem

class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    unordered_map<char, int>mp;
	    char s[9]={'!', '#', '$', '%', '&', '*', '@', '^', '~'};
	    for(int i=0; i<n; i++)
	    mp[bolts[i]]=i;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<9; j++)
	        if(mp.find(s[j])!=mp.end())
	        {
	            nuts[i]=s[j];
	            mp.erase(s[j]);
	            break;
	        }
	    }
	    mp.clear();
	    for(int i=0; i<n; i++)
	    mp[nuts[i]]=i;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<9; j++)
	        if(mp.find(s[j])!=mp.end())
	        {
	            bolts[i]=s[j];
	            mp.erase(s[j]);
	            break;
	        }
	    }
	}
};