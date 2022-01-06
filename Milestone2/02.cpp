// longest mountain

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int c=0,m=0;
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i] < arr[i+1])
                c++;
            else if(arr[i] == arr[i+1])
                c=0;
            else if(c>0)
            {
                while(i<arr.size()-1 && arr[i]>arr[i+1])
                {
                    i++;
                    c++;
                }
                m = max(m, c+1);
                c=0;i--;
            }
        }
        return m;
    }
};