// https://leetcode.com/problems/find-in-mountain-array

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start=0, end=mountainArr.length()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1))
                end=mid-1;
            else
                start=mid+1;
        }
        int peak=end;
        start=0;
        while(start<=peak)
        {
            int mid=start+(peak-start)/2;
            if(mountainArr.get(mid)>target)
                peak=mid-1;
            else if(mountainArr.get(mid)<target)
                start=mid+1;
            else
                return mid;
        }
        start=peak+1, end=mountainArr.length()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)<target)
                end=mid-1;
            else if(mountainArr.get(mid)>target)
                start=mid+1;
            else
                return mid;
        }
        return -1;
    }
};