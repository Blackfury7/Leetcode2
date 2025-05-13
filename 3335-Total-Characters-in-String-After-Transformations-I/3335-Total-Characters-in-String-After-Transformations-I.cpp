class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int md = 1e9+7;
        vector<int>v(26);
        for(char ch:s){
            v[ch-'a']++;
        }
        for(int i=0;i<t;i++){
            int ele =v[25];
            for(int j=25;j>0;j--){
                v[j] = v[j-1];
            }
            v[0] =0;
            v[0]= (v[0]+ele)%md;
            v[1]= (v[1]+ele)%md;
        }
        int sum = 0;
        for(int i=0;i<26;i++){
            sum = (sum + v[i])%md;
        }
        return sum;
    }
};