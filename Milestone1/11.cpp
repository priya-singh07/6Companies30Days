// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.


class Solution {
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        static int b[2];
        for(int i=0;i<n;i++)
        {
            while(arr[i]!=arr[arr[i]-1])
            swap(arr[i], arr[arr[i]-1]);
        }
        for(int i=0; i<n; i++)
        if(arr[i]!=i+1)
        {
            b[0]=arr[i];
            b[1]=i+1;
        }
        return b;
    }
};