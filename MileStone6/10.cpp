// https://leetcode.com/problems/generate-random-point-in-a-circle


class Solution {
public:
    double x,y,r;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double rad = (double)rand() / RAND_MAX;
        rad = sqrt(rad) * r;
        double theta = (double)rand() / RAND_MAX;
        theta *= 360.0;
        vector<double>v;
        //since, x = rcosθ, y = rsinθ
        v.push_back(x+rad*cos(theta));
        v.push_back(y+rad*sin(theta));
        return v; 
    }
};