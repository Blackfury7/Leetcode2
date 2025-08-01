class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int size = 0;
        for (auto it : nums) {
            if (it == maxi)
                ans = max(ans, ++size);
            else
                size = 0;
        }
        return ans;
    }
};