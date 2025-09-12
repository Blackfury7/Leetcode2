class Solution {
public:
    bool doesAliceWin(string s) {
        int vow = 0;
        int n = s.length();
        for(char& c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vow++;
            }
        }
        if(vow == 0) return false;
        return true;
    }
};