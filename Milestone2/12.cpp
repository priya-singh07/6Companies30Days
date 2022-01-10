// Column name from a given column number


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        while(n>0)
        {
            long long x=n%26;
            n/=26;
            if(x==0)
            {
                ans+='Z';
                n-=1;
            }
            else
            {
                ans+=('A'+x-1);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};