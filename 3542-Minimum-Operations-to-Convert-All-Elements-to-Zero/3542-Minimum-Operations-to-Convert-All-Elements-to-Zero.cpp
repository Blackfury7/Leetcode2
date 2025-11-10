class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stk;
        int ans = 0;
        for (int x : nums) {
            while (!stk.empty() && stk.back() > x) stk.pop_back();
            if (x == 0) continue;
            if (stk.empty() || stk.back() < x) {
                ans++;
                stk.push_back(x);
            }
        }
        return ans;
    }
};