class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0); // Use long long for prefixSum to avoid overflow

        // Compute prefix sums
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int cnt = 0;

        // Check valid splits
        for (int i = 0; i < n - 1; i++) {
            if (prefixSum[i] >= (prefixSum[n - 1] - prefixSum[i])) {
                cnt++;
            }
        }

        return cnt;
    }
};