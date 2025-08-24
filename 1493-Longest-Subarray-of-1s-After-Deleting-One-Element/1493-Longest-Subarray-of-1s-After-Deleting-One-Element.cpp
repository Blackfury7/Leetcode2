class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, n = nums.size(), cntZero = 0, maxLen = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) cntZero++;

            while (cntZero > 1) {
                if (nums[i] == 0) cntZero--;
                i++;
            }

            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};