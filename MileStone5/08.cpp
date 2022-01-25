// https://leetcode.com/problems/number-of-boomerangs/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<3)
            return 0;
        int ans=0;
        for(int i=0; i<points.size(); i++)
        {
            unordered_map<int, int>mp;
            for(int j=0; j<points.size(); j++)
            {
                if(i==j)
                    continue;
                else
                {
                    int d=((points[i][0]-points[j][0])*(points[i][0]-points[j][0]))+((points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                    mp[d]++;
                }
            }
            for(auto x: mp)
                ans+=(x.second*(x.second-1));
        }
        return ans;
    }
};