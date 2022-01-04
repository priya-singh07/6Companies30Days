// GCD Aof two strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.length();
        int l2=str2.length();
        string s="";
        int c=0;
        int d = __gcd(l1,l2);  //gcd inbuilt function
        if(d==l1 && d==l2)
        {
            if(str1==str2)
                return str1;
            else
                return s;
        }
        for(int i=0; i<l1; i++)
            if(str1[i]!=str1[i%d])
                c++;
        for(int i=0; i<l2; i++)
            if(str2[i]!=str2[i%d])
                c++;
        if(c)
            return s;
        else
        {
            int i=0;
            while(d--)
                s+=str1[i++];
        }
        return s;
    }
};