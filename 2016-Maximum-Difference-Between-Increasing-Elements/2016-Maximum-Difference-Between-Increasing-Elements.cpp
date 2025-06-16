class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int mn, mx;
        mn=1e9,mx =0;
        for(int i = 0; i < n; i++) {
            mn=min(mn,nums[i]);
            mx = max(nums[i] - mn, mx);
        }
        if(mx == 0) return -1;
        else return mx;
    }
};