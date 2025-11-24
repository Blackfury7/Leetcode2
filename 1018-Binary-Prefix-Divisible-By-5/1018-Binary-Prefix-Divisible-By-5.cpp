class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        res.reserve(nums.size());
        int cur = 0;

        for (int bit : nums) {
            cur = ((cur << 1) + bit) % 5;
            res.push_back(cur == 0);
        }

        return res;
    }
};