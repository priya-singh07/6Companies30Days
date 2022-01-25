// https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/


int convert_num(string s)
{
    int x=0;
    for(int i=0;i<s.size();i++)
      x=x*10+(s[i]-'0');
    return x;
}
int missingNumber(const string& s)
{
    int n=s.size();
    for(int len=1;len<=6;len++)
    {
       string temp="";
       int l=len,i=0;
       while(i<s.size()&&l--)
        temp+=s[i++];
       int prev=convert_num(temp),count=0,j=i,m,flag=0;
       temp="";
       while(j<s.size())
       {
               temp+=s[j++];
               if(prev+1==convert_num(temp))
               {
                   prev=convert_num(temp);
                   temp="";
               }
               else if(prev+2==convert_num(temp))
                    {
                        count++;
                        m=prev+1;
                        prev=convert_num(temp);
                        temp="";
                    }
                    else if(prev<convert_num(temp))
                           flag=1;
        }
        if(count==1&&flag==0)
         return m;
    }
    return -1;
}