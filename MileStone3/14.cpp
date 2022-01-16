// Given a destination D , find the minimum number of steps required to reach that destination.


class Solution{
public:
    int minSteps(int D){
        // code here
        int r =0, c=0;
        while(r < D)
        {
            r+=c;
            c++;
        }
        while((r-D)%2!=0)
        {
            r+=c;
            c++;
        }
        c--;
        return c;
    }
};