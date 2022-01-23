// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    bool canEat(vector<int>&piles, int mid, int h)
    {
        int hrs=0, d;
        for(int i=0; i<piles.size(); i++)
        {
            d=piles[i]/mid;
            hrs+=d;
            if(piles[i]%mid!=0)
                hrs++;
        }
        if(hrs<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low=1, high=piles[piles.size()-1];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canEat(piles, mid, h)==true)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};