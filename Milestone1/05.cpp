// Program to find nth ugly number

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull ugly[n];
	    ull i2=0, i3=0, i5=0;
	    ull next2=2, next3=3, next5=5;
	    ugly[0]=1;
	    for(int i=1; i<n; i++)
	    {
	        ugly[i]=min(next2, min(next3, next5));
	        if(ugly[i] == next2)
	        {
	            i2++;
	            next2=ugly[i2]*2;
	        }
	        if(ugly[i] == next3)
	        {
	            i3++;
	            next3=ugly[i3]*3;
	        }
	        if(ugly[i] == next5)
	        {
	            i5++;
	            next5=ugly[i5]*5;
	        }
	    }
	    return ugly[n-1];
	}
};

// Time Complexity: O(n)
// Auxiliary Space: O(n)