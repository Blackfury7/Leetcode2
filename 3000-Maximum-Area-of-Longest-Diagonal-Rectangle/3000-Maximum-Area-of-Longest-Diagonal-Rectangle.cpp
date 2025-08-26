class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx = 0;
        int mxDia = 0;
        for (auto& d : dimensions){
            int w = d[0], h = d[1];
            int dia = w*w + h*h;
            if (mxDia < dia){
                mxDia = dia;
                mx = 0;
            }
            if (dia == mxDia){
                mx = max(mx, w * h);
            }
        }
        return mx;
    }
};