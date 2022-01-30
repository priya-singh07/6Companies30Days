// https://leetcode.com/problems/divide-two-integers/


class Solution {
public:
    int divide(int dividend, int divisor) {
        int s=1,i;
        long long temp=0,c=0;
    if(dividend<0 || divisor<0)
        s=-1;
    if(dividend<0 && divisor<0)
        s=1;
    long long a=abs(dividend);
    long long b=abs(divisor);
    for(i=31;i>=0;i--)
    {
        if((temp+(b<<i))<=a)
        {
            temp += b << i;
            c |= 1LL << i;
        }
    }
        if(s==-1)
            c=-c;
        if(c>INT_MAX)
            return INT_MAX;
    return c;
    }
};