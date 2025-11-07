class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        const int n = stations.size();
        auto canPower = [&](long long required, int rem)->bool{
            long long sum = 0;
            for(int i = 0, len = min(n , r); i < len; ++i) sum += stations[i];
            vector<int> added(n , 0);
            for(int i = 0; i < n; ++i){
                if(i + r < n) sum += stations[i + r];
                if(i - r > 0) sum -= stations[i - r - 1] + added[i - r - 1];
                if(sum < required){
                    long long need = required - sum;
                    if(need > rem) return false;
                    added[min(i + r , n - 1)] += need;
                    sum = required;
                    rem -= need;
                }
            }
            return true;
        };
        long long left = 0, right = k, res = 0;
        for(int i = 0; i < n; ++i) right += stations[i];
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(canPower(mid , k)){
                res = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return res;
    }
};