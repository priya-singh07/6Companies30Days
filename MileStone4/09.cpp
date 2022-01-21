// Smallest palindromic number greater than N using the same set of digits as in N.


class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n=N.length();
        if(n<=3)
        return "-1";
        string res;
        int mid = n/2-1;
        string s = N.substr(0, mid+1);
        int k = s.length();
        int ind = k;
        for(int i=k-1;i>0;i--){
            if(s[i] > s[i-1]){
                ind = i-1;
                break;
            }
        }
        if(ind == k){
            return "-1";
        }
        for(int i=k-1; i>0; i--){
            if(s[i] > s[ind]){
                swap(s[i], s[ind]);
                break;
            }
        }
        reverse(s.begin()+ind+1, s.end());
        res += s;
        if(n%2){
            res += N[n/2];
        }
        reverse(s.begin(), s.end());
        res += s;
        return res;
    }
};