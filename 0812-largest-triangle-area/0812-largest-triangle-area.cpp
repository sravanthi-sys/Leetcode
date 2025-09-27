class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        for(int a = 0 ; a < points.size() ; a ++){
            for(int b = 0 ; b < points.size() ; b ++){
                for(int c = 0 ; c < points.size() ; c ++){
                    double d1 = sqrt(pow(points[a][0] - 
                    points[b][0], 2) + pow(points[b][1] - points[a][1], 2));
                    double d2 = sqrt(pow(points[b][0] - 
                    points[c][0], 2) + pow(points[b][1] - points[c][1], 2));
                    double d3 = sqrt(pow(points[a][0] - 
                    points[c][0], 2) + pow(points[c][1] - points[a][1], 2));
                    double s = (d1 + d2 + d3) / 2;
                    area = max(area, sqrt(s * (s - d1) * (s - d2) * (s - d3)));
                }
            }
        }
        return area;
    }
};