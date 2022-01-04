 // Array pair sum divisiblity problem 
 
 
 class Solution { 
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int>mp;
        int c=0;
        for(int i=0; i<nums.size(); i++)
        mp[nums[i]%k]++;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->first==0) {
            if(it->second%2!=0)
            return false;
            }
            else
            {
                if((it->second)!=mp[k-it->first])
                return false;
            }
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity : O(n)