// Minimise size subarray sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currsum=0,ans=100000,i=0,j=0;
        while(j<nums.size())
        {
            currsum+=nums[j];
            if(currsum < target)
                j++;
            else if(currsum == target)
            {
                ans=min(ans,j-i+1);
                j++;
            }
            else
            {
                while(currsum > target)
                {
                    currsum-=nums[i];
                    i++;
                }
                if(currsum == target)
                    ans=min(ans,j-i+1);
                if(currsum < target)
                {
                    i--;
                    currsum+=nums[i];
                    ans=min(ans,j-i+1);
                }
                j++;
            }
        }
        if(ans==100000)
            return 0;
        return ans;
    }
};