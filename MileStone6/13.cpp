// Find the Kth Largest Integer in the Array (Cows and Farm Question)


class Solution {
public:
    class comp {   
    public:
        bool operator()(string &a, string &b) 
        {     
            return a.length() > b.length() || (a.length()==b.length() && a>b);
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comp> pq;  
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }  
        while(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};