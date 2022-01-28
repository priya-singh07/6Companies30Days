// https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/

class Solution{
public:
    int height(int N){
        // code here
        int s,ans;
        s=sqrt(1+8*N);
        ans=-1+s;
        return ans/2;
    }
};