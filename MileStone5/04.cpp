// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1


class Solution
{
    public:
    void ans(string str, string &s, int k, int pos)
    {
        if(k==0 || pos>=str.length())
            return;
            
        char temp = str[pos];
        for(int i = pos+1; i < str.length() ;i++)
        {
            if(temp < str[i])
                temp = str[i];
        }
        if(temp != str[pos])
            k--;
        for(int i=str.length()-1; i>=pos ;i--)
        {
            if(str[i] == temp)
            {
                swap(str[i], str[pos]);
                if(str.compare(s) > 0)
                    s = str;
                    
                ans(str, s, k, pos+1);
                
                swap(str[i], str[pos]);
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string s = str;
       ans(str, s, k, 0);
       return s;
    }
};