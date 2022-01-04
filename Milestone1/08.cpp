// Total Decoding Messages

class Solution {
public:
	int p=1e9 + 7;
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    int a[n+1];
		    a[0]=1, a[1]=1;
		    if(str[0] == '0')
		    return 0;
		    for(int i=2; i<=n; i++)
		    {
		        a[i]=0;
		        if(str[i-1]>'0')
		        a[i]=a[i-1]%p;
		        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<'7'))
		        a[i]=(a[i]%p)+(a[i-2]%p);
		    }
		    return a[n]%p;
		}
};

// Time Complexity: O(n)
// Space Complexity: O(n) where n  = |str|