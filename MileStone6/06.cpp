// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/(Similar to Jennifer and Numbers Question)


class Solution {
    public:
    //You need to complete this fucntion
    long long p=1e9+7;
    long long power(int N,int R)
    {
       //Your code here
       if(R==0)
       return 1;
       long long temp = power(N, R/2)%p;
       temp=(temp*temp)%p;
       if(R%2==0)
          return (temp)%p;
       else
          return (N*temp)%p;
    }
};