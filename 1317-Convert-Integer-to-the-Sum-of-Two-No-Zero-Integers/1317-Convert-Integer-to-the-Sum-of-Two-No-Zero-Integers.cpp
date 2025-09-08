class Solution {
public:
    bool checkzero(int n){
        while(n > 0){
            if(n % 10 == 0){
                return true;
            }
            n = n / 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a = 1, b = n - 1;
        while(checkzero(b) || checkzero(a)){
            a++;
            b--;
        }
        return {a, b};
    }
};