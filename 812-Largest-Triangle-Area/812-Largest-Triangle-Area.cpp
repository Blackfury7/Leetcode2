class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int n = points.size();
        double res = 0;
        for (int i = 0; i < n-2; ++i) {
            int ax = points[i][0], ay = points[i][1];

            for (int j = i+1; j < n-1; ++j) {
                int bx = points[j][0], by = points[j][1];

                for (int k = j+1; k < n; ++k) {
                    int cx = points[k][0], cy = points[k][1];
                    double area = abs(0.5 * ((bx-ax)*(cy-ay) - (cx-ax)*(by-ay)));
                    if (area > res) res = area;
                }
            }
        }
        return res;
    }
};