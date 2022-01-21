// String Amendment

class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string str="";
        str+=tolower(s[0]);
        for(int i=1; s[i]; i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            str+=" ";
            str+=tolower(s[i]);
        }
        return str;
    }
};