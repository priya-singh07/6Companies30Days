// ATOI

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0, sign=1;
        while(str[i]==' ')
        i++;
        if(str[i]=='-')
        {
            sign=-1;
            i++;
        }
        int s=0,c=0;
        for(int k=i; k<str.length(); k++)
        {
            if(str[k]>='0' && str[k]<='9')
            s=s*10+(str[k]-48);
            else
            {
                c++;
                break;
            }
        }
        if(c)
        return -1;
        return s*sign;
    }
};