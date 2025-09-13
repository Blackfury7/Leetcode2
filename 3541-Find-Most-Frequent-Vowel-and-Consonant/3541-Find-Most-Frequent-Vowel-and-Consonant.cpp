class Solution {
public:
    int maxFreqSum(string s) {
        int vow =0,cons=0;
        int freq[26];
        for(auto ch:s){
            freq[ch-'a']++;
        }
        for(char i='a';i<='z';i++){
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'){
                vow = max(vow,freq[i-'a']);
            }
            else{
                cons = max(cons,freq[i-'a']);
            }
        }

        return vow+cons;
    }
};