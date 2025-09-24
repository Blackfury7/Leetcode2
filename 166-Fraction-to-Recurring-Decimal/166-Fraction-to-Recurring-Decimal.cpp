class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(!n) return "0";
        string ans = "";
        if (n > 0 ^ d > 0) ans += '-';
         long n1 = labs(n);  long d1 = labs(d);
        long q = n1 / d1;
        long k = n1%d1;
        ans += to_string(q);
        
        if(k == 0) return ans;
        
        ans += '.';
        unordered_map<long, int> m;
        while(k != 0){
            if(m.find(k)!=m.end()){
                int pos = m[k];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }else{
                m[k] = ans.length();
                k=k*10;
                ans+=to_string(int(k/d1));
                k=k%d1;
            }
        }
        return ans;
    }
};