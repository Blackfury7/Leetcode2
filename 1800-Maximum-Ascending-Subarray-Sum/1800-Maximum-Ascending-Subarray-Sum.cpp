class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum = nums[0], maxSum = currentSum;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i]; 
            } else {
                currentSum = nums[i]; 
            }
            maxSum = max(maxSum, currentSum); 
        }
        
        return maxSum;
    }
};